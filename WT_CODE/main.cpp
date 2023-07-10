#include<iostream>
#include"fractals.h"

void generate_scaled_outputs(int dim, double start_scaling_factor, double end_scaling_factor, double scaling_factor_step) {
    for (double scaling_factor = start_scaling_factor; scaling_factor >= end_scaling_factor; scaling_factor -= scaling_factor_step) {
        BOARD board(dim);
        board.coloring_board(scaling_factor);
        board.save_to_file_m(scaling_factor);
    }
}


void generate_julia_set(int dim, double scaling_factor, int num_points, double step) {
    for (int i = 0; i < num_points; ++i) {
        double real_c = -2.0 + i * step;
        double imag_c = -1.0 + i * step;
        std::complex<double> c(real_c, imag_c);

        BOARD board(dim);
        board.coloring_board(scaling_factor, c, false);
        board.save_to_file_j(c);
    }
}

int main() {
    int dim = 800;
    double scaling_factor = 1.0;
    int num_points = 10;
    double step = 0.1;

    generate_julia_set(dim, scaling_factor, num_points, step);

    return 0;
}
