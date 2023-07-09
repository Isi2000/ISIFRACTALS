#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int num_iter(std::complex<double> z0, std::complex<double> c, int max_iter,
             double thresh = 4) {
  /*
function that given a point on the complex plane a given constant c calculates
the orbit given by the recursive formula z = z**2 + c of that point
   */
  std::complex<double> zn = std::move(z0);
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
  // Distinction between mand and jul is implemented with "Overload"

public:
  BOARD(int dim) : dim(dim), board(dim * dim, 1.0) {}

  void coloring_board(double scaling_factor, bool mode = true) {
    /*
      takes each pixel and colors it accordin to the algorithm for generating
      algorithm of the mandelbrot of julia set true --> mandelbrot set false -->
      julia sets
     */
    const int n_it = 300;
    if (mode == true) {
      // choose where to scale basing on math, as of right now it scales in
      // -2.-113, which is the "center" of the mandelbrot set
      const double z_real_bound = 2.48 * scaling_factor / (this->dim - 1);
      const double z_im_bound = 2.26 * scaling_factor / (this->dim - 1);

      for (int x = 0; x < this->dim; ++x) {
        for (int y = 0; y < this->dim; ++y) {
          double real = x * z_real_bound - 2 * scaling_factor;
          double im = y * z_im_bound - 1.13 * scaling_factor;
          int number_iterations =
              num_iter(0, std::complex<double>(real, im), n_it);
          this->board[y * this->dim + x] =
              1.0 - number_iterations / static_cast<double>(n_it);
        }
      }
    }

    if (mode == false) {
      const std::complex c(0.3, 0.4);
      const double z_real_bound = 4 * scaling_factor / (this->dim - 1);
      const double z_im_bound = 4 * scaling_factor / (this->dim - 1);

      for (int x = 0; x < this->dim; ++x) {
        for (int y = 0; y < this->dim; ++y) {
          double real = x * z_real_bound - 2 * scaling_factor;
          double im = y * z_im_bound - 2 * scaling_factor;
          int number_iterations =
              num_iter(std::complex<double>(real, im), c, n_it);
          this->board[y * this->dim + x] =
              1.0 - number_iterations / static_cast<double>(n_it);
        }
      }
    }
  }

  void save_to_file(double scaling_factor) {
    // saves to a given path
    std::string path = "/home/isacco/ISIFRACTALS/WT_CODE/PLOT/";
    std::string filename =
        path + "output_scaling_" + std::to_string(scaling_factor) + ".ppm";
    std::ofstream outfile(filename);
    // format for ppm file
    outfile << "P3\n";
    outfile << dim << " " << dim << "\n";
    outfile << "255\n";

    for (int i = 0; i < this->dim; i++) {
      for (int j = 0; j < this->dim; j++) {
        int pixel_value =
            static_cast<int>(this->board[i * this->dim + j] * 255);
        outfile << pixel_value << " " << pixel_value << " " << pixel_value
                << " ";
      }
      outfile << "\n";
    }

    outfile.close();
  }
};
