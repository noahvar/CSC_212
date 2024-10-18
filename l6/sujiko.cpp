#include "sujiko.h"


Sujiko::Sujiko() {

}

Sujiko::Sujiko(std::string fname) {
    // Read 4 sum values from file
    std::ifstream file(fname);

    std::string line;
    unsigned int topLeft, topRight, botLeft, botRight;

    //get first line of file
    std::getline(fname, line);

    //tokenize each number in the first line
    std::istringstream inputs(line)
    inputs << topLeft << topRight << botLeft << botRight;

    // Read file & create board
    while(std::getline(fname, line)){
        
    }
}

Sujiko::~Sujiko() {

}

bool Sujiko::solve(unsigned int cell){
    // If we placed a number succesfully on every cell, we did it!

    return false;
}

void Sujiko::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << this->board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}