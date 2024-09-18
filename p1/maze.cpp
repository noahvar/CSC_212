#include "maze.h"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <utility>

//constructor
Maze::Maze(int seed, int rows, int cols) : seed(seed), n(rows), m(cols), mazeArray(nullptr), visited(nullptr)
{
    //creates maze default maze
    allocateMaze();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mazeArray[i][j] = 15;
        }
    }
    mazeArray[0][0] = 7;
    mazeArray[n - 1][m - 1] = 11;

    //creates default visited 2D array
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
}

//destructor
Maze::~Maze()
{
    deallocateMaze();
}

//maze and visited allocation
void Maze::allocateMaze()
{
    mazeArray = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mazeArray[i] = new int[m];
    }

    visited = new bool*[false];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
    }
}

//maze and visited deallocation
void Maze::deallocateMaze()
{
    for(int i = 0; i < n; i++)
    {
        delete[] mazeArray[i];
    }
    delete[] mazeArray;

    for(int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
}

//print
void Maze::printMaze(std::string filename)
{

    //open outpute file
    std::ofstream outFile(filename);

    //check if it opened
    if(!outFile)
    {
        std::cerr << "Error opening file " << filename << std::endl;
    }

    //print to terminal and to output file
    for(int i = 0; i < n; i++)
        {
        for(int j = 0; j < m; j++)
            {
            std::cout << mazeArray[i][j] << " ";
            outFile << mazeArray[i][j];//write value to output file
            if(j<m-1)
            {
                outFile << " "; //add spaces in between cols
            }
        }
        std::cout << "\n";//new line in terminal
        outFile << "\n";//new line in output file
    }
    outFile.close();//close file when done
}

void Maze::generateMaze(Maze& maze)
{
    while(maze.current != exit)
    {
        //pop current into expPath
        //mark current as visited
        //get current's neighbors and put into neighbor array
        //randomly select neighbor
        //delete wall between current and selected
        //make selected cell the current
        //repeat
    }
}

void checkNeighbours()
{
    //to make sure we don't move current out of valid array
}


