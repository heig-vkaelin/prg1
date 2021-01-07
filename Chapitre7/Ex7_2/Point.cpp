//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>
#include "Point.h"

using namespace std;
using namespace Ex7_2;

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

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

void afficher(const Point &p) {
	cout << "(" << p.abscisse() << "," << p.ordonnee() << ")" << endl;
}

int ex7_2() {
	Point p(1.2f, 2.4f);
	afficher(p);
	p.deplacer(0.8f, 0.6f);
	afficher(p);

	return EXIT_SUCCESS;
}
