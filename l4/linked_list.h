#include "node.h"
#include <vector>
#include <string>

class LinkedList{
private:
    Node* head;  // Pointer to the first node in the list
    unsigned int size;  // Stores the number of elements in the list

public:
    // Default constructor, initializes an empty linked list
    LinkedList(); // this->head = nullptr;

    // Constructor that initializes the list with a single node containing `data`
    LinkedList(int data);

    // Constructor that initializes the list with elements from a vector
    LinkedList(std::vector<int> vec);

    // Destructor to clean up the dynamically allocated nodes
    ~LinkedList();

    // Adds a new node with `data` to the front of the list
    void push_front(int data);

    // Adds a new node with `data` to the back of the list
    void push_back(int data);

    // Inserts a new node with `data` at the index `idx`
    // If `idx` is greater than the current size, appends the node to the end
    void insert(int data, int idx); // For any `idx` > `size`, append the value

    //helper function to with node deletion(recursion)
    void deleteNodes(Node* node);

    // Removes the node containing `data` from the list
    void remove(int data);

    // Checks if a node with `data` exists in the list
    bool contains(int data);

    // Returns the number of elements in the list
    unsigned int get_size();

    // Returns a string representation of the list
    std::string to_string();
};
