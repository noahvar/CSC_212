#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    // Generate a board from the give file

    //get the file name
    std::ifstream file(f_name);
    std::string line;

    int row = 0;
    int value;
    while(std::getline(file, line) && row < 9)
    {
        std::stringstream inputs(line);
        for(int col = 0; col < 9; col++)
        {
            if(inputs >> value)
            {
                board[row][col] = value;
            }
        }
        row++;
    }
}

bool Sudoku::solve() {



    return false;
}

// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return (this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){

    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){

    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){

    return false;
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}