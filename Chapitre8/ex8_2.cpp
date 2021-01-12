//
// Created by Valentin on 04.01.2021.
//

#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
using ushort = unsigned short;

class Temps {
public:
	Temps(ushort heure, ushort minute);

	bool operator==(const Temps &t) const;

private:
	ushort heure, minute;
};

Temps::Temps(ushort heure, ushort minute) : heure(heure), minute(minute) {}

bool Temps::operator==(const Temps &t) const {
	return t.heure == heure && t.minute == minute;
}

template<typename T>
size_t nbOcc(const T tab[], size_t taille, const T &element) {
	return (size_t) count(tab, tab + taille, element);
}

int ex8_2() {
	{
		const int TAB[] = {0, 1, 0};
		const size_t TAILLE = sizeof(TAB) / sizeof(int);
		size_t n = nbOcc(TAB, TAILLE, 0);
		cout << "nbr d'occurrences = " << n << endl;
	}
	{
		const Temps TAB[] = {
			{7,  45},
			{9,  20},
			{12, 0},
			{21, 30}
		};
		const size_t TAILLE = sizeof(TAB) / sizeof(Temps);
		size_t n = nbOcc(TAB, TAILLE, {12, 0});
		cout << "nbr d'occurrences = " << n << endl;
	}
	{
		const string TAB[] = {"Paul", "Jacques", "Paul", "Jean", "Paul"};
		const size_t TAILLE = sizeof(TAB) / sizeof(string);
		size_t n = nbOcc(TAB, TAILLE, string("Paul"));
		cout << "nbr d'occurrences = " << n << endl;
	}
//	{
//		const char* TAB[] = {"Paul", "Jacques", "Paul", "Jean", "Paul"};
//		const size_t TAILLE = sizeof(TAB) / sizeof(const char*);
//		const char* prenom = "Paul";
//		size_t n = nbOcc(TAB, TAILLE, prenom);
//		cout << "nbr d'occurrences = " << n << endl;
//	}

	return EXIT_SUCCESS;
}
