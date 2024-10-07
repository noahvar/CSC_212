#pragma once  // Ensures the file is included only once during compilation

// Diagram of a simple singly linked list
// head
//  5  ->  3  ->  8  ->  6  -> X
// p1 (head pointer to the first node)

class Node {
private:
    int data;  // Stores the integer data for the node
    Node* next;  // Pointer to the next node in the list

    // Declares LinkedList class as a friend to allow access to private members
    friend class LinkedList;

public:
    // Default constructor
    // Initializes a node with default values
    Node();

    // Parameterized constructor to initialize a node with specific data
    Node(int data);

    // Parameterized constructor to initialize a node with specific data and the next node pointer
    Node(int data, Node* next);

    // Destructor
    // Ensures proper deletion of nodes
    ~Node();
};
