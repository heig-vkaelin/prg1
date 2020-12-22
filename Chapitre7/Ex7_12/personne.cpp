//
// Created by Valentin on 22.12.2020.
//

#include "personne.h"

using namespace std;

string hobbiesToString(const vector<Hobby> &h) {
	string hobbies = "[";
	for (size_t i = 0; i < h.size(); ++i) {
		if (i > 0) { hobbies += ", "; }
		hobbies += NOMS_HOBBY[(int) h[i]];
	}
	hobbies += "]";
	return hobbies;
}

string amisToString(const vector<Personne> &a) {
	string amis = "[";
	for (size_t i = 0; i < a.size(); ++i) {
		if (i > 0) { amis += ", "; }
		amis += a[i].prenom + " " + a[i].nom;
	}
	amis += "]";
	return amis;
}

Personne::Personne(const std::string &nom, const std::string &prenom,
						 const Adresse &adresse, const std::vector<Hobby> &hobbies,
						 const std::vector<Personne *> &amis)
	: nom(nom), prenom(prenom), adresse(adresse), hobbies(hobbies) {
	for (Personne *ami : amis) {
		ami->amis.push_back(*this);
		this->amis.push_back(*ami);
	}
}

void Personne::ajouterHobbies(const std::vector<Hobby> &nouveauxHobbies) {
	this->hobbies
		.insert(this->hobbies.end(), nouveauxHobbies.begin(), nouveauxHobbies.end());
}

void Personne::ajouterAmis(const vector<Personne *> &nouveauxAmis) {
	for (Personne *ami : nouveauxAmis) {
		ami->amis.push_back(*this);
		amis.push_back(*ami);
	}
}

ostream &operator<<(ostream &lhs, const Personne &rhs) {
	lhs << rhs.prenom << " " << rhs.nom << "\n"
		 << rhs.adresse.toString() << "\n"
		 << "Hobbies : " << hobbiesToString(rhs.hobbies) << "\n"
		 << "Ami(e)s : " << amisToString(rhs.amis);
	return lhs;
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>
#include <iostream>

int ex7_12() {
	Adresse a1 = {"Chemin des Lilas", "7A", 1400, "Yverdon-les-Bains"},
		a2 = {"Avenue des sports", "18", 1000, "Lausanne"},
		a3 = {"Rue des Acacias", "21", 1800, "Vevey"};

	Personne p1 = {"Ecoffey", "Paul", a1, {Hobby::MUSIQUE}},
		p2 = {"Grandjean", "Alexandre", a2, {}, {&p1}},
		p3 = {"Ducotterd", "Julie", a3, {Hobby::SPORT, Hobby::CINEMA}};

	p1.ajouterHobbies({Hobby::CINEMA, Hobby::LECTURE});
	p1.ajouterAmis({&p3});

	cout << p1 << endl << endl;
	cout << p2 << endl << endl;
	cout << p3 << endl << endl;

	return EXIT_SUCCESS;
}
