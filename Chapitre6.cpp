//
// Created by Valentin on 03.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string valeurBoolFR(int n) { return n == 0 ? "Faux" : "Vrai"; }

int ex6_1() {
	char c;
	const unsigned W = 20;
	cout << "Entrez un caractere :";
	cin >> c;

	cout << boolalpha << endl
		  << "Code ASCII de '" << c << "'" << setw(21) << " : " << (int) c
		  << endl
		  << "'" << c << "' est une lettre de l'alphabet"
		  << setw(6) << ": " << valeurBoolFR(isalpha(c)) << endl
		  << "'" << c << "' est une lettre minuscule"
		  << setw(10) << ": " << valeurBoolFR(islower(c)) << endl
		  << "'" << c << "' est un chiffre"
		  << setw(20) << ": " << valeurBoolFR(isdigit(c)) << endl
		  << "'" << c << "' est un caractere de ponctuation"
		  << setw(3) << ": " << valeurBoolFR(ispunct(c)) << endl;

	return EXIT_SUCCESS;
}

string milieu(const string &str) {
	if (str.empty()) { return "Chaine de caractere vide"; }
	unsigned decalage = str.size() % 2 ? 1 : 2;
	return str.substr(str.size() / 2 - decalage + 1, decalage);
}

int ex6_7() {
	cout << milieu("") << endl;
	cout << milieu("ABC") << endl;
	cout << milieu("ABCD") << endl;

	return EXIT_SUCCESS;
}