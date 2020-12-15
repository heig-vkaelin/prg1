//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_PAYS_H
#define PRG1_EXERCICES_PAYS_H

#include <string>

namespace Ex7_3 {
	class Pays {
	public:
		std::string nom;
		unsigned nbHabitants;
		double superficie;

		Pays(const std::string &n, unsigned h, double s);
	};
};

#endif // PRG1_EXERCICES_PAYS_H
