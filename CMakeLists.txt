cmake_minimum_required(VERSION 3.17)
project(PRG1_Exercices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(PRG1_Exercices main.cpp Chapitre1.cpp exercises.h Chapitre2.cpp
        Chapitre3.cpp TheorieChapitre3.cpp Chapitre4.cpp Chapitre5.cpp Chapitre6.cpp
        Chapitre7/Ex7_1/Point.cpp Chapitre7/Ex7_1/Point.h Chapitre7/Ex7_2/Point.cpp
        Chapitre7/Ex7_2/Point.h Chapitre7/Ex7_3/Pays.cpp Chapitre7/Ex7_3/Pays.h
        Chapitre7/Ex7_4/Robot.cpp Chapitre7/Ex7_5/Point.cpp Chapitre7/Ex7_5/Point.h
        Chapitre7/Ex7_7/C.cpp Chapitre7/Ex7_8/Objet.cpp Chapitre7/Ex7_9/Voiture.cpp
        Chapitre7/Ex7_10-11/Message.cpp Chapitre7/Ex7_10-11/Message.h Chapitre7/Ex7_10-11/Mailbox.cpp
        Chapitre7/Ex7_12/Personne.cpp Chapitre7/Ex7_12/Personne.h Chapitre7/Ex7_12/Adresse.cpp Chapitre7/Ex7_12/Adresse.h Chapitre7/Ex7_12/hobby.h
        Chapitre8/ex8_2.cpp Chapitre8/ex8_6.cpp Chapitre8/ex8_7.cpp Chapitre8/ex8_8.cpp)