#include "sujiko.h"


Sujiko::Sujiko() {

}

Sujiko::Sujiko(std::string fname) {
    // Get file name
    std::ifstream file(fname);
    // Create string to write file lines to
    std::string line;
    // variables to write to
    unsigned int value;

    //get first line of file
    std::getline(file, line);
    std::istringstream inputs(line);

    //tokenize each number in the first line
    inputs >> topLeft >> topRight >> botLeft >> botRight;

    // Read the rest of the file & create board
    int row = 0;
    while(std::getline(file, line) && row < 3)
    {
        std::istringstream inputs(line);
        for(int col = 0; col < 3; col++)
        {
            if(inputs >> value)
            {
                board[row][col] = value;
            }
        }
        row++;
    }

}

Sujiko::~Sujiko() {

}

bool Sujiko::solve(unsigned int cell){
    // If we placed a number succesfully on every cell, we did it!

//     0.) Is the win condition met? If so, return true. Otherwise, continue on.
//     1.) At any given step, record all of the missing values.
//          1.2) Place the first missing value into the first open spot on the board.
//          1.3) Recursively call this function with the new board. If we obtain True, also return True.
//     Otherwise, replace the number with the next missing value.
//     2.) If we tried all of the missing values & none worked, return False so the previous version of this board can try another number.

    return false;
}

void Sujiko::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << this->board[i][j] << " ";
        }
        std::cout << std::endl;

    }
    //added to see intersections
    // std::cout << "topLeft: " << topLeft << std::endl;
    // std::cout << "topRight: " << topRight << std::endl;
    // std::cout << "botLeft: " << botLeft << std::endl;
    // std::cout << "botRight: " << botRight << std::endl;
}