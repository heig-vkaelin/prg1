//
// Created by Valentin on 12.11.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int ex5_2() {
	// Tableau de 5 int
	int tab1[5];
	int tab2[5] = {};

	// Tableau de 5 int, 1er élément =1, 2e = 2
	int tab3[5] = {1, 2};
	int tab4[5];
	tab4[0] = 1;
	tab4[1] = 2;

	// Tableau de 5 bool, 1er = true, reste = false
	bool tab5[5] = {true};

	return EXIT_SUCCESS;
}

void afficherEx5_4(const int tab[], unsigned int taille) {
	cout << "[";
	for (unsigned i = 0; i < taille; ++i) {
		cout << tab[i];
		if (i != taille - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

int ex5_4() {
	afficherEx5_4({}, 0);
	int t1[] = {1};
	afficherEx5_4(t1, 1);
	int t2[] = {1, 2};
	afficherEx5_4(t2, 2);

	return EXIT_SUCCESS;
}

double somme(const double tab[], unsigned taille) {
	double somme = 0;
	for (unsigned i = 0; i < taille; ++i) {
		somme += tab[i];
	}
	return somme;
}

double moyenne(const double notes[], unsigned taille) {
	return somme(notes, taille) / taille;
}

unsigned lireNotes(double notes[], unsigned tailleMax) {
	unsigned i = 0;

	double noteTemp;
	do {
		cin >> noteTemp;
		if (noteTemp != 0) {
			notes[i] = noteTemp;
			i++;
		}
	} while (noteTemp != 0 && i < tailleMax);

	return i;
}

int ex5_5() {
	const unsigned NB_MAX_NOTES = 10;
	double notes[NB_MAX_NOTES];

	cout << "Entrez la liste de vos notes (10 notes max), 0 pour quitter :" << endl;
	unsigned nbNotes = lireNotes(notes, NB_MAX_NOTES);

	cout << fixed << setprecision(2) << endl;

	if (nbNotes) {
		cout << "La moyenne des notes saisies = " << moyenne(notes, nbNotes) << endl;
	} else {
		cout << "Moyenne non calculable car aucune note saisie !" << endl;
	}

	return EXIT_SUCCESS;
}

void permuterExtremitesTableau(int tab[], unsigned taille) {
	if (taille < 2) {
		return;
	}

	int tmp = tab[0];
	tab[0] = tab[taille - 1];
	tab[taille - 1] = tmp;
}

int ex5_6() {
	int tab1[] = {1, 2, 3, 4};
	int tab2[] = {42, 69, 23};
	int tab3[] = {1, 2};
	int tab4[] = {23};

	afficherEx5_4(tab1, 4);
	permuterExtremitesTableau(tab1, 4);
	afficherEx5_4(tab1, 4);

	afficherEx5_4(tab2, 3);
	permuterExtremitesTableau(tab2, 3);
	afficherEx5_4(tab2, 3);

	afficherEx5_4(tab3, 2);
	permuterExtremitesTableau(tab3, 2);
	afficherEx5_4(tab3, 2);

	afficherEx5_4(tab4, 1);
	permuterExtremitesTableau(tab4, 1);
	afficherEx5_4(tab4, 1);

	return EXIT_SUCCESS;
}

void remplacerValeursPaires(int tab[], unsigned taille, int valeur) {
	for (unsigned i = 0; i < taille; ++i) {
		if (tab[i] % 2 == 0) {
			tab[i] = valeur;
		}
	}
}

int ex5_7() {
	const int NOMBRE_CHOISI = 42;
	int tab1[] = {1, 2, 3, 4, 5, 6};

	afficherEx5_4(tab1, 6);
	remplacerValeursPaires(tab1, 6, NOMBRE_CHOISI);
	afficherEx5_4(tab1, 6);

	return EXIT_SUCCESS;
}

void decalageDroite(int tab[], unsigned taille) {
	int tmp = tab[taille - 1];
	for (unsigned i = taille - 1; i > 0; --i) {
		tab[i] = tab[i - 1];
	}
	tab[0] = tmp;
}

int ex5_8() {
	int tab1[] = {1, 2, 3, 4, 5, 6};

	afficherEx5_4(tab1, 6);
	decalageDroite(tab1, 6);
	afficherEx5_4(tab1, 6);
	return EXIT_SUCCESS;
}

void supprimerCentral(int tab[], unsigned &taille) {
	unsigned decalage = taille % 2 == 0 ? 2 : 1;
	for (unsigned i = taille / 2 + 1; i < taille; ++i) {
		tab[i - decalage] = tab[i];
	}
	taille -= decalage;
}

int ex5_9() {
	unsigned tailleTab1 = 6;
	int tab1[] = {1, 2, 3, 4, 5, 6};

	unsigned tailleTab2 = 5;
	int tab2[] = {1, 2, 3, 4, 5};

	afficherEx5_4(tab1, tailleTab1);
	supprimerCentral(tab1, tailleTab1);
	afficherEx5_4(tab1, tailleTab1);

	afficherEx5_4(tab2, tailleTab2);
	supprimerCentral(tab2, tailleTab2);
	afficherEx5_4(tab2, tailleTab2);

	return EXIT_SUCCESS;
}

int sommeAlternee(const int tab[], unsigned taille) {
	int somme = 0;
	for (unsigned i = 0; i < taille; ++i) {
		somme += i % 2 == 0 ? tab[i] : -tab[i];
	}
	return somme;
}

int ex5_11() {
	int tab1[] = {1, 2, 3, 4};

	afficher(tab1, 4);
	cout << "Somme: " << sommeAlternee(tab1, 4) << endl;

	afficher({}, 0);
	cout << "Somme: " << sommeAlternee({}, 0) << endl;

	return EXIT_SUCCESS;
}

void supprimerOccurrences(int tab[], unsigned &taille, int valeur) {
	unsigned decalage = 0;
	for (unsigned i = 0; i < taille; ++i) {
		tab[i - decalage] = tab[i];
		if (tab[i] == valeur) {
			decalage++;
		}
	}
	taille -= decalage;
}

int ex5_12() {
	unsigned tailleTab1 = 10;
	int tab1[] = {1, 2, 3, 4, 5, 2, 6, 7, 2, 8};

	afficher(tab1, tailleTab1);
	supprimerOccurrences(tab1, tailleTab1, 2);
	afficher(tab1, tailleTab1);

	return EXIT_SUCCESS;
}
