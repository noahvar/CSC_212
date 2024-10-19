#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

class Sujiko{
private:
    const unsigned int EMPTY = 0;
    const unsigned int BOARD_SIZE = 3;
    std::vector<std::vector<unsigned int>> board = std::vector<std::vector<unsigned int>>(3, std::vector<unsigned int>(3, 0));
    std::vector<std::vector<unsigned int>> nums = std::vector<std::vector<unsigned int>>(2, std::vector<unsigned int>(2, 0));
    unsigned int topLeft;
    unsigned int topRight;
    unsigned int botLeft;
    unsigned int botRight;

public:
    Sujiko();
    explicit Sujiko(std::string fname);
    ~Sujiko();

    bool solve(unsigned int cell);
    bool isValid();
    void display_board();
};