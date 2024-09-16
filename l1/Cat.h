#include "Animal.h"

class Cat : public Animal{
public:
    Cat(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak() override {
        std::cout << "Meow!" << std::endl;
    }
};