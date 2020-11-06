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

void permutationCirculaireDroite(double &a, double &b, double &c) {
	double tmp = a;
	a = b;
	b = c;
	c = tmp;
}

int ex4_8() {
	double a = 10, b = 2.5, c = 5;
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	permutationCirculaireDroite(a, b, c);
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
	return EXIT_SUCCESS;
}

double retirerMontant(double &solde, double montant) {
	double retrait = solde - montant >= 0 ? montant : solde;
	solde -= retrait;
	return retrait;
}

int ex4_9() {
	double solde = 500;
	double premierRetrait = retirerMontant(solde, 300);
	cout << "1er retrait: " << premierRetrait << " solde: " << solde << endl;
	double deuxiemeRetrait = retirerMontant(solde, 300);
	cout << "2e retrait: " << deuxiemeRetrait << " solde: " << solde << endl;

	return EXIT_SUCCESS;
}

void afficher() {
	static int n;
	cout << "Appel numero " << ++n << endl;
}

int ex4_13() {
	for (int i = 0; i < 3; ++i) {
		afficher();
	}
	return EXIT_SUCCESS;
}