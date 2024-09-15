#include "Animal.h"

class Bird : public Animal{
public:
    Bird(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak() override {
        std::cout << "Tweet!" << std::endl;
    }
};