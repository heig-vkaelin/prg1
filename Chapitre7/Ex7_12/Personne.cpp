//
// Created by Valentin on 22.12.2020.
//

#include "Personne.h"

using namespace std;

ostream &operator<<(ostream &os, const Personne &obj) {
	string strHobbies = "[";
	for (size_t i = 0; i < obj.hobbies.size(); ++i) {
		if (i > 0) { strHobbies += ", "; }
		strHobbies += HOBBIES[(int) obj.hobbies[i]];
	}
	strHobbies += "]";

	string strAmis = "[";
	for (size_t i = 0; i < obj.amis.size(); ++i) {
		if (i > 0) { strAmis += ", "; }
		strAmis += obj.amis[i]->prenom + " " + obj.amis[i]->nom;
	}
	strAmis += "]";

	os << obj.prenom << " " << obj.nom << endl << obj.adresse << endl
		<< "Hobbies : " << strHobbies << "\n"
		<< "Ami(e)s : " << strAmis;

	return os;
}

Personne::Personne(const string &nom, const string &prenom, const Adresse &adresse,
						 const Hobbies &hobbies, const Amis &amis)
	: nom(nom), prenom(prenom), adresse(adresse), hobbies(hobbies) {
	ajouterAmis(amis);
}

void Personne::ajouterHobbies(const Hobbies &hobbies) {
	this->hobbies.insert(this->hobbies.end(), hobbies.begin(), hobbies.end());
}

void Personne::ajouterAmis(const Amis &amis) {
	for (Ami *ami : amis) {
		this->amis.push_back(ami);
		ami->amis.push_back(this);
	}
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
