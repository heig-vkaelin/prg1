//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_PAYS_H
#define PRG1_EXERCICES_PAYS_H

#include <string>

namespace Ex7_3 {
	class Pays {
	public:
		// Constructeur
		Pays(const std::string &nom, double population, unsigned superficie);

		// Sélecteurs
		std::string getNom() const;

		double getPopulation() const;

		unsigned getSuperficie() const;

		// Modificateurs
		void setNom(const std::string &nom);

		void setPopulation(double population);

		void setSuperficie(unsigned superficie);

		// Autres
		double densitePopulation() const;

	private:
		std::string nom;
		double population; // en mio d'habitants
		unsigned superficie; // en km2
	};
}

#endif // PRG1_EXERCICES_PAYS_H
