//
// Created by Valentin Kaelin on 22.09.20.
//
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

int ex2_4() {
	cout << "signed char (" << sizeof(signed char) * 8 << " bits) : " <<
		  SCHAR_MIN << " .. " << SCHAR_MAX << endl;

	cout << "short (" << sizeof(short) * 8 << " bits) : " <<
		  numeric_limits<short>::lowest() << " .. " << numeric_limits<short>::max()
		  << endl;

	cout << "int (" << sizeof(int) * 8 << " bits) : " << INT_MIN << " .. " <<
		  INT_MAX << endl;

	cout << "long (" << sizeof(long) * 8 << " bits) : " << LONG_MIN << " .. " <<
		  LONG_MAX << endl;

	cout << "long long (" << sizeof(long long) * 8 << " bits) : " << LONG_LONG_MIN
		  << " .. " << LONG_LONG_MAX << endl;

	return EXIT_SUCCESS;
}

int ex2_11() {
	const double CM3_EN_LITRE = 1E-3;
	double r1, r2, h1, h2, h3; // [cm]

	cout << "Entrez le rayon du cylindre 1 (en cm) : " << endl;
	cin >> r1;
	cout << "Entrez le rayon du cylindre 2 (en cm) : " << endl;
	cin >> r2;
	cout << "Entrez la hauteur du cylindre 1 (en cm) : " << endl;
	cin >> h1;
	cout << "Entrez la hauteur du cylindre 2 (en cm) : " << endl;
	cin >> h2;
	cout << "Entrez la hauteur du tronc du cone (en cm) : " << endl;
	cin >> h3;

	const double VOLUME_CYLINDRE_1 = M_PI * r1 * r1 * h1,
		VOLUME_CYLINDRE_2 = M_PI * r2 * r2 * h2,
		VOLUME_CONE = M_PI * (r1 * r1 + r1 * r2 + r2 * r2) * h3 / 3,
		VOLUME_TOTAL = (VOLUME_CYLINDRE_1 + VOLUME_CYLINDRE_2 + VOLUME_CONE) *
							CM3_EN_LITRE;

	cout << fixed << setprecision(1)
		  << "La bouteille peut contenir " << VOLUME_TOTAL << " litre"
		  << (VOLUME_TOTAL < 2 ? "" : "s") << "." << endl;

	return EXIT_SUCCESS;
}

int ex2_12() {
	const double METRES_EN_MILES = 6.213711922e-4,
		METRES_EN_PIEDS = 3.280839895,
		METRES_EN_POUCES = 39.37007874;

	// Saisie utilisateur
	unsigned nbMetres;
	cout << "Entrez le nombre de metres a convertir (entier > 0) : ";
	cin >> nbMetres;

	// Affichage du résultat des diverses conversions
	const int W = (int) log10(nbMetres) + 8;

	cout << fixed << setprecision(2) << endl
		  << nbMetres << " [m] = " << nbMetres * METRES_EN_MILES << " [mile]" << endl
		  << setw(W) << "= " << nbMetres * METRES_EN_PIEDS << " [ft]" << endl
		  << setw(W) << "= " << nbMetres * METRES_EN_POUCES << " [inch]" << endl;

	return EXIT_SUCCESS;
}


int ex2_13() {
	unsigned saisie;

	cout << "Entrez un nombre entier > 0 : ";
	cin >> saisie;

	unsigned nbChiffres = (unsigned) log10(saisie) + 1;
	unsigned premierChiffre = (unsigned) (saisie / pow(10, nbChiffres - 1));
	unsigned dernierChiffre = saisie % 10;

	cout << endl;
	cout << "Nombre saisi         : " << saisie << endl;
	cout << "Nombre de chiffres   : " << nbChiffres << endl;
	cout << "Premier chiffre      : " << premierChiffre << endl;
	cout << "Dernier chiffre      : " << dernierChiffre << endl;

	return EXIT_SUCCESS;
}
