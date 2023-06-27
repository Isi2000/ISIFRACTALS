#include <iostream>
#include <vector>
#include <complex>
#include <fstream>

int num_iter(std::complex<double> z0, std::complex<double> c, int max_iter, double thresh = 4)
{
  //calculates the number of iterations for each pixel
    std::complex<double> zn = z0;
    int it = 0;
    while ((std::norm(zn) < thresh) && it < max_iter) {
        zn = zn * zn + c;
        it += 1;
    }
    return it;
}

class BOARD {
    int dim;
    std::vector<double> board;

public:
    BOARD(int dim) : dim(dim), board(dim * dim, 1.0) { }

    void coloring_board() {
      double s_f = 0.25;
      //assigns to each pixel the color corresponding to num_iter
        double z_real_bound = 2.48* s_f / (this->dim - 1);
        double z_im_bound = 2.26 * s_f /(this->dim - 1);

        for (int x = 0; x < this->dim; ++x) {
            for (int y = 0; y < this->dim; ++y) {
	      double real = x * z_real_bound - 3.5*s_f;
                double im = y * z_im_bound - 1.13*s_f;
                int number_iterations = num_iter(0, std::complex<double>(real, im), 500);
                this->board[y * this->dim + x] = 1 - number_iterations / 500;
            }
        }
    }

  void save_to_file() {
        std::ofstream outfile("output.txt");

        for (int i = 0; i < this->dim; i++) {
            for (int j = 0; j < this->dim; j++) {
                outfile << this->board[i * this->dim + j] << " ";
            }
            outfile << "\n";
        }

        outfile.close();
    }
};
