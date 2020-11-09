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

void afficherTexteEtValeur(const string &texte, double valeur, int precision) {
	cout << texte << fixed << setprecision(precision) << valeur << endl;
}

int ex4_3() {
	afficherTexteEtValeur("volume pyramide 1 = ", volumePyramide(10, 3.5, 12), 1);
	afficherTexteEtValeur("volume pyramide 2 = ", volumePyramide(3.6, 2.4, 2.7), 1);

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
	double tmp = c;
	c = b;
	b = a;
	a = tmp;
}

void afficherEx4_8(double a, double b, double c) {
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
}

int ex4_8() {
	double a = 1, b = 2, c = 3;
	for (int i = 1; i <= 3; ++i) {
		permutationCirculaireDroite(a, b, c);
		afficherEx4_8(a, b, c);
	}
	return EXIT_SUCCESS;
}

double retrait(double montant, double &solde) {
	double retraitEffectif = solde > montant ? montant : solde;
	solde -= retraitEffectif;
	return retraitEffectif;
}

int ex4_9() {
	double solde = 500, retraitEffectif;

	retraitEffectif = retrait(300, solde);
	afficherTexteEtValeur("Montant retrait effectif = ", retraitEffectif, 1);
	afficherTexteEtValeur("Solde courant            = ", solde, 1);

	retraitEffectif = retrait(300, solde);
	afficherTexteEtValeur("Montant retrait effectif = ", retraitEffectif, 1);
	afficherTexteEtValeur("Solde courant            = ", solde, 1);

	return EXIT_SUCCESS;
}

void afficherEx4_13() {
	static int n;
	cout << "Appel numero " << ++n << endl;
}

int ex4_13() {
	for (int i = 0; i < 3; ++i) {
		afficherEx4_13();
	}
	return EXIT_SUCCESS;
}