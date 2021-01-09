//
// Created by Valentin on 22.12.2020.
//

#ifndef PRG1_EXERCICES_PERSONNE_7_12_H
#define PRG1_EXERCICES_PERSONNE_7_12_H

#include <string>
#include <vector>
#include "Adresse.h"
#include "hobby.h"

using Hobbies = std::vector<Hobby>;

class Personne;

using Ami = Personne;
using Amis = std::vector<Ami *>;

class Personne {
	friend std::ostream &operator<<(std::ostream &os, const Personne &obj);

public:
	Personne(const std::string &nom, const std::string &prenom,
				const Adresse &adresse, const Hobbies &hobbies = {},
				const Amis &amis = {});

	void ajouterHobbies(const Hobbies &hobbies);

	void ajouterAmis(const Amis &amis);

private:
	std::string nom, prenom;
	Adresse adresse;
	Hobbies hobbies;
	Amis amis;
};

#endif // PRG1_EXERCICES_PERSONNE_7_12_H
