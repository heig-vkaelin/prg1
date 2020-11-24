//
// Created by Valentin on 12.11.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>

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

void afficherTableau(const int tab[], size_t taille) {
	cout << "[";
	for (size_t i = 0; i < taille; ++i) {
		if (i > 0) {
			cout << ", ";
		}
		cout << tab[i];
	}
	cout << "]" << endl;
}

int ex5_4() {
	afficherTableau({}, 0);
	int t1[] = {1};
	afficherTableau(t1, 1);
	int t2[] = {1, 2};
	afficherTableau(t2, 2);

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

	afficherTableau(tab1, 4);
	permuterExtremitesTableau(tab1, 4);
	afficherTableau(tab1, 4);

	afficherTableau(tab2, 3);
	permuterExtremitesTableau(tab2, 3);
	afficherTableau(tab2, 3);

	afficherTableau(tab3, 2);
	permuterExtremitesTableau(tab3, 2);
	afficherTableau(tab3, 2);

	afficherTableau(tab4, 1);
	permuterExtremitesTableau(tab4, 1);
	afficherTableau(tab4, 1);

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

	afficherTableau(tab1, 6);
	remplacerValeursPaires(tab1, 6, NOMBRE_CHOISI);
	afficherTableau(tab1, 6);

	return EXIT_SUCCESS;
}

void decalageDroite(int tab[], size_t taille) {
	if (taille < 1) { return; }

	int tmp = tab[taille - 1];
	for (size_t i = taille - 1; i > 0; --i) {
		tab[i] = tab[i - 1];
	}
	tab[0] = tmp;
}

int ex5_8() {
	int tab1[] = {1, 2, 3, 4, 5, 6};

	afficherTableau(tab1, 6);
	decalageDroite(tab1, 6);
	afficherTableau(tab1, 6);
	return EXIT_SUCCESS;
}

void supprimerCentral(int tab[], size_t &taille) {
	if (taille <= 0) { return; }
	size_t decalage = taille % 2 ? 1 : 2;
	for (size_t i = taille / 2 + 1; i < taille; ++i) {
		tab[i - decalage] = tab[i];
	}
	taille -= decalage;
}

int ex5_9() {
	size_t tailleTab1 = 6;
	int tab1[] = {1, 2, 3, 4, 5, 6};

	size_t tailleTab2 = 5;
	int tab2[] = {1, 2, 3, 4, 5};

	afficherTableau(tab1, tailleTab1);
	supprimerCentral(tab1, tailleTab1);
	afficherTableau(tab1, tailleTab1);

	afficherTableau(tab2, tailleTab2);
	supprimerCentral(tab2, tailleTab2);
	afficherTableau(tab2, tailleTab2);

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

	afficherTableau(tab1, 4);
	cout << "Somme: " << sommeAlternee(tab1, 4) << endl;

	afficherTableau({}, 0);
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

	afficherTableau(tab1, tailleTab1);
	supprimerOccurrences(tab1, tailleTab1, 2);
	afficherTableau(tab1, tailleTab1);

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

	afficherTableau(tab1, tailleTab1);
	supprimerDoublons(tab1, tailleTab1);
	afficherTableau(tab1, tailleTab1);

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

void afficherVector(const vector<int> &vecteur) {
	cout << "[";
	for (size_t i = 0; i < vecteur.size(); ++i) {
		if (i > 0) {
			cout << ", ";
		}
		cout << vecteur.at(i);
	}
	cout << "]" << endl;
}

template<typename T>
void afficher(const T &container) {
	cout << "[";
	for (auto i = begin(container); i != end(container); ++i) {
		cout << *i;
		if (i != end(container) - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

bool tousImpairs(const vector<int> &vecteur) {
	for (int val : vecteur) {
		if (val % 2 == 0) {
			return false;
		}
	}
	return true;
}

int ex5_15() {
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2 = {1, 3, 5, 7};
	vector<int> v3 = {};

	afficherVector(v1);
	cout << boolalpha << tousImpairs(v1) << endl;

	afficherVector(v2);
	cout << boolalpha << tousImpairs(v2) << endl;

	afficherVector(v3);
	cout << boolalpha << tousImpairs(v3) << endl;

	return EXIT_SUCCESS;
}

vector<int> append(vector<int> v1, const vector<int> &v2) {
	v1.insert(v1.end(), v2.begin(), v2.end());
	return v1;
}

int ex5_16() {
	vector<int> v1 = {1, 3};
	vector<int> v2 = {2, 4, 5};

	afficherVector(v1);
	afficherVector(v2);
	auto v3 = append(v1, v2);
	afficherVector(v3);

	return EXIT_SUCCESS;
}

vector<int> merge(const vector<int> &v1, const vector<int> &v2) {
	vector<int> resultat;
	size_t tailleMax = v1.size() > v2.size() ? v1.size() : v2.size();
	for (size_t i = 0; i < tailleMax; ++i) {
		if (i < v1.size()) {
			resultat.push_back(v1[i]);
		}
		if (i < v2.size()) {
			resultat.push_back(v2[i]);
		}
	}
	return resultat;
}

int ex5_17() {
	vector<int> v1 = {1, 3, 5, 7};
	vector<int> v2 = {2, 4};

	afficher(v1);
	afficher(v2);

	auto resultat = merge(v1, v2);
	afficher(resultat);

	return EXIT_SUCCESS;
}

void afficher2DVector(const vector<vector<int>> &m) {
	cout << "[";
	for (size_t i = 0; i < m.size(); ++i) {
		cout << "(";
		for (size_t j = 0; j < m[i].size(); ++j) {
			cout << m[i][j] << (j < m[i].size() - 1 ? ", " : "");
		}
		cout << (i < m.size() - 1 ? "), " : ")");
	}
	cout << "]";
}

typedef vector<int> Ligne;
typedef vector<Ligne> Matrice;

void diagonalesMatrice(const Matrice &m, int &diagGauche, int &diagDroite) {
	const size_t TAILLE_LIGNE = m[0].size();

	for (size_t i = 0; i < m.size(); ++i) {
		diagGauche += m[i][i];
		diagDroite += m[i][TAILLE_LIGNE - i - 1];
	}
}

void afficherEx5_18(const Matrice &m, int diagGauche, int diagDroite) {
	cout << "La somme des elements de la diagonale gauche de ";
	afficher2DVector(m);
	cout << " vaut " << diagGauche << endl;
	cout << "La somme des elements de la diagonale droite de ";
	afficher2DVector(m);
	cout << " vaut " << diagDroite << endl;
}

int ex5_18() {
	Matrice m1 = {{1, 0, 1},
					  {0, 1, 0},
					  {1, 1, 0}};
	int diagonaleGauche = 0;
	int diagonaleDroite = 0;

	diagonalesMatrice(m1, diagonaleGauche, diagonaleDroite);
	afficherEx5_18(m1, diagonaleGauche, diagonaleDroite);

	return EXIT_SUCCESS;
}

vector<string> creerMatriceAlphabet() {
	const unsigned NB_LETTRES_ALPHABET = 26;
	vector<string> matrice;

	for (unsigned i = NB_LETTRES_ALPHABET; i > 0; --i) {
		string ligne;
		for (unsigned j = 0; j < i; ++j) {
			ligne += 'a' + (char) j;
		}
		matrice.push_back(ligne);
	}

	return matrice;
}

void afficherEx5_19(const vector<string> &matrice) {
	for (const string &ligne : matrice) {
		cout << ligne << endl;
	}
}

int ex5_19() {
	vector<string> matrice = creerMatriceAlphabet();
	afficherEx5_19(matrice);

	return EXIT_SUCCESS;
}

void afficherExtremites(array<int, 3> tab) {
	cout << "Premier element: " << *tab.begin() << endl;
	cout << "Dernier element: " << *(tab.end() - 1) << endl;
}

int ex5_21() {
	// 1)
	array<int, 3> tab1 = {1, 2, 3};
	// 2)
	afficher(tab1);
	// 3)
	afficherExtremites(tab1);
	// 4)
	tab1.fill(0);
	// 5)
	afficher(tab1);

	return EXIT_SUCCESS;
}
