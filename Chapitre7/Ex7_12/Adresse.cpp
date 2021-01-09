//
// Created by Valentin on 22.12.2020.
//

#include "Adresse.h"

using namespace std;

ostream &operator<<(ostream &os, const Adresse &obj) {
	return os << obj.nomRue << " " << obj.noRue << endl
				 << obj.npa << " " << obj.localite;
}

Adresse::Adresse(const string &nomRue, const string &noRue, unsigned npa,
					  const string &localite)
	: nomRue(nomRue), noRue(noRue), localite(localite), npa(npa) {
}
