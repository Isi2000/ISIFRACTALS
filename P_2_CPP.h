#include <iostream>
#include <vector>
#include <complex>
#include <fstream>
#include <cmath>
#include <string>

int num_iter(std::complex<double> z0, std::complex<double>&& c, int max_iter, double thresh = 4)
{
    //calculates the number of iterations for each pixel
  
  std::complex<double> zn = std::move(z0);//std move creates a temporary obj
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

    void coloring_board(double scaling_factor) {
        std::complex<double> s(-0.3, 0.05);
        //assigns to each pixel the color corresponding to num_iter
        const double z_real_bound = 2.48 * scaling_factor / (this->dim - 1);
        const double z_im_bound = 2.26 * scaling_factor / (this->dim - 1);

        for (int x = 0; x < this->dim; ++x) {
            for (int y = 0; y < this->dim; ++y) {
                double real = x * z_real_bound - 0.42884 * scaling_factor;
                double im = y * z_im_bound + 0.231345 * scaling_factor;
                int number_iterations = num_iter(0, std::complex<double>(real, im), 50);
                this->board[y * this->dim + x] = 1 - number_iterations / 50;
            }
        }
    }

    void save_to_file(double scaling_factor) {
        std::string filename = "output_scaling_" + std::to_string(scaling_factor) + ".txt";
        std::ofstream outfile(filename);

        for (int i = 0; i < this->dim; i++) {
            for (int j = 0; j < this->dim; j++) {
                outfile << this->board[i * this->dim + j] << " ";
            }
            outfile << "\n";
        }

        outfile.close();
    }
};

