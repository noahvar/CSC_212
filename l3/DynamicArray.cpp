#include "DynamicArray.h"
#include <cstring>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}
// default constructor with a scaling factor, creates an array with capacity = capacity
DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //..............
    // TODO
    //..............
    //Initialize the variables in each of the constructors.
}
// fill constructor, creates an array of capacity = length, and set all values to `default_value`
DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    //..............
    // TODO
    //..............
}
//copy constructor
DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other;
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str("");

	//..............
    // TODO
    //
    //use to_string function to convert each int in array
    //then put in the empty string by iterating again.

    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    //iterate through the array and check if value = any of the array indices.
    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    //iterate through the array and check if value = an array indices if it does set it equal to a value
    //continue until you've gone through whole array and then return the value.
    return found;
}

void DynamicArray::append(int value) {
    //..............
    // TODO
    //..............
    //check if size = capacity if it does reallocate
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //..............
    //function prepend
    //     if size == capacity
    //         reallocate
    //     end if
    //     for i = size downto 1
    //         array[i] = array[i - 1]
    //     end for
    //     array[0] = element
    //     size = size + 1
    //     end function
}

void DynamicArray::remove_last() {
    //..............
    // TODO
    //..............
    // function remove_last
    // if size == 0
    //     return
    // end if
    // size = size - 1
    // end function
}

void DynamicArray::remove_first() {
    //..............
    // TODO
    //..............
    // function remove_first
    // if size == 0
    //     return
    // end if
    // for i = 0 to size - 2
    //     array[i] = array[i + 1]
    // end for
    // size = size - 1
    // end function
}

void DynamicArray::clear() {
    //..............
    // TODO
    //..............
    //if size = 0 exit
    //set size = 0;
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);
    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this);
}