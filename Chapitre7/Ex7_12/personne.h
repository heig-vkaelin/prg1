//
// Created by Valentin on 22.12.2020.
//

#ifndef PRG1_EXERCICES_PERSONNE_7_12_H
#define PRG1_EXERCICES_PERSONNE_7_12_H

#include <string>
#include <vector>
#include <iostream>
#include "adresse.h"

enum class Hobby {
	SPORT, MUSIQUE, CINEMA, LECTURE
};

const std::string NOMS_HOBBY[] = {"sport", "musique", "cinema", "lecture"};

class Personne {
	friend std::ostream &operator<<(std::ostream &lhs, const Personne &rhs);

	friend std::string amisToString(const std::vector<Personne *> &a);

public:
	Personne(const std::string &nom, const std::string &prenom,
				const Adresse &adresse, const std::vector<Hobby> &hobbies,
				const std::vector<Personne *> &amis = {});

	void ajouterHobbies(const std::vector<Hobby> &nouveauxHobbies);

	void ajouterAmis(const std::vector<Personne *> &nouveauxAmis);

private:
	std::string nom, prenom;
	Adresse adresse;
	std::vector<Hobby> hobbies;
	std::vector<Personne *> amis;
};

#endif // PRG1_EXERCICES_PERSONNE_7_12_H
