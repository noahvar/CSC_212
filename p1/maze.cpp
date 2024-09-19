#include "maze.h"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <utility>

//constructor
Maze::Maze(int seed, int rows, int cols) : seed(seed), n(rows), m(cols), mazeArray(nullptr), visited(nullptr)
{
    //initializes expPath, current cell, exit cell, and seed
    expPath.push_back({0,0});
    current = expPath[0];
    exit = {n-1,m-1};
    std::srand(seed);

    //creates maze default maze
    allocateMaze();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mazeArray[i][j] = 15;
        }
    }

    mazeArray[n - 1][m - 1] = 11;
    mazeArray[0][0] = 7;

    //creates default visited 2D array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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

    visited = new bool*[n];
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
    //check for edge case (1x1 grid)
    if(n == 1 && m == 1)
    {
        mazeArray[current.first][current.second] -= 4;
        return;
    }

    while(!isMazeFullyVisited())
    {
        /*
         *expPath[0] = {0, 0}
         *current = expPath[0]
         */

        visited[current.first][current.second] = true;//mark current as visited

        addNeighbors();//get current's neighbors and put into neighbor array

        //if neighbors are empty then you have reached a dead end
        if(neighbors.empty()) {
            expPath.pop_back();
            current = expPath.back();
            continue;
        }

        //moving squares
        if(!neighbors.empty())
        {
            //selecting random cell to move to
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());

            previous = current; //before moving cells remember this cell as previous

            current = neighbors[idx]; //moving to new square
        }

        //push the current cell into expPath
        expPath.push_back(current);

        //delete wall between current and neighbors[idx]
        removeWall();

        //repeat
    }
}

void Maze::addNeighbors()
{
    //add all neighbors to array
    neighbors = {
        {current.first+1,current.second},
        {current.first,current.second+1},
        {current.first-1,current.second},
        {current.first,current.second-1}
    };

    //remove neighbors that are out of range or that are visited
    for(int i = 0; i < neighbors.size();)
    {
        if(neighbors[i].first < 0 || neighbors[i].second < 0 || neighbors[i].first == n || neighbors[i].second == m || visited[neighbors[i].first][neighbors[i].second] == true)
        {
            neighbors.erase(neighbors.begin() + i);
        }
        else
        {
            i++;
        }
    }
}
void Maze::removeWall()
{
    //delete wall between current and neighbors[idx]
    /*
     *current coords are coords to where you have moved
     *(find way to delete the wall between this and previous)
     */

    //check if moved NORTH
    if(current.first == (previous.first-1))
    {
        mazeArray[current.first][current.second] -= 4;
        mazeArray[previous.first][previous.second] -= 8;
    }
    //check if moved SOUTH
    else if(current.first == (previous.first+1))
    {
        mazeArray[current.first][current.second] -= 8;
        mazeArray[previous.first][previous.second] -= 4;
    }
    //check if moved EAST
    else if(current.second == (previous.second+1))
    {
        mazeArray[current.first][current.second] -= 1;
        mazeArray[previous.first][previous.second] -= 2;
    }
    //check if moved WEST
    else if(current.second == (previous.second-1))
    {
        mazeArray[current.first][current.second] -= 2;
        mazeArray[previous.first][previous.second] -= 1;
    }

}
bool Maze::isMazeFullyVisited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                return false;
            }
        }
    }
    return true;
}




