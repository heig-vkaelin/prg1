//
// Created by Valentin on 22.12.2020.
//

#include <iostream>

using namespace std;

class Objet {
	friend ostream &operator<<(ostream &os, const Objet &obj);

public:
	Objet();

	Objet(const Objet &);

	Objet &operator=(const Objet &);

	~Objet();

	unsigned no() const;

	static unsigned prochainNo();

	static unsigned compteur();

private:
	const unsigned _no;
	static unsigned _prochainNo;
	static unsigned _compteur;
};

ostream &operator<<(ostream &os, const Objet &obj) {
	return os << "Affichage objet #" << obj._no;
}

Objet::Objet() : _no(_prochainNo) {
	cout << "Constructeur objet #" << _no << endl;
	++_prochainNo;
	++_compteur;
}

Objet::Objet(const Objet &) : Objet() {} // crée un nouvel objet au lieu de copier

Objet &Objet::operator=(const Objet &) {
	cout << "Affectation dans objet #" << _no << endl;
	return *this; // ne fait rien, renvoie l'objet lvalue
}

Objet::~Objet() {
	cout << "Destructeur objet #" << _no << endl;
	--_compteur;
}

unsigned Objet::no() const {
	return _no;
}

unsigned Objet::prochainNo() {
	return _prochainNo;
}

unsigned Objet::compteur() {
	return _compteur;
}

unsigned Objet::_prochainNo = 1;
unsigned Objet::_compteur = 0;

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>

void afficherEtatClasseObjet() {
	cout << "\nClasse Objet : "
		  << Objet::compteur()
		  << (Objet::compteur() > 1 ? " objets vivants" : " objet vivant")
		  << ", prochain numero : " << Objet::prochainNo()
		  << endl << endl << flush;
}

int ex7_8() {
	afficherEtatClasseObjet();
	const Objet OBJ;
	cout << OBJ << endl;
	afficherEtatClasseObjet();
	for (int i = 1; i <= 3; ++i) {
		Objet obj;
		cout << obj << endl;
		afficherEtatClasseObjet();
	}
	afficherEtatClasseObjet();
	Objet o1;
	cout << o1 << endl;
	afficherEtatClasseObjet();
	Objet o2(o1);
	cout << o2 << endl;
	afficherEtatClasseObjet();
	o1 = o2;
	cout << o1 << endl;
	afficherEtatClasseObjet();

	return EXIT_SUCCESS;
}
