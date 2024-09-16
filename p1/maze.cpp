#include "maze.h"
#include <iostream>
#include <random>

//constructor
Maze::Maze(int rows, int cols) : n(rows), m(cols) {
    allocateMaze();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mazeArray[i][j] = 15;
        }
    }
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
void Maze::printMaze() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << mazeArray[i][j] << " ";
        }
        std::cout << "\n";
    }
}

