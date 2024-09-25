#include "DynamicArray.h"
#include <cstring>
#include <iostream>
#include <ostream>

int main(int argc, char *argv[])
{
    //create DEFAULT array
    DynamicArray defArr;
    //create CAPPED array
    DynamicArray capArr(2, 10);
    //create LENGTH array
    DynamicArray lenArr(2, 5, 0);

    std::cout << "cap before append: " << lenArr.get_capacity() << std::endl;

    lenArr.append(1);
    lenArr.append(0);
    lenArr.append(5);
    lenArr.append(0);
    lenArr.append(1);

    unsigned int first;
    unsigned int last;

    lenArr.find_first_of(5, &first);
    lenArr.find_last_of(0, &last);

    std::cout << "cap after append: " << lenArr.get_capacity() << std::endl;









    //output DEFAULT array
    // std::cout << "DEFAULT array: " << std::endl;
    // for (int i = 0; i < defArr.get_length(); i++)
    // {
    //     std::cout << defArr[i] << " ";
    // }
    // std::cout << "\n" << std::endl;

    //output CAPPED array
    // std::cout << "CAPPED array: " << std::endl;
    // for (int i = 0; i < capArr.get_length(); i++)
    // {
    //     std::cout << capArr[i] << " ";
    // }
    // std::cout << "\n" << std::endl;

    //output LENGTH array
    std::cout << "LENGTH array: " << std::endl;
    for (int i = 0; i < lenArr.get_length(); i++)
    {
        std::cout << lenArr[i] << " ";
    }

    return 0;
}
