import numpy as np
import matplotlib.pyplot as plt

rec_formula = lambda z0, c : z0**2+c

def n_iter(z0: complex, c: complex, max_iter: int, thresh = 4):
    """
    Returns the number of iterations before z diverges (given a treshold)
    """
    zn = z0
    it = 0
    while ((abs(zn)**2 < thresh) and it < max_iter):
        zn = rec_formula(zn, c)
        it += 1
    return it


class fractal_board:
    """
    board to generate and plot the Mandelbrot set
    """
    def __init__(self, dim):
        self.dim = dim
        self.board = np.full((self.dim, self.dim), 1., dtype = float)

    """
    keep in mind that The left-most extent of the set ends with the spike 
    at x = -2, and the right side extends out to approximately x = 0.47. 
    The top and bottom are at approximately y = ± 1.12
    """
    def coloring_board(self):
        """
        function that colors each pixel the board basing on number of iters
        """
        z_real_bound = 2.48/(self.dim-1)
        z_im_bound = 2.26/(self.dim-1)
        #lamda func that maps the coordinates into the rescaled ones
        f = lambda z_real, z_im:(z_real*z_real_bound - 2, z_im*z_im_bound - 1.13)
        for x in range(self.dim):
            for y in range(self.dim):
                number_iterations = n_iter(0, complex(*f(x,y)), 500)
                self.board[y][x] = (1-number_iterations/500)

    def plotter(self):
        zoomed_board = self.board[self.dim//8*5 : self.dim//8*6 , self.dim//8*4 : self.dim//8*5] 
        plt.imshow(self.board, cmap = "rainbow")
        plt.axis('off')
        plt.show()


a =  fractal_board(500)
a.coloring_board()
a.plotter()

