//
// Created by Valentin on 29.10.2020.
//

#include "cstdlib"
#include <iostream>
#include <iomanip>

using namespace std;

double volumePyramide(double longueur, double largeur, double hauteur) {
	return longueur * largeur * hauteur / 3;
}

int ex4_3() {
	cout << fixed << setprecision(1);
	cout << volumePyramide(10, 3.5, 12) << endl;
	cout << volumePyramide(3.6, 2.4, 2.7) << endl;

	return EXIT_SUCCESS;
}

bool estBissextile(unsigned annee) {
	return annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0);
}

int ex4_4() {
	cout << "1900 " << (estBissextile(1900) ? "est" : "n'est pas")
		  << " bissextile." << endl;
	cout << "2000 " << (estBissextile(2000) ? "est" : "n'est pas")
		  << " bissextile." << endl;
	cout << "2010 " << (estBissextile(2010) ? "est" : "n'est pas")
		  << " bissextile." << endl;
	cout << "2020 " << (estBissextile(2020) ? "est" : "n'est pas")
		  << " bissextile." << endl;

	return EXIT_SUCCESS;
}