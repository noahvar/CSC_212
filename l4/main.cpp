#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){

    // Check if a file name was passed via command line argument (CLA)
    // Exit if no file is provided

    // Open the file given by the first command line argument

    // Check if the file opened successfully
    // Exit if the file cannot be opened

    // Read the first line to determine which constructor to use

    // Create a LinkedList object (will be based on constructor logic)

    // Process each subsequent line in the file (commands to modify the list)
    // Handle different types of inputs (integers, pairs, negative values, integers with '?')

    // If there's a single integer:
    // - If the integer is odd, prepend to the list
    // - If the integer is even, append to the list

    // If it's a negative integer, remove from the list (remove the '-')

    // If the line contains a pair of integers (for insertion)
    // - Insert the first integer at the index provided by the second integer

    // If the line contains a number with a '?'
    // - Check if the list contains the number and print the result

    // After each command, print the list (assuming there's a print function in LinkedList class)

    return 0;

}