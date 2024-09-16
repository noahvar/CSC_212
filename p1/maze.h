#ifndef MAZE_H
#define MAZE_H

#include <iostream>

class Maze {
private:
    int n; //rows
    int m; //columns
    int** mazeArray;
    bool** visited;

    void allocateMaze();
    void deallocateMaze();

public:

    Maze(int rows, int cols); //constructor
    ~Maze(); //destructor
    void printMaze(); //print
};

#endif