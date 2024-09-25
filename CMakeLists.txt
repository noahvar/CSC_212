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
        l1/Bird.h
        l2/MaxSub.cpp)
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
add_executable(l2_3
        l2/csvPlot.cpp)
add_executable(l2_4
        l2/MaxSub.cpp)
add_executable(p1
        p1/main.cpp
        p1/maze.cpp
        p1/maze.h)
