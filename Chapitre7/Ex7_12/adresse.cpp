//
// Created by Valentin on 22.12.2020.
//

#include "adresse.h"

using namespace std;

Adresse::Adresse(const string &nom, const string &numero, int codePostal,
					  const string &localite)
	: nom(nom), numero(numero), localite(localite), codePostal(codePostal) {
}

string Adresse::toString() const {
	return nom + " " + numero + "\n" + to_string(codePostal) + " " + localite;
}
