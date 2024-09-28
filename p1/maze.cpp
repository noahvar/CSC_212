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

    //open output file
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
            unsigned long long idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());

            previous = current; //before moving cells remember this cell as previous

            current = neighbors[idx]; //moving to new square
        }

        //push the current cell into expPath
        expPath.push_back(current);

        //delete wall between current and neighbors[idx]
        removeWall();

        //temporary output to check maze after each wall removal

        // std::cout << "Moving from (" << previous.first << "," << previous.second << ") to (" << current.first << "," << current.second << ")\n";
        //
        // std::cout << "Maze state after wall removal:" << std::endl;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         std::cout << mazeArray[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;

        //repeat
    }
}

void Maze::addNeighbors()
{
    //add all neighbors to array
    //newer version
     neighbors = {
         {current.first-1,current.second}, //North Neighbor
         {current.first+1,current.second}, //South Neighbor
         {current.first,current.second+1}, //East Neighbor
         {current.first,current.second-1} //West Neighbor
     };

    //remove neighbors that are out of range or that are visited
    for(int i = 0; i < neighbors.size();)
    {
        //checks if a neighbor has n or m values less than 0, or greater than n or m which would be out bounds.
        //also checks if neighbors cell has been marked as visited.
        if(neighbors[i].first < 0 || neighbors[i].second < 0 || neighbors[i].first == n || neighbors[i].second == m || visited[neighbors[i].first][neighbors[i].second] == true)
        {
            neighbors.erase(neighbors.begin() + i);
        }
        else
        {
            i++; //Move to next element if no element was erased
        }
    }

    // temporary for loop to see output of neighbors after each move.
     // std::cout << "Current position: (" << current.first << ", " << current.second << ")\n";
     // for(int i = 0; i < neighbors.size(); i++)
     // {
     //     std::cout << "N" << i << ": (" << neighbors[i].first << "," << neighbors[i].second << ")" << std::endl;
     // }
}

//add enumeration for readability in removeWall();
enum Direction {
    NORTH = 4,
    SOUTH = 8,
    EAST = 1,
    WEST = 2

};

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
        //debug
        // std::cout << "NORTH wall being removed." << std::endl;
        mazeArray[current.first][current.second] -= NORTH;
        mazeArray[previous.first][previous.second] -= SOUTH;
    }
    //check if moved SOUTH
    else if(current.first == (previous.first+1))
    {
        //debug
        // std::cout << "SOUTH wall being removed." << std::endl;
        mazeArray[current.first][current.second] -= SOUTH;
        mazeArray[previous.first][previous.second] -= NORTH;
    }
    //check if moved EAST
    else if(current.second == (previous.second+1))
    {
        //debug
        // std::cout << "EAST wall being removed." << std::endl;
        mazeArray[current.first][current.second] -= EAST;
        mazeArray[previous.first][previous.second] -= WEST;
    }
    //check if moved WEST
    else if(current.second == (previous.second-1))
    {
        //debug
        // std::cout << "WEST wall being removed." << std::endl;
        mazeArray[current.first][current.second] -= WEST;
        mazeArray[previous.first][previous.second] -= EAST;
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




