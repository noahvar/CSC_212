#ifndef LAB_01_CODE_ANIMAL_H
#define LAB_01_CODE_ANIMAL_H

#include <iostream>

class Animal{
private:
    float hunger;
    float thirst;

public:
    virtual ~Animal() = default;

    Animal(float initial_hunger, float initial_thirst);
    void Eat(float sustenance);
    void Drink(float sustenance);
    float GetHunger();
    float GetThirst();
    virtual void Speak() = 0;
};

#endif //LAB_01_CODE_ANIMAL_H