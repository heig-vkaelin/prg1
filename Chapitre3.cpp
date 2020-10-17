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

	// Pour ne pas avoir à utiliser la lib string:
	// Utiliser le ternaire directement dans le cout
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

	{
		// Autre variante
		int min = a < b ? a : b;
		min = c < min ? c : min;
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

int ex3_12() {
	const unsigned NB_NOTES = 4;
	double n1, n2, n3, n4;
	cout << "Entrez " << NB_NOTES << " notes [1-6] :";
	cin >> n1 >> n2 >> n3 >> n4;

	double moyenne = (n1 + n2 + n3 + n4) / NB_NOTES;

	cout << fixed << setprecision(1)
		  << "Moyenne = " << moyenne << " - ";

	if (moyenne > 5.5) {
		cout << "Excellent";
	} else if (moyenne > 5) {
		cout << "Très bien";
	} else if (moyenne > 4.5) {
		cout << "Bien";
	} else if (moyenne >= 4.0) {
		cout << "Moyen";
	} else {
		cout << "Insuffisant";
	}
	cout << endl;

	return EXIT_SUCCESS;
}

int ex3_15() {
	enum class Mois {
		JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
		SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
	};
	int noMois;
	string jours;

	cout << "Entrez un no de mois (1-12) :";
	cin >> noMois;

	switch (noMois) {
		case (int) Mois::FEVRIER:
			jours = "28 ou 29";
			break;
		case (int) Mois::AVRIL:
		case (int) Mois::JUIN:
		case (int) Mois::SEPTEMBRE:
		case (int) Mois::NOVEMBRE:
			jours = "30";
			break;
		default:
			jours = "31";
	}

	cout << "Ce mois comporte " << jours << " jours." << endl;

	return EXIT_SUCCESS;
}

int ex3_19() {
	double montant;
	double tauxInteretAnnuel;

	cout << "Entrez un montant :";
	cin >> montant;
	cout << "Entrez un taux d'interet annuel (en %) :";
	cin >> tauxInteretAnnuel;

	const double MONTANT_CIBLE = montant * 2;

	// Avec boucle
	//	int annee = 0;
	//	while (montant < MONTANT_CIBLE) {
	//		++annee;
	//		double interet = montant * tauxInteretAnnuel / 100.0;
	//		montant += interet;
	//	}

	// Sans boucle
	// https://fr.wikipedia.org/wiki/Int%C3%A9r%C3%AAts_compos%C3%A9s
	double annee = ceil(
		log(MONTANT_CIBLE / montant) /
		log(1 + tauxInteretAnnuel / 100.0));

	cout << "Le montant sera doublé après " << annee << " années." << endl;
	return EXIT_SUCCESS;
}

int ex3_20() {
	const int W = 3;
	const int NOMBRE_MAX = 20;
	const int TAILLE_LOTS = 3;

	// 1) Version while
	int i = NOMBRE_MAX;
	while (i > 0) {
		cout << setw(W) << i;
		if (i % TAILLE_LOTS == 0) {
			cout << endl;
		}
		i--;
	}

	cout << endl << endl;

	// 2) Version for
	for (int j = NOMBRE_MAX; j > 0; --j) {
		cout << setw(W) << j;
		if (j % TAILLE_LOTS == 0) {
			cout << endl;
		}
	}

	return EXIT_SUCCESS;
}

int ex3_26() {
	int h;
	bool saisieOK;

	do {
		cout << "Hauteur du triangle (h >= 0) :";
		if (!(saisieOK = cin >> h && h >= 0)) {
			cin.clear();
			cout << "Saisie incorrecte. Veuillez recommencer." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOK);

	for (int ligne = 1; ligne <= h; ++ligne) {
		for (int espace = ligne; espace < h; ++espace) {
			cout << " ";
		}
		for (int etoile = 1; etoile <= (2 * ligne - 1); etoile++) {
			cout << "*";
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}
