#include "linked_list.h"
#include <iostream>

// Default constructor
// Initializes an empty linked list with the head set to nullptr and size to 0
LinkedList::LinkedList(){
    // Initialize head pointer and size
    this->head = nullptr;
    this->size = 0;
}

// Constructor that creates a linked list with one node containing the given data
// Initializes the head with the node containing data and sets the size to 1
LinkedList::LinkedList(int data){
    // Create a new node with the provided data and set it as head
    this->head = new Node(data);
    // Update size to 1
    this->size = 1;
}

// Constructor that creates a linked list from a vector of integers
// Initializes the list by iterating through the vector and appending each element
LinkedList::LinkedList(std::vector<int> vec){
    //check if vec is empty
    if (vec.empty()) {
        this->head = nullptr;
        this->size = 0;
        return;
    }
    // For each element in the vector, append to the linked list
    this->head = new Node(vec[0]);
    Node* current = this->head;
    // For each element in the vector, create a new node and link it
    for (size_t i = 1; i < vec.size(); i++) {
        Node* newNode = new Node(vec[i]); // Create a new node
        current->next = newNode; // Link the new node to the current node
        current = newNode; // Move to the newly created node
    }
    this->size = vec.size();
}

// Destructor
// Recursively deletes all nodes to free memory
LinkedList::~LinkedList() {
    if (this->head != nullptr)
    {
        deleteNodes(head);
    }
}

void LinkedList::deleteNodes(Node* node) {
    if (node == nullptr) {
        return;
    }
    //delete next node
    deleteNodes(node->next);

    //delete current node
    delete node;
}


// Pushes a new node with data at the front of the list
// This involves creating a new node, linking it to the current head, and updating the head pointer
void LinkedList::push_front(int data){
    // Create a new node with the given data
    // Set the new node's next pointer to point to the current head node
    Node* newNode = new Node(data, head);

    // Update the head pointer to point to the new node (new node becomes the first node)
    head = newNode;
    // Increment the size of the list
    size++;
}

// Pushes a new node with data at the end of the list
// This involves traversing to the last node and appending the new node
void LinkedList::push_back(int data){
    // If the list is empty, the new node is added at the front using push_front
    if(head == nullptr)
    {
        push_front(data);
    }
    // Otherwise, create a new node
    Node* newNode = new Node(data);
    // Start traversal from the head node
    // Traverse through the list using a temporary pointer until you find the last node (i.e., a node whose next pointer is null)

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    // Once at the last node, set its next pointer to the new node (appending the new node)
        temp-> next = newNode;

    // Increment the size of the list
    size++;
}

// Inserts a new node at a specific index
// If the index is larger than the size, append the new node at the end
void LinkedList::insert(int data, int idx){
    // If index is 0, use push_front to add the node at the front
    if (idx == 0)
    {
        push_front(data);
        return;
    }
    // If index is greater than or equal to the size, use push_back to append the node at the end
    if (idx > size)
    {
        push_back(data);
        return;
    }
    // Otherwise, create a new node
    Node* newNode = new Node(data);
    // Traverse the list to the (idx-1)th node (i.e., one node before the insertion point)
    // Use a loop to move a temporary pointer forward (start at the head and stop at the (idx-1)th node)
    Node* temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }
    //insert new node between temp and temp->next
    temp->next = newNode;
    newNode->next = temp->next;

    // Increment the size of the list
    size++;
}

// Removes the node with the given data from the list
// This involves traversing the list, locating the node, and adjusting the pointers
void LinkedList::remove(int data) {
    // If the list is empty, there's nothing to remove
    if (head == nullptr) {
        return;
    }

    // If the node to be removed is the head node
    if (head->data == data) {
        Node* temp = head;      // Store the head node in a temporary variable
        head = head->next;      // Update head to the next node
        delete temp;            // Delete the old head
        size--;                 // Decrement the size
        return;                // Exit the function
    }

    // Use two pointers: temp for the current node, prev for the previous node
    Node* temp = head->next; // Start from the second node
    Node* prev = head;       // Initialize prev to head

    // Traverse the list to find the node with the given data
    while (temp != nullptr) {
        if (temp->data == data) {
            // Only update prev->next if prev is not a nullptr
            if(prev != nullptr)
            {
                prev->next = temp->next; // Bypass the current node
            }
            delete temp;             // Free the memory
            size--;                  // Decrement the size
            return;                 // Exit the function
        }
        prev = temp;    // Move prev to the current node
        temp = temp->next; // Move temp to the next node
    }

    // If we reach here, the data was not found; nothing to remove
}

// Checks if the list contains a node with the given data
// Traverses the list and returns true if the data is found, otherwise false
bool LinkedList::contains(int data){
    // Start traversal from the head node
    // Use a temporary pointer to traverse through each node in the list
    Node* temp = head;
    while (temp != nullptr)
    {
        // Check if the current node's data matches the given data
        if (temp->data == data)
        {
            // If a match is found, return true
            return true;
        }

    }
    // If the entire list is traversed without finding the data, return false
    return false;
}



// Returns the current size of the linked list
unsigned int LinkedList::get_size(){
    return this->size;  // Return the size of the list
}

// Converts the linked list to a string representation
// Concatenates all node data into a single string with space-separated values
// Time complexity: O(n) as it needs to traverse the entire list
std::string LinkedList::to_string() {
    std::string stringified;  // Stores the concatenated string
    Node* temp = this->head;  // Start from the head node

    if (temp == nullptr) {
        return "List is empty";  // Return a message for an empty list
    }

    while (temp != nullptr) {  // Traverse the list
        std::cout << "Current node data: " << temp->data << std::endl;  // Debugging statement
        stringified += std::to_string(temp->data) + " ";  // Append data to the string
        temp = temp->next;  // Move to the next node
    }

    return stringified;  // Return the concatenated string
}
