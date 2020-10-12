//
// Created by Valentin on 09.10.2020.
//

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

int ex3_8() {
	int noMois;

	cout << "Entrez un no de mois (1-12) :";
	cin >> noMois;

	string jours = (noMois == 4 || noMois == 6 || noMois == 9 || noMois == 11) ?
						"30" : noMois == 2 ? "28 ou 29" : "31";

	cout << "Ce mois comporte " << jours << " jours." << endl;

	return EXIT_SUCCESS;
}

int ex3_9() {
	int a, b, c;

	cout << "Entrez 3 entiers séparés par un espace :";
	cin >> a >> b >> c;

	int min = a;
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}

	cout << "Le minimum des 3 entiers est: " << min << endl;

	return EXIT_SUCCESS;
}

int ex3_11() {
	int n;
	cout << "Entrez un entier n >= 0 :";
	cin >> n;

	if (n % 3 == 0 && n % 5 == 0) {
		cout << n << " est un multiple de 3 et 5" << endl;
	} else if (n % 3 == 0) {
		cout << n << " est un multiple de 3" << endl;
	} else if (n % 5 == 0) {
		cout << n << " est un multiple de 5" << endl;
	} else {
		cout << n << " n'est ni un multiple de 3 ni un multiple de 5" << endl;
	}

	return EXIT_SUCCESS;
}
