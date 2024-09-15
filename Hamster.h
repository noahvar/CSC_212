#include "Animal.h"

class Hamster : public Animal{
public:
    Hamster(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak() override {
        std::cout << "Squeak!" << std::endl;
    }
};