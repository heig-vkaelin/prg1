//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>
#include "point.h"

using namespace std;
using namespace Ex7_2;

Point::Point(float x, float y) {
	coordX = x;
	coordY = y;
}

void Point::translation(float deplacementX, float deplacementY) {
	coordX += deplacementX;
	coordY += deplacementY;
}

float Point::getAbscisse() const {
	return coordX;
}

float Point::getOrdonnee() const {
	return coordY;
}

int ex7_2() {
	Point p1(5, 2.5);
	cout << "(" << p1.getAbscisse() << "," << p1.getOrdonnee() << ")" << endl;
	p1.translation(-2, 1.5);
	cout << "(" << p1.getAbscisse() << "," << p1.getOrdonnee() << ")" << endl;

	return EXIT_SUCCESS;
}
