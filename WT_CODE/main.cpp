#include<iostream>
#include"fractals.h"

void saver(bool m, double scale_f, double max_s,  double step, int dim)
{
    for (double scale_f ; scale_f < max_s; scale_f += step) {
      BOARD board(dim);
      board.coloring_board(scale_f, m);
      board.save_to_file(scale_f);
    }
}

int main() {
  saver(true,0.8,1.05, 0.05, 100);
}
