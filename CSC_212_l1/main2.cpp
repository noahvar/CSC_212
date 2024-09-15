#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char*argv[]){

    // Extract # of animals we're expecting to read from the CLA
    int num_of_animals = std::stoi(argv[1]);

    // Extract the name of the file we'll be reading from the CLA
    std::string file_name = argv[2];

    // Create a collection (data structure) of the appropriate size to hold the # of animals we are creating
    std::vector<Animal*> animals;

    //read the file and check if file was opened
    std::ifstream file(file_name);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << file_name << std::endl;
        return 1;
    }

    // Loop through the number of animals we have.
    // Read the current line from the file
    while(std::getline(file, line)) {
        // Tokenize the line into type, hunger, thirst
        std::istringstream inputs(line);
        //create tokens
        std::string animal_name;
        float hunger, thirst;

        inputs >> animal_name >> hunger >> thirst;

        // Based on the type, create the appropriate animal and add it to your collection of animals
        if(animal_name == "Cat") {
            animals.push_back(new Cat(hunger, thirst));
        }
        else if(animal_name == "Dog") {
            animals.push_back(new Dog(hunger, thirst));
        }
        else if(animal_name == "Hamster") {
            animals.push_back(new Hamster(hunger, thirst));
        }
        else if(animal_name == "Snake") {
            animals.push_back(new Snake(hunger, thirst));
        }
        else if(animal_name == "Bird") {
            animals.push_back(new Bird(hunger, thirst));
        }

    }

    // Loop through your collection of animals
    for(int i = 0; i < num_of_animals; i++){
        // Speak
        animals[i]->Speak();
        // Output hunger
        // Output thirst
        std::cout << animals[i]->GetHunger() << "\n" << animals[i]->GetThirst() << std::endl;
    }

    return 0;
}