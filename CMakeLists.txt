cmake_minimum_required(VERSION 3.29)
project(csc212_l1 )

set(CMAKE_CXX_STANDARD 11)

add_executable(csc212_l1
        l1/main.cpp
        l1/Animal.cpp
        l1/Animal.h
        l1/Cat.h
        l1/Dog.h
        l1/Snake.h
        l1/Hamster.h
        l1/Bird.h)
add_executable(csc212_l1_2
        l1/main2.cpp
        l1/Animal.cpp
        l1/Animal.h
        l1/Cat.h
        l1/Dog.h
        l1/Snake.h
        l1/Hamster.h
        l1/Bird.h
        l1/animals.txt)
add_executable(l2
        l2/euler.cpp)
add_executable(l2_2
        l2/fib.cpp)
add_executable(l3
        l3/main.cpp
        l3/DynamicArray.cpp
        l3/DynamicArray.h)
add_executable(p1
        p1/main.cpp
        p1/maze.cpp
        p1/maze.h)
add_executable(l4
        l4/linked_list.cpp
        l4/linked_list.h
        l4/node.cpp
        l4/node.h
        l4/main.cpp)
add_executable(l5
        l5/hanoi.cpp)
add_executable(l6
        l6/main.cpp
        l6/sujiko.cpp
        l6/sujiko.h
        l6/sujikoTest.txt)
