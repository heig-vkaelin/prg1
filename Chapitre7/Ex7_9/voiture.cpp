//
// Created by Valentin on 22.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

namespace Ex7_9 {
	class Voiture {
		friend void afficherVoiture(const Voiture &v) {
			const int W = 31;
			cout << left << fixed << setprecision(1)
				  << setw(W) << "Capacite du reservoir [l] " << ": " << v.capacite
				  << endl
				  << setw(W) << "Consommation moyenne [l/100km] " << ": "
				  << v.consommation << endl
				  << setw(W) << "Nb litres restants " << ": " << v.nbLitresActuels
				  << endl << endl;
		}

	public:
		Voiture(int capacite, double consommation)
			: capacite(capacite), consommation(consommation),
			  nbLitresActuels(capacite) {};

		static double getPrixEssence() {
			return prixEssence;
		}

		static void setPrixEssence(double prix) {
			prixEssence = prix;
		}

		double coutTrajet(int km) {
			double litres = consommation * km / 100;

			nbLitresActuels -= litres;
			while (nbLitresActuels <= 0) { nbLitresActuels += capacite; }

			return litres * prixEssence;
		}

	private:
		static inline double prixEssence = 1.5; // prix pour 1 litre

		int capacite; // en litres
		double consommation; // litres pour 100km
		double nbLitresActuels; // nombre de litres restants dans le réservoir
	};
}

using namespace Ex7_9;

void afficherPrix(double val, const string &msg, const string &unite = "Frs",
						int precision = 2) {
	cout << fixed << setprecision(precision)
		  << msg << val << " " << unite << endl << endl;
}

void afficherPrixEssence(double prix) {
	afficherPrix(prix, "Prix de l'essence : ");
}

void afficherCoutTrajet(double coutTrajet) {
	afficherPrix(coutTrajet, "Cout du trajet : ");
}

int ex7_9() {
	afficherPrixEssence(Voiture::getPrixEssence());
	Voiture::setPrixEssence(1.34);
	afficherPrixEssence(Voiture::getPrixEssence());
	Voiture v(52, 6.7);
	afficherVoiture(v);
	afficherCoutTrajet(v.coutTrajet(1000));
	afficherVoiture(v);
	afficherCoutTrajet(v.coutTrajet(200));
	afficherVoiture(v);
	return EXIT_SUCCESS;
}
