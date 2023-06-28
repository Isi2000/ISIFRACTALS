#include<iostream>
#include"P_2_CPP.h"



int main() {
    int dim = 500;

    for (double scaling_factor = 2.0; scaling_factor >= 0.2; scaling_factor -= 0.2) {
        BOARD board(dim);
        board.coloring_board(scaling_factor);
        board.save_to_file(scaling_factor);
    }

    return 0;
}
