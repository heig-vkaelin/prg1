//
// Created by Valentin on 22.12.2020.
//

namespace Ex7_8 {
	class Objet {
	public:
		Objet() { numero = ++nb; };

		~Objet() {};

		unsigned no() const { return numero; }

		static unsigned prochainNo() { return nb + 1; }

		static unsigned compteur() { return nb; }

	private:
		static inline unsigned nb = 0;
		unsigned numero;
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
	cout << "Prochain numero: " << o1.prochainNo() << endl;
	cout << "------------------------------------" << endl;

	Objet o2;
	cout << "Objet 1: " << o1.no() << endl;
	cout << "Prochain numero: " << o1.prochainNo() << endl;
	cout << "Objet 2: " << o2.no() << endl;
	cout << "Prochain numero: " << o2.prochainNo() << endl;
	cout << "Nombre objets: " << o1.compteur() << endl;
	cout << "Nombre objets: " << Objet::compteur() << endl;

	return EXIT_SUCCESS;
}
