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

    //to determine which constructor to use
    DynamicArray arr;

    if(argc <= 2){
        arr = DynamicArray();
    }
    else if(argc == 4){
        double scaling_factor = std::stod(argv[2]);
        unsigned int capacity = std::stoi(argv[3]);
        arr = DynamicArray(scaling_factor, capacity);
    }
    else if(argc == 5){
        double scaling_factor = std::stod(argv[2]);
        unsigned int length = std::stoi(argv[3]);
        int val = std::stoi(argv[4]);
        arr = DynamicArray(scaling_factor, length, val);
    }

    for(std::size_t i = 0; i < inputs.size()/2; i++)
    {
        arr.append(inputs[i]);
    }
    std::cout << arr.to_string() << std::endl;
    //std::cout << "APPENED: " << arr.to_string() << std::endl;

    for(std::size_t i = inputs.size()/2; i < inputs.size(); i++)
    {
        arr.prepend(inputs[i]);
    }
    std::cout << arr.to_string() << std::endl;
    // std::cout << "PREPEND: " << arr.to_string() << std::endl;

    unsigned int first;
    arr.find_first_of(inputs[inputs.size()/3], &first);

    unsigned int last;
    arr.find_last_of(inputs[inputs.size()/3], &last);

    arr.remove_last();
    std::cout << arr.to_string() << std::endl;
    // std::cout << "REMOVE LAST: " << arr.to_string() << std::endl;

    arr.remove_first();
    std::cout << arr.to_string() << std::endl;
    // std::cout << "REMOVE FIRST: " << arr.to_string() << std::endl;

    arr.clear();
    std::cout << arr.to_string() << std::endl;
    // std::cout << "CLEAR" << arr.to_string() << std::endl;

    return 0;
}