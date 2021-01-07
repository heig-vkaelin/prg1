//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>
#include "Point.h"

using namespace std;
using namespace Ex7_5;

Point::Point(float x, float y) : x(x), y(y) {}

void Point::deplacer(float dx, float dy) {
	x += dx;
	y += dy;
}

float Point::abscisse() const {
	return x;
}

float Point::ordonnee() const {
	return y;
}

Point Point::operator+(const Point &p) const {
	return Point(x + p.x, y + p.y);
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

void afficher(const Point &p) {
	cout << "(" << p.abscisse() << "," << p.ordonnee() << ")" << endl;
}

int ex7_5() {
	const Point P1(1, 2);
	const Point P2 = Point(3, 4);
	afficher(P1 + P2);

	return EXIT_SUCCESS;
}
