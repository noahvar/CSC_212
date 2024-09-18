#ifndef MAZE_H
#define MAZE_H
/*
 * Check if these header files are needed later
 * by Ctrl+X or deletion.
 * (Don't know if header files need to be included in maze.h)
 */
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <utility>

class Maze
{
private:
    int n; //rows
    int m; //columns
    int seed; // seed for random number generator
    std::vector<std::pair<int, int>> neighbors; //dynamic array of neighbors coords
    int** mazeArray;
    bool** visited; // n*m 2D array of visited and unvisited cells

    void allocateMaze();
    void deallocateMaze();

public:

    Maze(int rows, int cols); //constructor
    ~Maze(); //destructor
    void printMaze(std::string filename); //print
    void generateMaze(int seed);//randomly deletes walls of the mazeArray
};

#endif