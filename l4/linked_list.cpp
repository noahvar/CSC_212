#include "linked_list.h"
#include <iostream>

// Default constructor
// Initializes an empty linked list with the head set to nullptr and size to 0
LinkedList::LinkedList(){
    // Initialize head pointer and size
}

// Constructor that creates a linked list with one node containing the given data
// Initializes the head with the node containing data and sets the size to 1
LinkedList::LinkedList(int data){
    // Create a new node with the provided data and set it as head
    // Update size to 1
}

// Constructor that creates a linked list from a vector of integers
// Initializes the list by iterating through the vector and appending each element
LinkedList::LinkedList(std::vector<int> vec){
    // For each element in the vector, append to the linked list
}

// Destructor
// Recursively deletes all nodes to free memory
LinkedList::~LinkedList(){
    // Traverse through the list and delete all nodes
}

// Pushes a new node with data at the front of the list
// This involves creating a new node, linking it to the current head, and updating the head pointer
void LinkedList::push_front(int data){
    // Create a new node with the given data
    // Set the new node's next pointer to point to the current head node
    // Update the head pointer to point to the new node (new node becomes the first node)
    // Increment the size of the list
}

// Pushes a new node with data at the end of the list
// This involves traversing to the last node and appending the new node
void LinkedList::push_back(int data){
    // If the list is empty, the new node is added at the front using push_front
    // Otherwise, create a new node
    // Start traversal from the head node
    // Traverse through the list using a temporary pointer until you find the last node (i.e., a node whose next pointer is null)
    // Once at the last node, set its next pointer to the new node (appending the new node)
    // Increment the size of the list
}

// Inserts a new node at a specific index
// If the index is larger than the size, append the new node at the end
void LinkedList::insert(int data, int idx){
    // If index is 0, use push_front to add the node at the front
    // If index is greater than or equal to the size, use push_back to append the node at the end
    // Otherwise, create a new node
    // Traverse the list to the (idx-1)th node (i.e., one node before the insertion point)
    // Use a loop to move a temporary pointer forward (start at the head and stop at the (idx-1)th node)
    // Once at the (idx-1)th node, update its next pointer to point to the new node
    // Set the new node's next pointer to point to the (idx)th node (previously at idx)
    // Increment the size of the list
}

// Removes the node with the given data from the list
// This involves traversing the list, locating the node, and adjusting the pointers
void LinkedList::remove(int data){
    // If the list is empty, there's nothing to remove (return)
    // If the node to be removed is the head node, update the head pointer to the next node and delete the head node
    // Otherwise, traverse the list using two pointers:
    //   - A temporary pointer to keep track of the current node
    //   - A previous pointer to keep track of the node before the current one
    // Traverse until you find the node with the given data (or reach the end of the list)
    // Once the node is found, update the previous node's next pointer to bypass the current node
    // Delete the current node to free the memory
    // Decrement the size of the list
}

// Checks if the list contains a node with the given data
// Traverses the list and returns true if the data is found, otherwise false
bool LinkedList::contains(int data){
    // Start traversal from the head node
    // Use a temporary pointer to traverse through each node in the list
    // Check if the current node's data matches the given data
    // If a match is found, return true
    // If the entire list is traversed without finding the data, return false
}



// Returns the current size of the linked list
int LinkedList::get_size(){
    return this->size;  // Return the size of the list
}

// Converts the linked list to a string representation
// Concatenates all node data into a single string with space-separated values
// Time complexity: O(n) as it needs to traverse the entire list
std::string LinkedList::to_string(){
    std::string stringified;  // Stores the concatenated string
    Node* tmp = this->head;  // Start from the head node

    while(tmp != nullptr){  // Traverse the list
        stringified += std::to_string(tmp->data) + " ";  // Append data to the string
        tmp = tmp->next;  // Move to the next node
    }

    return stringified;  // Return the concatenated string
}
