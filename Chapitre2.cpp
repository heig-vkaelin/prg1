//
// Created by Valentin Kaelin on 22.09.20.
//
#include <iostream>
#include <limits>
#include <cmath>

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
