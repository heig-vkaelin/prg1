//
// Created by Valentin Kaelin on 15.10.20.
//

#include <iostream>

using namespace std;

int exempleSaisieControleeInt_1() {
	int n;

	do {
		cout << "Entrez un int >= 0 : ";
		if (cin >> n && n >= 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vider le buffer
			break;
		} else {
			cout << "rdstate() = " << cin.rdstate() << endl; // affiche 4 => failbit
			cin.clear(); // Reset des bits d'erreur
			cout << "rdstate() = " << cin.rdstate() << endl; // affiche 0
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vider le buffer
			cout << "Saisie incorrecte. Veuillez recommencer." << endl;
		}
	} while (true);

	cout << "Vous avez saisi la valeur " << n << endl;

	return EXIT_SUCCESS;
}

int exempleSaisieControleeInt_2() {
	int n;
	bool saisieOK;

	do {
		cout << "Entrez un int >= 0 : ";
		saisieOK = cin >> n && n >= 0;
		if (!saisieOK) {
			cin.clear();
			cout << "Saisie incorrecte. Veuillez recommencer." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOK);

	cout << "Vous avez saisi la valeur " << n << endl;

	return EXIT_SUCCESS;
}

int exempleSaisieControleeInt_3() {
	int n;
	bool saisieOK;

	do {
		cout << "Entrez un int >= 0 : ";
		if (!(saisieOK = cin >> n && n >= 0)) { // Affectation dans la condition 💩
			cin.clear();
			cout << "Saisie incorrecte. Veuillez recommencer." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOK);

	cout << "Vous avez saisi la valeur " << n << endl;

	return EXIT_SUCCESS;
}
