#include <iostream>
#include "sujiko.h"

int main(int argc, char * argv[])
{
    Sujiko s(argv[1]);

    s.solve(0);

    s.display_board();

    return 0;
}
