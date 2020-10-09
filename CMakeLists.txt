cmake_minimum_required(VERSION 3.17)
project(PRG1_Exercices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(PRG1_Exercices main.cpp Chapitre1.cpp exercices.h Chapitre2.cpp Chapitre3.cpp)