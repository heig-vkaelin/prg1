//
// Created by Valentin on 22.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace Ex7_9 {
	class Voiture {
	public:
		Voiture(unsigned capacite, double consommation);

		unsigned getCapaciteReservoir() const;

		double getConsommationMoyenne() const;

		double getNbLitresDansReservoir() const;

		double effectuerTrajet(double nbKm);

		static double getPrixEssence();

		static void setPrixEssence(double prix);

	private:
		static double prixEssence; // en Frs

		unsigned capacite; // en litres
		double consommation; // litres aux 100km
		double nbLitresDansReservoir; // nb de litres actuellement dans le réservoir
	};
}

using namespace Ex7_9;

double Voiture::prixEssence = 1.5;

Voiture::Voiture(unsigned int capacite, double consommation)
	: capacite(capacite), consommation(consommation),
	  nbLitresDansReservoir(capacite) {
}

unsigned Voiture::getCapaciteReservoir() const {
	return capacite;
}

double Voiture::getConsommationMoyenne() const {
	return consommation;
}

double Voiture::getNbLitresDansReservoir() const {
	return nbLitresDansReservoir;
}

double Voiture::effectuerTrajet(double nbKm) {
	const double CONSOMMATION = consommation * nbKm / 100;
	nbLitresDansReservoir -= fmod(CONSOMMATION, capacite);
	if (nbLitresDansReservoir <= 0) {
		nbLitresDansReservoir += capacite;
	}

	// Variante initiale moins efficace mais plus simple à comprendre:
	//	nbLitresDansReservoir -= CONSOMMATION;
	//	while (nbLitresDansReservoir <= 0) { nbLitresDansReservoir += capacite; }

	return CONSOMMATION * prixEssence;
}

double Voiture::getPrixEssence() {
	return prixEssence;
}

void Voiture::setPrixEssence(double prix) {
	prixEssence = prix;
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

void afficherPrixEssence(double prix) {
	cout << fixed << setprecision(2)
		  << "Prix de l'essence : " << prix << " " << " Frs"
		  << endl << endl << defaultfloat;
}

void afficherVoiture(const Voiture &v) {
	const int W = 31;
	cout << left << setw(W) << "Capacite du reservoir [l] " << ": "
		  << fixed << setprecision(1) << v.getCapaciteReservoir() << endl
		  << setw(W) << "Consommation moyenne [l/100km] " << ": "
		  << v.getConsommationMoyenne() << endl
		  << setw(W) << "Nb litres restants " << ": " << v.getNbLitresDansReservoir()
		  << endl << endl << defaultfloat;
}

void afficherCoutTrajet(double montant) {
	cout << fixed << setprecision(2)
		  << "Cout du trajet : " << montant << " " << " Frs"
		  << endl << endl << defaultfloat;
}

int ex7_9() {
	afficherPrixEssence(Voiture::getPrixEssence());
	Voiture::setPrixEssence(1.34);
	afficherPrixEssence(Voiture::getPrixEssence());
	Voiture v(52, 6.7);
	afficherVoiture(v);
	afficherCoutTrajet(v.effectuerTrajet(1000));
	afficherVoiture(v);
	afficherCoutTrajet(v.effectuerTrajet(200));
	afficherVoiture(v);
	return EXIT_SUCCESS;
}
