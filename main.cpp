#include<iostream>
#include"P_2_CPP.h"



int main() {
    int dim = 300;

    for (double scaling_factor = 0.01; scaling_factor <= 1; scaling_factor += 0.05) {
        BOARD board(dim);
        board.coloring_board(scaling_factor);
        board.save_to_file(scaling_factor);
    }

    return 0;
}
