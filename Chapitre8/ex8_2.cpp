//
// Created by Valentin on 04.01.2021.
//

#include <cstdlib>
#include <iostream>

class Temps {
public:
	Temps(const std::string &heures, const std::string &minutes)
		: heures(heures), minutes(minutes) {}

	bool operator==(const Temps &t) const {
		return t.heures == heures && t.minutes == minutes;
	}

	std::string toString() const {
		return heures + ":" + minutes;
	}

private:
	std::string heures, minutes;
};

template<typename T>
unsigned nbOcc(const T tab[], const T &element, size_t taille) {
	unsigned nbOcc = 0;
	for (size_t i = 0; i < taille; ++i) {
		if (tab[i] == element) nbOcc++;
	}
	return nbOcc;
}

using namespace std;

int ex8_2() {
	int tab1[] = {0, 1, 0};
	int valAChercher = 0;
	cout << "Nombre de valeur " + to_string(valAChercher) + ": "
		  << nbOcc(tab1, valAChercher, 3) << endl;

	Temps tab2[] = {
		Temps("07", "45"),
		Temps("09", "20"),
		Temps("12", "00"),
		Temps("21", "30"),
	};
	Temps tempsAChercher("12", "00");
	cout << "Nombre de " + tempsAChercher.toString() + ": "
		  << nbOcc(tab2, tempsAChercher, 4) << endl;

	string tab3[] = {"Paul", "Jacques", "Paul", "Jean", "Paul"};
	string strAChercher = "Paul";
	cout << "Nombre de \"" + strAChercher + "\": "
		  << nbOcc(tab3, strAChercher, 5) << endl;

//	const char *tab4[] = {"Paul", "Jacques", "Paul", "Jean", "Paul"};
//	const char *charATrouver = "Paul";
//	cout << "Nombre de \"" + strAChercher + "\": "
//		  << nbOcc(tab4, charATrouver, 5) << endl;

	return EXIT_SUCCESS;
}
