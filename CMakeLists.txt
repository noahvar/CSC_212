cmake_minimum_required(VERSION 3.29)
project(csc212_l1)

set(CMAKE_CXX_STANDARD 11)

add_executable(csc212_l1
        CSC_212_l1/main.cpp
        CSC_212_l1/Animal.cpp
        CSC_212_l1/Animal.h
        CSC_212_l1/Cat.h
        CSC_212_l1/Dog.h
        CSC_212_l1/Snake.h
        CSC_212_l1/Hamster.h
        CSC_212_l1/Bird.h)
add_executable(csc212_l1_2
        CSC_212_l1/main2.cpp
        CSC_212_l1/Animal.cpp
        CSC_212_l1/Animal.h
        CSC_212_l1/Cat.h
        CSC_212_l1/Dog.h
        CSC_212_l1/Snake.h
        CSC_212_l1/Hamster.h
        CSC_212_l1/Bird.h
        CSC_212_l1/animal.txt)
