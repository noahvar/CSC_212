#include "node.h"

// Default constructor
// Initializes the node with data set to 0 and next pointer set to nullptr
Node::Node(){
    this->data = 0;
    this->next = nullptr;
}

// Parameterized constructor
// Initializes the node with the given data and next pointer set to nullptr
Node::Node(int data){
    this->data = data;
    this->next = nullptr;
}

// Parameterized constructor
// Initializes the node with the given data and sets the next pointer to the given node
Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}

// Destructor
// Recursively deletes the next node if it exists
Node::~Node()
{
    //handled in linklist destructor
}
