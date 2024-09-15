#include "Animal.h"

Animal::Animal(float initial_hunger, float initial_thirst){
    this->hunger = initial_hunger;
    this->thirst = initial_thirst;
}

float Animal::GetHunger(){
    return this->hunger;
}

float Animal::GetThirst() {
    return this->thirst;
}

void Animal::Drink(float sustenance) {
    this->hunger += sustenance;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}

void Animal::Speak() {
    std::cout << "Hi, I'm a talking animal, don't be scared";
}