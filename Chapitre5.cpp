//
// Created by Valentin on 12.11.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <iterator>

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

int sommeAlternee(const int tab[], size_t taille) {
	int somme = 0;
	for (size_t i = 0; i < taille; ++i) {
		somme += tab[i] * (i % 2 ? -1 : 1);
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

void supprimerOccurrences(int tab[], size_t &taille, int valeur,
								  size_t posDebut = 0) {
	size_t decalage = 0;
	for (size_t i = posDebut; i < taille; ++i) {
		tab[i - decalage] = tab[i];
		if (tab[i] == valeur) {
			decalage++;
		}
	}
	taille -= decalage;
}

int ex5_12() {
	size_t tailleTab1 = 10;
	int tab1[] = {1, 2, 3, 4, 5, 2, 6, 7, 2, 8};

	afficherTableau(tab1, tailleTab1);
	supprimerOccurrences(tab1, tailleTab1, 2);
	afficherTableau(tab1, tailleTab1);

	return EXIT_SUCCESS;
}

void supprimerDoublons(int tab[], size_t &taille) {
	if (taille < 2) { return; }
	for (size_t i = 0; i < taille - 1; ++i) {
		supprimerOccurrences(tab, taille, tab[i], i + 1);
	}
}

int ex5_13() {
	size_t tailleTab1 = 7;
	int tab1[] = {1, 2, 4, 2, 1, 1, 3};

	afficherTableau(tab1, tailleTab1);
	supprimerDoublons(tab1, tailleTab1);
	afficherTableau(tab1, tailleTab1);

	return EXIT_SUCCESS;
}

bool appartientA(const int t[], size_t n, int val) {
	for (size_t i = 0; i < n; ++i) {
		if (t[i] == val) {
			return true;
		}
	}
	return false;
}

bool estInclus(const int t1[], size_t n1, const int t2[], size_t n2) {
	for (size_t i = 0; i < n1; ++i) {
		if (!appartientA(t2, n2, t1[i])) {
			return false;
		}
	}
	return true;
}

bool tableauxEgaux(const int t1[], size_t n1, const int t2[], size_t n2) {
	return estInclus(t1, n1, t2, n2) && estInclus(t2, n2, t1, n1);
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
		  << tableauxEgaux(tab1, 6, tab2, 3) << endl
		  << tableauxEgaux(tab3, 5, tab4, 3) << endl
		  << tableauxEgaux(tab5, 3, tab6, 7) << endl
		  << tableauxEgaux(tab7, 5, tab8, 4) << endl;

	return EXIT_SUCCESS;
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

	afficher(v1);
	cout << boolalpha << tousImpairs(v1) << endl;

	afficher(v2);
	cout << boolalpha << tousImpairs(v2) << endl;

	afficher(v3);
	cout << boolalpha << tousImpairs(v3) << endl;

	return EXIT_SUCCESS;
}

vector<int> append(const vector<int> &v1, const vector<int> &v2) {
	vector<int> v;
	v.reserve(v1.size() + v2.size());
	v.insert(v.end(), v1.begin(), v1.end());
	v.insert(v.end(), v2.begin(), v2.end());
	return v;
}

int ex5_16() {
	vector<int> v1 = {1, 3};
	vector<int> v2 = {2, 4, 5};

	afficher(v1);
	afficher(v2);
	auto v3 = append(v1, v2);
	afficher(v3);

	return EXIT_SUCCESS;
}

vector<int> merge(const vector<int> &v1, const vector<int> &v2) {
	vector<int> resultat;
	resultat.reserve(v1.size() + v2.size());

	auto i1 = v1.begin();
	auto i2 = v2.begin();
	auto end = i1 + (long long) min(v1.size(), v2.size());

	while (i1 != end) {
		resultat.push_back(*i1);
		++i1;
		resultat.push_back(*i2);
		++i2;
	}
	resultat.insert(resultat.end(), i1, v1.end());
	resultat.insert(resultat.end(), i2, v2.end());

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

using Matrice = vector<vector<int>>;

template<typename T>
string to_string(const vector<vector<T>> &matrice) {
	string resultat = "[";
	for (size_t i = 0; i < matrice.size(); ++i) {
		if (i > 0) resultat += ", ";
		resultat += "(";
		for (size_t j = 0; j < matrice[i].size(); ++j) {
			if (j > 0) resultat += ", ";
			resultat += to_string(matrice[i][j]);
		}
		resultat += ")";
	}
	resultat += "]";

	return resultat;
}

void diagonalesMatrice(const Matrice &m, int &diagGauche, int &diagDroite) {
	const size_t TAILLE = m.size();
	diagGauche = 0, diagDroite = 0;

	for (size_t i = 0; i < m.size(); ++i) {
		diagGauche += m[i][i];
		diagDroite += m[i][TAILLE - i - 1];
	}
}

void afficherEx5_18(const Matrice &m, int diagGauche, int diagDroite) {
	cout << "La somme des elements de la diagonale gauche de "
		  << to_string(m) << " vaut " << diagGauche << endl;
	cout << "La somme des elements de la diagonale droite de "
		  << to_string(m) << " vaut " << diagDroite << endl;
}

int ex5_18() {
	const Matrice MATRICE = {{1, 0, 1},
									 {0, 1, 0},
									 {1, 1, 0}};
	int sommeDiagGauche = 0;
	int sommeDiagDroite = 0;

	diagonalesMatrice(MATRICE, sommeDiagGauche, sommeDiagDroite);
	afficherEx5_18(MATRICE, sommeDiagGauche, sommeDiagDroite);

	return EXIT_SUCCESS;
}

vector<vector<char>> creerMatriceAlphabet(const string &alphabet) {
	const size_t NB_LETTRES = alphabet.size();
	vector<vector<char>> matrice(NB_LETTRES);

	for (size_t i = 0; i < NB_LETTRES; ++i) {
		matrice.at(i).reserve(NB_LETTRES - i);
		matrice.at(i).assign(
			alphabet.begin(),
			alphabet.begin() + (long long) (NB_LETTRES - i)
		);
	}

	return matrice;
}

void afficherEx5_19(const vector<vector<char>> &matrice) {
	for (const vector<char> &ligne : matrice) {
		for (char c : ligne) {
			cout << c;
		}
		cout << endl;
	}
}

int ex5_19() {
	vector<vector<char>> matrice = creerMatriceAlphabet("abcdefghijklmnopqrstuvwxyz");
	afficherEx5_19(matrice);

	return EXIT_SUCCESS;
}

void afficherExtremites(array<int, 3> tab) {
	cout << "Premier element: " << tab.front() << endl;
	cout << "Dernier element: " << tab.back() << endl;
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

using ushort = unsigned short;
enum class Pays {
	CANADA, CHINE, ALLEMAGNE, COREE, JAPON, RUSSIE, ETATS_UNIS
};
const ushort NB_PAYS = 8;
const string PAYS[] = {"Canada", "Chine", "Allemagne", "Coree", "Japon", "Russie",
							  "Etats-Unis"};
enum class TypeMedaille {
	OR, ARGENT, BRONZE
};
const ushort NB_TYPES_MEDAILLE = 3;
const string TYPE_MEDAILLE[] = {"Or", "Argent", "Bronze"};
using Medailles_Obtenues = array<ushort, NB_TYPES_MEDAILLE>;
using Medailles = array<Medailles_Obtenues, NB_PAYS>;

unsigned nbTotalMedailles(const Medailles &medailles, const Pays &pays) {
	unsigned nbTotalMedailles = 0;
	for (ushort j = 0; j < NB_TYPES_MEDAILLE; ++j) {
		nbTotalMedailles += medailles[(ushort) pays][j];
	}

	return nbTotalMedailles;
}

unsigned nbTotalMedailles(const Medailles &medailles,
								  const TypeMedaille &typeMedaille) {
	unsigned nbTotalMedailles = 0;
	for (ushort i = 0; i < NB_PAYS; ++i) {
		nbTotalMedailles += medailles[i][(ushort) typeMedaille];
	}
	return nbTotalMedailles;
}

int ex5_22() {
	const Medailles MEDAILLES = {
		Medailles_Obtenues{1, 0, 1},
		Medailles_Obtenues{1, 1, 1},
		Medailles_Obtenues{0, 0, 1},
		Medailles_Obtenues{1, 0, 0},
		Medailles_Obtenues{0, 1, 1},
		Medailles_Obtenues{0, 1, 1},
		Medailles_Obtenues{1, 1, 1},
	};

	for (Pays p = Pays::CANADA; p <= Pays::ETATS_UNIS; p = (Pays) ((int) p + 1)) {
		unsigned nbMedailles = nbTotalMedailles(MEDAILLES, p);
		cout << setw(10) << left << PAYS[(int) p] << " : "
			  << nbMedailles << " medaille" << (nbMedailles >= 2 ? "s" : "")
			  << endl;
	}

	return EXIT_SUCCESS;
}

bool estImpair(int i) { return i % 2; }

bool tousImpairsV2(const vector<int> &v) {
	return all_of(v.begin(), v.end(), estImpair);
}

int ex5_23() {
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2 = {1, 3, 5, 7};
	vector<int> v3 = {};

	afficher(v1);
	cout << boolalpha << tousImpairsV2(v1) << endl;

	afficher(v2);
	cout << boolalpha << tousImpairsV2(v2) << endl;

	afficher(v3);
	cout << boolalpha << tousImpairsV2(v3) << endl;

	return EXIT_SUCCESS;
}

vector<int> appendV2(const vector<int> &v1, const vector<int> &v2) {
	vector<int> v(v1.size() + v2.size());
	copy(v2.begin(), v2.end(), copy(v1.begin(), v1.end(), v.begin()));
	return v;
}

int ex5_24() {
	vector<int> v1 = {1, 3};
	vector<int> v2 = {2, 4, 5};

	afficher(v1);
	afficher(v2);
	auto v3 = appendV2(v1, v2);
	afficher(v3);

	return EXIT_SUCCESS;
}

vector<int> ensemble(const vector<int> &v) {
	vector<int> w(v);
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	return w;
}

bool vecteursEgaux(const vector<int> &v1, const vector<int> &v2) {
	return ensemble(v1) == ensemble(v2);
}

int ex5_25() {
	vector<int> v1 = {3, 3, 1, 1, 2, 1};
	vector<int> v2 = {1, 2, 3};

	vector<int> v3 = {3, 3, 7, 0, 5, 2};
	vector<int> v4 = {3, 0, 5};

	vector<int> v5 = {5, 0, 3};
	vector<int> v6 = {3, 0, 0, 3, 5, 5, 3};

	vector<int> v7 = {1, 2, 3, 4, 5};
	vector<int> v8 = {1, 3, 2, 7};

	cout << boolalpha
		  << vecteursEgaux(v1, v2) << endl
		  << vecteursEgaux(v3, v4) << endl
		  << vecteursEgaux(v5, v6) << endl
		  << vecteursEgaux(v7, v8) << endl;

	return EXIT_SUCCESS;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	os << "[";
	for (auto i = v.begin(); i != v.end(); ++i) {
		if (i != v.begin()) { os << ", "; }
		os << *i;
	}
	os << "]";
	return os;
}

int ex5_26() {
	const int TAB[] = {3, 2, -5, 2, 4};
	vector<int> v;

	const size_t TAILLE_TAB = sizeof(TAB) / sizeof(int);
	v.resize(TAILLE_TAB);
	copy(TAB, TAB + TAILLE_TAB, v.begin());

	cout << "Le vecteur v initial :" << endl << v << endl
		  << "La plus petite valeur de v : "
		  << *min_element(v.begin(), v.end()) << endl
		  << "La plus grande valeur de v : "
		  << *max_element(v.begin(), v.end()) << endl
		  << "La somme des elements de v : "
		  << accumulate(v.begin(), v.end(), 0) << endl
		  << "Nombre d'occurrences de la valeur 2 dans v : "
		  << count(v.begin(), v.end(), 2) << endl
		  << "Nombre de valeurs impaires dans v : "
		  << count_if(v.begin(), v.end(), [](int n) { return n % 2; }) << endl;

	sort(v.begin(), v.end());
	cout << "Le vecteur v trie croissant : " << v << endl;

	sort(v.rbegin(), v.rend());
	cout << "Le vecteur v trie decroissant : " << v << endl;

	cout << "Vecteur compose des sommes partielles de v : " << endl;
	vector<int> sp(v.size());
	partial_sum(v.begin(), v.end(), sp.begin());
	cout << sp;

	return EXIT_SUCCESS;
}

int ex5_27() {
	const vector<string> PRENOMS = {"Pierre", "Pierre", "Pierre", "Paul", "Jacques",
											  "Jacques", "Henri", "Pierre", "Paul", "Jacques"};

	auto debut = PRENOMS.begin(),
		fin = PRENOMS.end(),
		courant = PRENOMS.begin();

	cout << "Dans le vecteur" << endl << PRENOMS << endl
		  << "on trouve : " << endl << endl;

	// Recherche dans PRENOMS les prénoms listés dans r1
	vector<string> r1 = {"Paul", "Henri"};
	while ((courant = find_first_of(courant, fin, r1.begin(), r1.end())) != fin) {
		cout << "- " << *courant
			  << " en position " << distance(debut, courant) << endl;
		++courant;
	}

	courant = PRENOMS.begin();

	// Recherche dans PRENOMS les positions du motif défini par r2
	vector<string> r2 = {"Pierre", "Paul", "Jacques"};
	while ((courant = search(courant, fin, r2.begin(), r2.end())) != fin) {
		cout << "- le motif " << r2
			  << " en position " << distance(debut, courant) << endl;
		++courant;
	}

	courant = PRENOMS.begin();

	// Recherche dans PRENOMS les positions des doublons
	while ((courant = adjacent_find(courant, fin)) != fin) {
		cout << "- un doublon en position " << distance(debut, courant) << endl;
		++courant;
	}

	return EXIT_SUCCESS;
}
