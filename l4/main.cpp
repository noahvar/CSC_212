#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){

    // Check if a file name was passed via command line argument (CLA)
    // Exit if no file is provided
    if (argc < 2) {
        std::cerr << "Error: No file name provided." << std::endl; // Print error message to standard error
        return 1; // Exit with a non-zero status to indicate an error
    }
    // Open the file given by the first command line argument
    std::ifstream file;
    file.open(argv[1]);

    //check if there is error opening file
    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
    }

    // Read the first line to determine which constructor to use

    //initialize a linked list
    LinkedList list;

    std::string first_line;
    std::getline(file, first_line);
    if(first_line.empty())
    {
        list = LinkedList();
        std::cout << "using default constructor." << std::endl;
    }
    else
    {
        std::istringstream ss(first_line);
        std::string token;
        if(std::getline(ss, token, ' ')) //reads first token
        {
            //check if first token is a single integer
            if(ss.eof())
            {
                int value = std::stoi(token); //convert token to int
                list = LinkedList(value);
                std::cout << "using int constructor." << std::endl;
            }
            else
            {
                //otherwise, it's a vector of numbers
                std::vector<int> values;
                values.push_back(std::stoi(token));
                while(std::getline(ss, token, ' '))
                {
                    values.push_back(std::stoi(token));
                }
                list = LinkedList (values);
                std::cout << "using vector constructor." << std::endl;
            }
        }
    }

    std::cout << list.to_string() << std::endl;
    // Process each subsequent line in the file (commands to modify the list)
    std::string line;
    while(std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        int data, index;

        //read first token
        if(ss >> data)
        {
            //check if we must use removal
            if (data < 0)
            {
                list.remove(-data);
                std::cout << list.to_string() << std::endl;
            }
        }
        else
        {
            //check if we have a second number and must insert
            if(ss >> index)
            {
                list.insert(data, index);
                std::cout << list.to_string() << std::endl;
            }
            else
            {
                list.push_front(data);
                std::cout << list.to_string() << std::endl;
            }
        }

        //check for '?'
        if(line.back() == '?')
        {
            data = std::stoi(line.substr(0, line.size() - 1)); //removes the '?' and converts to int
            list.contains(data);
        }

    }

    file.close();
    return 0;

}