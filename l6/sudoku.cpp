#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    // Generate a board from the given file

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

bool Sudoku::solve(unsigned int cell) {
    //get current row and col from cell
    int row = cell/9;
    int col = cell%9;

    // 1) If we have filled the entire board,  return true
    if(cell == 81)
    {
    return true;
    }

    //check if the current cell is filled
    if(board[row][col] != 0)
    {
        //recursive call to move to next cell if this one is filled
        return solve(cell+1);
    }

    // 2) For each digit 1-9:
    for(int i = 1; i <= 9; i++)
    {
        // If this digit can be placed in this cell
        if(is_valid(row, col, i))
        {
            // Place the digit
            board[row][col] = i;
            // debug
            // display_board();
            std::cout << std::endl;
            // Recurse to the next empty cell.
            if(solve(cell+1))
            {
                // If that recursive call returns true
                // Return true
                return true;
            }
            //     - else
            //         - Try the next digit
        }
        // 3) If none of the digits yielded a valid solution, backtrack.
        board[row][col] = 0;
    }

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
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == num)
        {
            return true;
        }
    }
    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){

    for(unsigned int row = 0; row < 3; row++)
    {
        for(unsigned int col = 0; col < 3; col++)
        {
            if(board[boxStartRow+row][boxStartCol+col] == num)
            {
                return true;
            }
        }
    }

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