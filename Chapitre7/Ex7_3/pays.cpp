//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include "pays.h"

using namespace std;
using namespace Ex7_3;

Pays::Pays(const std::string &n, unsigned h, double s) {
	nom = n;
	nbHabitants = h;
	superficie = s;
}

int ex7_3() {
	vector<Pays> pays = {
		Pays("Suisse", 7000000, 41285),
		Pays("Russie", 144500000, 17100000),
		Pays("USA", 328200000, 9834000),
	};

	cout << "Plus grande superficie: "
		  << (*max_element(
			  pays.begin(),
			  pays.end(),
			  [](const Pays &p1, const Pays &p2) {
				  return p1.superficie < p2.superficie;
			  })).nom << endl;

	cout << "Plus grande population: " << (*max_element(
		pays.begin(),
		pays.end(),
		[](const Pays &p1, const Pays &p2) {
			return p1.nbHabitants < p2.nbHabitants;
		})).nom << endl;

	cout << "Plus grande densité: " << (*max_element(
		pays.begin(),
		pays.end(),
		[](const Pays &p1, const Pays &p2) {
			return (p1.nbHabitants / p1.superficie) < (p2.nbHabitants / p2.superficie);
		})).nom << endl;

	return EXIT_SUCCESS;
}
