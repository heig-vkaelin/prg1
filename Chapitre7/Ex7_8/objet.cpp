//
// Created by Valentin on 22.12.2020.
//

namespace Ex7_8 {
	class Objet {
	public:
		Objet() { numero = ++nb; };

		~Objet() {};

		int no() const { return numero; }

		static int prochainNo() { return nb + 1; }

		static int compteur() { return nb; }

	private:
		static inline int nb = 0;
		int numero;
	};
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>
#include <iostream>

using namespace std;
using namespace Ex7_8;

int ex7_8() {
	Objet o1;
	cout << "Objet 1: " << o1.no() << endl;
	cout << "Prochain numéro: " << o1.prochainNo() << endl;
	cout << "------------------------------------" << endl;

	Objet o2;
	cout << "Objet 1: " << o1.no() << endl;
	cout << "Prochain numéro: " << o1.prochainNo() << endl;
	cout << "Objet 2: " << o2.no() << endl;
	cout << "Prochain numéro: " << o2.prochainNo() << endl;
	cout << "Nombre objets: " << o1.compteur() << endl;
	cout << "Nombre objets: " << Objet::compteur() << endl;

	return EXIT_SUCCESS;
}
