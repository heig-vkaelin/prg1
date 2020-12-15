//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>
#include "point.h"

using namespace std;
using namespace Ex7_5;

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

Point Point::operator+(const Point &p) const {
	return Point(coordX + p.getAbscisse(), coordY + p.getOrdonnee());
}

int ex7_5() {
	Point p1(5, 2.5);
	Point p2(2, 1);
	cout << "p1: (" << p1.getAbscisse() << "," << p1.getOrdonnee() << ")" << endl;
	cout << "p2: (" << p2.getAbscisse() << "," << p2.getOrdonnee() << ")" << endl;

	Point p3 = p1 + p2;
	cout << "p3: (" << p3.getAbscisse() << "," << p3.getOrdonnee() << ")" << endl;

	return EXIT_SUCCESS;
}
