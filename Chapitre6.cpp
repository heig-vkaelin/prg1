//
// Created by Valentin on 03.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

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

int nombreRomainEnDecimal(string romain) {
	int decimal = 0;
	map<char, int> m = {{'I', 1},
							  {'V', 5},
							  {'X', 10},
							  {'L', 50},
							  {'C', 100},
							  {'D', 500},
							  {'M', 1000}};

	for (size_t i = 0; i < romain.length(); i++) {
		if (m[romain[i + 1]] <= m[romain[i]]) {
			decimal += m[romain[i]];
		} else {
			decimal -= m[romain[i]];
		}
	}
	return decimal;
}

int ex6_9() {
	string exemple = "XIV";
	cout << exemple << " -> " << nombreRomainEnDecimal(exemple) << endl;

	return EXIT_SUCCESS;
}

int ex6_10() {
	const unsigned W = 20;
	int entier;
	cout << "Entrez un nombre entier >= 0 :";
	cin >> entier;
	string entierStr = to_string(entier);

	cout << left << setw(W) << "Nombre saisi" << ": " << entierStr << endl
		  << left << setw(W) << "Nombre de chiffres" << ": " << entierStr.length()
		  << endl
		  << left << setw(W) << "Premier chiffre " << ": " << entierStr.at(0) << endl
		  << left << setw(W) << "Dernier chiffre" << ": "
		  << entierStr.at(entierStr.length() - 1) << endl;

	return EXIT_SUCCESS;
}

int ex6_11() {
	const unsigned W = 19;
	string prenom, nom;
	cout << "Entrez votre prenom et votre nom :";
	cin >> prenom >> nom;
	string acronyme{prenom[0], nom[0], nom[nom.length() - 1]};
	for (char &lettre : acronyme) {
		lettre = (char) toupper(lettre);
	}

	cout << left << setw(W) << "Votre prenom est" << ": " << prenom << endl
		  << left << setw(W) << "Votre nom est" << ": " << nom << endl
		  << left << setw(W) << "Votre acronyme est" << ": "
		  << acronyme << endl;

	return EXIT_SUCCESS;
}