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
#include <algorithm>

class Maze
{
private:
    int n; //rows
    int m; //columns
    int seed; // seed for random number generator
    std::pair<int, int> previous; //cell visited before current cell
    std::pair<int, int> exit; // exit cell
    std::pair<int, int> current; //pair of ints to represent current cell
    std::vector<std::pair<int, int>> neighbors; //holds ALL neighbors
    std::vector<std::pair<int, int>> expPath; //dynamic array to pop and push exploration path
    int** mazeArray;
    bool** visited; // n*m 2D array of visited and unvisited cells

    bool isMazeFullyVisited();
    void addNeighbors();
    void removeWall();
    void allocateMaze();
    void deallocateMaze();

public:

    Maze(int seed, int rows, int cols); //constructor
    ~Maze(); //destructor
    void printMaze(std::string filename); //print
    void generateMaze(Maze& maze);//randomly deletes walls of the mazeArray
};

#endif