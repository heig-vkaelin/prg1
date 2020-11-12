//
// Created by Valentin on 12.11.2020.
//

#include <cstdlib>
#include <iostream>

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
		if (i + 1 != taille) {
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
}
