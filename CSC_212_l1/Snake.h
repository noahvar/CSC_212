#include "Animal.h"

class Snake : public Animal{
public:
    Snake(float initial_hunger, float initial_thirst) : Animal(initial_hunger, initial_thirst){};
    void Speak() override {
        std::cout << "Hisssss!" << std::endl;
    }
};