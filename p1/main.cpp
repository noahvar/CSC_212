#include "maze.h"
#include <iostream>
#include <random>

int main(int argc, char *argv[])
{

    Maze maze(std::stoi(argv[1]),std::stoi(argv[2]), std::stoi(argv[3]));
    maze.generateMaze(maze);
    maze.printMaze(argv[4]);

    return 0;
}