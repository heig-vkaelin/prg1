cmake_minimum_required(VERSION 3.17)
project(PRG1_Exercices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(PRG1_Exercices main.cpp Chapitre1.cpp exercises.h Chapitre2.cpp
        Chapitre3.cpp TheorieChapitre3.cpp Chapitre4.cpp Chapitre5.cpp Chapitre6.cpp Chapitre7/Ex7_1/point.cpp Chapitre7/Ex7_1/point.h Chapitre7/Ex7_2/point.cpp Chapitre7/Ex7_2/point.h Chapitre7/Ex7_3/pays.cpp Chapitre7/Ex7_3/pays.h Chapitre7/Ex7_4/robot.cpp Chapitre7/Ex7_5/point.cpp Chapitre7/Ex7_5/point.h Chapitre7/Ex7_7/c.cpp Chapitre7/Ex7_8/objet.cpp Chapitre7/Ex7_9/voiture.cpp Chapitre7/Ex7_10-11/message.cpp Chapitre7/Ex7_10-11/message.h Chapitre7/Ex7_10-11/mailbox.cpp Chapitre7/Ex7_12/personne.cpp Chapitre7/Ex7_12/personne.h Chapitre7/Ex7_12/adresse.cpp Chapitre7/Ex7_12/adresse.h Chapitre8/ex8_2.cpp)