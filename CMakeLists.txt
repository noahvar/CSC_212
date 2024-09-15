cmake_minimum_required(VERSION 3.29)
project(csc212_l1)

set(CMAKE_CXX_STANDARD 11)

add_executable(csc212_l1
        main.cpp
        Animal.cpp
        Animal.h
        Cat.h
        Dog.h
        Snake.h
        Hamster.h
        Bird.h)
add_executable(csc212_l1_2
        main2.cpp
        Animal.cpp
        Animal.h
        Cat.h
        Dog.h
        Snake.h
        Hamster.h
        Bird.h
        animal.txt)
