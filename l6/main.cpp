#include <iostream>
#include "sujiko.h"
#include "n_queens.h"
#include "sudoku.h"

int main(int argc, char * argv[])
{
    // SUJIKO

    // Sujiko s(argv[1]);
    // s.solve(0);
    // s.display_board();

    // N_QUEENS

    // unsigned int n = std::stoi(argv[1]);
    // NQueens Q(n);
    // Q.solve_rec(0);
    // Q.display_board();

    //SUDUKO

    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}
