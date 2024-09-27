#include "DynamicArray.h"
#include <cstring>
#include <iostream>

// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}
// default constructor with a scaling factor, creates an array with capacity = capacity
DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    //Initialize the variables in each of the constructors.
    this->m_capacity = capacity;
    this->m_scaling_factor = scaling_factor;
    this->m_length = 0;
    m_data = new int[capacity];
    //..............
    // TODO
    //..............
}
// fill constructor, creates an array of capacity = length, and set all values to `default_value`
DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    this->m_length = length;
    this->m_capacity = length;
    this->m_scaling_factor = scaling_factor;
    m_data = new int[length];
    for (unsigned int i = 0; i < length; i++)
    {
        m_data[i] = default_value;
    }
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
    //use to_string function to convert each int in array
    //then put in the empty string by iterating again.

    // Initialize an empty string
    std::string str("");
    for(unsigned int i = 0; i < m_length; i++)
    {
        str.append(std::to_string(m_data[i]));
        str.append(" ");
    }
    return str;
    //..............
    // TODO
    //
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;

    // Check if index pointer is valid
    if (!index) {
        return false;  // Return false if index pointer is null
    }

    //iterate through the array and check if value = any of the array indices.
    for(unsigned int i = 0; i < m_length; i++)
    {
        if(m_data[i] == value)
        {
            *index = i;
            found = true;
            break;
        }
    }
    if(found == true)
    {
        std::cout << found << "\t" << *index << std::endl;
    }
    else
    {
        std::cout << found << "\t" << *index << std::endl;
    }
    return found;
    //..............
    // TODO
    //..............
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;

    //iterate through the array backwards and check if value = an array indices if it does set it equal to a value
    //continue until you've gone through whole array and then return the value.
    for(unsigned int i = m_length; i > 0; i--)
    {
        if(m_data[i] == value)
        {
            *index = i;
            found = true;
            break;
        }
    }
    if(found == true)
    {
        std::cout << found << "\t" << *index << std::endl;
    }
    else
    {
        std::cout << found << "\t" << *index << std::endl;
    }
    return found;
    //..............
    // TODO
    //..............
}

void DynamicArray::append(int value) {
    //check if size = capacity if it does reallocate
    if(m_length == m_capacity)
    {
        //copy data to new array
        int* new_data = new int[m_capacity * static_cast<unsigned int>(m_scaling_factor)];
        for(unsigned int i = 0; i < m_length; i++)
        {
            new_data[i] = m_data[i];
        }

        //deallocate memory not being used
        delete[] m_data;

        //make m_data = to new array
        m_data = new_data;
        //add appended value
        m_data[m_length] = value;
        //scale cap by the scaling factor
        m_capacity = m_capacity * static_cast<unsigned int>(m_scaling_factor);
    }
    else
    {
        //if space doesnt need to be reallocated just append
        m_data[m_length] = value;
    }
    //increment length to account for added value
    m_length++;
    //..............
    // TODO
    //..............
}

void DynamicArray::prepend(int value) {
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

    //check if size = capacity if it does reallocate
    if(m_length == m_capacity)
    {
        //copy data to new array
        int* new_data = new int[m_capacity * static_cast<unsigned int>(m_scaling_factor)];
        for(unsigned int i = 0; i < m_length; i++)
        {
            new_data[i] = m_data[i];
        }

        //deallocate memory not being used
        delete[] m_data;

        //make m_data = to new array
        m_data = new_data;
        //scale cap by the scaling factor
        m_capacity = m_capacity * static_cast<unsigned int>(m_scaling_factor);
    }
    //move all elements one index to the right
    for(unsigned int i = m_length; i > 0; i--)
    {
        m_data[i] = m_data[i-1];
    }
    //index 0 should be free now
    m_data[0] = value;
    //increment length after adding new element
    m_length++;
    //..............
    // TODO
    //..............
}

void DynamicArray::remove_last() {
    //if length of array is 0 there is nothing to remove
    if(m_length == 0)
    {
        return;
    }
    //remove last element by reducing size by one
    m_length--;
    //..............
    // TODO
    //..............
}

void DynamicArray::remove_first() {
    //check if there is nothing to remove
    if(m_length == 0)
    {
        return;
    }
    //shift everything to the left effectively deleting the first index value
    for(unsigned int i = 0; i < m_length-1; i++)
    {
        m_data[i] = m_data[i+1];
    }
    //decrease length because you removed
    m_length--;
    //..............
    // TODO
    //..............
}

void DynamicArray::clear() {
    if(m_capacity == 0)
    {
        return;
    }
    //deallocate memory being used by array
    delete[] m_data;

    //reset length and capacity
    m_length = 0;
    m_capacity = 0;

    //prevent dangling pointer
    m_data = nullptr;
    //..............
    // TODO
    //..............
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