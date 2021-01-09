//
// Created by Valentin on 22.12.2020.
//

#ifndef PRG1_EXERCICES_ADRESSE_7_12_H
#define PRG1_EXERCICES_ADRESSE_7_12_H

#include <string>
#include <iostream>

class Adresse {
	friend std::ostream &operator<<(std::ostream &os, const Adresse &obj);

public:
	Adresse(const std::string &nomRue, const std::string &noRue, unsigned npa,
			  const std::string &localite);

private:
	std::string nomRue, noRue, localite;
	unsigned npa;
};

#endif // PRG1_EXERCICES_ADRESSE_7_12_H
