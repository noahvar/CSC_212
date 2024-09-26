#include "DynamicArray.h"
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <sstream>

int main(int argc, char *argv[])
{
    // Extract the name of the file we'll be reading from the CLA
    std::string file_name = argv[1];

    //read the file and check if file was opened
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_name << std::endl;
        return 1;
    }

    // Create a vector to temporarily hold values
    std::vector<int> inputs;
    //create a string to hold the line im reading
    std::string line;

    // Read the current line from the file and put into inputs vector
    while(std::getline(file, line))
    {
        int val;
        std::istringstream ss(line);
        while (ss >> val)
        {
            inputs.push_back(val);
        }
    }

    DynamicArray arr;

    for(std::size_t i = 0; i < inputs.size()/2; i++)
    {
        arr.append(inputs[i]);
    }

    for(std::size_t i = inputs.size()-1; i >= inputs.size()/2; i--)
    {
        arr.prepend(inputs[i]);
    }

    unsigned int first;
    arr.find_first_of(inputs[inputs.size()/3], &first);

    unsigned int last;
    arr.find_last_of(inputs[inputs.size()/3], &last);

    arr.remove_last();
    arr.remove_first();
    arr.clear();

    return 0;
}