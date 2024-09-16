#include "maze.h"
#include <iostream>
#include <random>
#include <fstream>

//constructor
Maze::Maze(int rows, int cols) : n(rows), m(cols) {
    allocateMaze();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mazeArray[i][j] = 15;
        }
    }
    mazeArray[0][0] = 7;
    mazeArray[n-1][m-1] = 11;
}

//destructor
Maze::~Maze() {
    deallocateMaze();
}


//maze allocation
void Maze::allocateMaze() {
    mazeArray = new int*[n];
    for(int i = 0; i < n; i++) {
        mazeArray[i] = new int[m];
    }
}

//maze deallocation
void Maze::deallocateMaze() {
    for(int i = 0; i < n; i++) {
        delete[] mazeArray[i];
    }
    delete[] mazeArray;
}

//print
void Maze::printMaze(std::string filename) {

    //open outpute file
    std::ofstream outFile(filename);

    //check if it opened
    if(!outFile) {
        std::cerr << "Error opening file " << filename << std::endl;
    }

    //print to terminal and to output file
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << mazeArray[i][j] << " ";
            outFile << mazeArray[i][j];//write value
            if(j<m-1) {
                outFile << " "; //add spaces in between cols
            }
        }
        std::cout << "\n";//new line in terminal
        outFile << "\n";//new line in output file
    }
    outFile.close();//close file when done
}

