//
// Created by Valentin on 22.12.2020.
//

#ifndef PRG1_EXERCICES_ADRESSE_7_12_H
#define PRG1_EXERCICES_ADRESSE_7_12_H

#include <string>

class Adresse {
public:
	Adresse(const std::string &nom, const std::string &numero, int codePostal,
			  const std::string &localite);

	std::string toString() const;

private:
	std::string nom, numero, localite;
	int codePostal;
};

#endif // PRG1_EXERCICES_ADRESSE_7_12_H
