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

print(rec_formula(1+2j, 2+2j))
