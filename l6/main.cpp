#include <iostream>
#include "sujiko.h"
#include "n_queens.h"

int main(int argc, char * argv[])
{
    // SUJIKO
    // Sujiko s(argv[1]);
    // s.solve(0);
    // s.display_board();

    unsigned int n = std::stoi(argv[1]);

    NQueens Q(n);

    Q.solve_rec(0);

    Q.display_board();

    return 0;
}
