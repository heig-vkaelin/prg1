cmake_minimum_required(VERSION 3.17)
project(PRG1_Exercices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(PRG1_Exercices main.cpp Chapitre1.cpp exercises.h Chapitre2.cpp
        Chapitre3.cpp TheorieChapitre3.cpp Chapitre4.cpp Chapitre5.cpp Chapitre6.cpp Chapitre7/Ex7_1/point.cpp Chapitre7/Ex7_1/point.h Chapitre7/Ex7_2/point.cpp Chapitre7/Ex7_2/point.h Chapitre7/Ex7_3/pays.cpp Chapitre7/Ex7_3/pays.h Chapitre7/Ex7_4/robot.cpp Chapitre7/Ex7_5/point.cpp Chapitre7/Ex7_5/point.h Chapitre7/Ex7_7/c.cpp)