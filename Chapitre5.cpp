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

	// Tableau de 5 int, 1er élément = 1, 2e = 2
	int tab2[5] = {1, 2};
	int tab3[] = {1, 2};

	// Tableau de 5 bool, 1er = true, reste = false
	bool tab4[5] = {true, false, false, false, false};
	bool tab5[] = {true, false, false, false, false};
	bool tab6[5] = {true};

	return EXIT_SUCCESS;
}

void afficher(const int tab[], unsigned taille) {
	cout << "[";
	for (unsigned i = 0; i < taille; ++i) {
		if (i > 0) {
			cout << ", ";
		}
		cout << tab[i];
	}
	cout << "]" << endl;
}

int ex5_4() {
	afficher({}, 0);
	int t1[] = {1};
	afficher(t1, 1);
	int t2[] = {1, 2};
	afficher(t2, 2);

	return EXIT_SUCCESS;
}

double moyenne(const double notes[], unsigned nbNotes) {
	double somme = 0;
	for (unsigned i = 0; i < nbNotes; ++i) {
		somme += notes[i];
	}
	return somme / nbNotes;
}

unsigned lireNotes(double notes[], unsigned nbNotesMax) {
	cout << "Entrez la liste de vos notes (" << nbNotesMax
		  << " notes max), 0 pour quitter :" << endl;

	// 1ère variante:
	//	double noteSaisie;
	//	unsigned nbNotesSaisies = 0;
	//	do {
	//		cin >> noteSaisie;
	//		if (noteSaisie != 0) {
	//			notes[nbNotesSaisies++] = noteSaisie;
	//		}
	//	} while (noteSaisie != 0 && nbNotesSaisies < nbNotesMax);
	//	return nbNotesSaisies;

	// Autre variante avec boucle for au lieu de do while:
	for (unsigned i = 0; i < nbNotesMax; ++i) {
		cin >> notes[i];
		if (notes[i] == 0) {
			return i;
		}
	}
	return nbNotesMax;
}

int ex5_5() {
	const unsigned NB_MAX_NOTES = 10;
	double notes[NB_MAX_NOTES];

	unsigned nbNotesSaisies = lireNotes(notes, NB_MAX_NOTES);

	cout << endl;
	if (nbNotesSaisies) {
		cout << fixed << setprecision(2)
			  << "La moyenne des notes saisies = " << moyenne(notes, nbNotesSaisies)
			  << endl;
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

	afficher(tab1, 4);
	permuterExtremitesTableau(tab1, 4);
	afficher(tab1, 4);

	afficher(tab2, 3);
	permuterExtremitesTableau(tab2, 3);
	afficher(tab2, 3);

	afficher(tab3, 2);
	permuterExtremitesTableau(tab3, 2);
	afficher(tab3, 2);

	afficher(tab4, 1);
	permuterExtremitesTableau(tab4, 1);
	afficher(tab4, 1);

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

	afficher(tab1, 6);
	remplacerValeursPaires(tab1, 6, NOMBRE_CHOISI);
	afficher(tab1, 6);

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

	afficher(tab1, 6);
	decalageDroite(tab1, 6);
	afficher(tab1, 6);
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

	afficher(tab1, tailleTab1);
	supprimerCentral(tab1, tailleTab1);
	afficher(tab1, tailleTab1);

	afficher(tab2, tailleTab2);
	supprimerCentral(tab2, tailleTab2);
	afficher(tab2, tailleTab2);

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

void supprimerDoublons(int tab[], unsigned &taille) {
	for (unsigned i = 0; i < taille; i++) {
		for (unsigned j = 0; j < i; j++) {
			if (tab[i] == tab[j]) {
				taille--;
				for (unsigned k = i; k < taille; k++) {
					tab[k] = tab[k + 1];
				}
				i--;
			}
		}
	}
}

int ex5_13() {
	unsigned tailleTab1 = 7;
	int tab1[] = {1, 2, 4, 2, 1, 1, 3};

	afficher(tab1, tailleTab1);
	supprimerDoublons(tab1, tailleTab1);
	afficher(tab1, tailleTab1);

	return EXIT_SUCCESS;
}

//void copierTableau(const int tabSource[], int tabDest[], unsigned taille) {
//	for (unsigned i = 0; i < taille; i++) {
//		tabDest[i] = tabSource[i];
//	}
//}

unsigned chercher(const int tab[], unsigned taille, int val, unsigned pos = 0) {
	for (; pos < taille; ++pos) {
		if (tab[pos] == val) {
			return pos;
		}
	}
	return taille;
}

bool tableauxEgaux(const int tab1[], const int tab2[], unsigned tailleTab1,
						 unsigned tailleTab2) {
	unsigned tailleMax = tailleTab1 < tailleTab2 ? tailleTab2 : tailleTab1;

	for (unsigned i = 0; i < tailleMax; ++i) {
		bool elementDansTab1 =
			i > tailleTab1 - 1 || chercher(tab2, tailleTab2, tab1[i]) != tailleTab2;
		bool elementDansTab2 =
			i > tailleTab2 - 1 || chercher(tab1, tailleTab1, tab2[i]) != tailleTab1;

		if (!elementDansTab1 || !elementDansTab2) {
			return false;
		}
	}
	return true;
}


int ex5_14() {
	int tab1[] = {3, 3, 1, 1, 2, 1};
	int tab2[] = {1, 2, 3};

	int tab3[] = {3, 3, 7, 0, 5, 2};
	int tab4[] = {3, 0, 5};

	int tab5[] = {5, 0, 3};
	int tab6[] = {3, 0, 0, 3, 5, 5, 3};

	int tab7[] = {1, 2, 3, 4, 5};
	int tab8[] = {1, 3, 2, 7};

	cout << boolalpha
		  << tableauxEgaux(tab1, tab2, 6, 3) << endl
		  << tableauxEgaux(tab3, tab4, 6, 3) << endl
		  << tableauxEgaux(tab5, tab6, 3, 7) << endl
		  << tableauxEgaux(tab7, tab8, 5, 4) << endl;

	return EXIT_SUCCESS;
}
