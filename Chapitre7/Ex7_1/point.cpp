//
// Created by Valentin on 15.12.2020.
//

#include <iostream>
#include "point.h"

using namespace std;
using namespace Ex7_1;

Point::Point(float x, float y) {
	coordX = x;
	coordY = y;
}

void Point::translation(float deplacementX, float deplacementY) {
	coordX += deplacementX;
	coordY += deplacementY;
}

void Point::afficher() const {
	cout << "(" << coordX << "," << coordY << ")" << endl;
}

int ex7_1() {
	Point p1(5, 3.5);
	p1.afficher();
	p1.translation(-2, 1.5);
	p1.afficher();

	return EXIT_SUCCESS;
}
