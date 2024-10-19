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
    // If we placed a number successfully on every cell, we did it!
    //0.) Is the win condition met? If so, return true. Otherwise, continue on.
    if(cell == 9)
    {
        return isValid();
    }

    //1.) At any given step, record all of the missing values.
    std::vector<unsigned int> missing = {1,2,3,4,5,6,7,8,9};
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            if(board[r][c] != 0)
            {
                missing.erase(std::remove(missing.begin(), missing.end(), board[r][c]));
            }
        }
    }

    //1.2) Place the first missing value into the first open spot on the board.

    //get row and col from cell
    unsigned int row = cell/3;
    unsigned int col = cell%3;

    //check if the current cell is filled
    if(board[row][col] != 0)
    {
        //recursive call to move to next cell if this one is filled
        return solve(cell+1);
    }

    for(unsigned int element : missing)
    {
        board[row][col] = element;
        //debug to show the board
        display_board();
        std::cout << std::endl;
        //1.3) Recursively call this function with the new board. If we obtain True, also return True.
        if(solve(cell+1))
        {
            return true;
        };
        //Otherwise, replace the number with the next missing value.
        board[row][col] = 0;
    }

    //2.) If we tried all of the missing values & none worked, return False so the previous version of this board can try another number.
    return false;
}

bool Sujiko::isValid()
{
    //check if no duplicate numbers
    //check if numbers add up to the intersection numbers
    unsigned int topLeftCheck = board[0][0]+board[0][1]+board[1][0]+board[1][1];
    unsigned int topRightCheck = board[0][1]+board[0][2]+board[1][1]+board[1][2];
    unsigned int botLeftCheck = board[1][0]+board[1][1]+board[2][0]+board[2][1];
    unsigned int botRightCheck = board[1][1]+board[1][2]+board[2][1]+board[2][2];
    if(topLeft == topLeftCheck && topRight == topRightCheck && botLeft == botLeftCheck && botRight == botRightCheck)
    {
        return true;
    }

    return false;


    /*
     * (0,0), (0,1), (0,2)
     * (1,0), (1,1), (1,2)
     * (2,0), (2,1), (2,2)
     */
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