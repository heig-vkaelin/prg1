//
// Created by Valentin on 15.12.2020.
//

#include <iostream>
#include "point.h"

using namespace std;
using namespace Ex7_1;

Point::Point(float x, float y) : x(x), y(y) {}

void Point::deplacer(float dx, float dy) {
	x += dx;
	y += dy;
}

void Point::afficher() const {
	cout << "(" << x << "," << y << ")" << endl;
}

int ex7_1() {
	Point p(1.2f, 2.4f);
	p.afficher();
	p.deplacer(0.8f, 0.6f);
	p.afficher();

	return EXIT_SUCCESS;
}
