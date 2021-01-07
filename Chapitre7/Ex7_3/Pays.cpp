//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Pays.h"

using namespace std;
using namespace Ex7_3;

Pays::Pays(const std::string &nom, double population, unsigned superficie)
	: nom(nom), population(population), superficie(superficie) {
}

string Pays::getNom() const {
	return nom;
}

double Pays::getPopulation() const {
	return population;
}

unsigned Pays::getSuperficie() const {
	return superficie;
}

void Pays::setNom(const std::string &nom) {
	this->nom = nom;
}

void Pays::setPopulation(double population) {
	this->population = population;
}

void Pays::setSuperficie(unsigned int superficie) {
	this->superficie = superficie;
}

double Pays::densitePopulation() const {
	return population * 1E6 / superficie;
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

bool compareSuperficie(const Pays &pays1, const Pays &pays2) {
	return pays1.getSuperficie() < pays2.getSuperficie();
}

bool comparePopulation(const Pays &pays1, const Pays &pays2) {
	return pays1.getPopulation() < pays2.getPopulation();
}

bool compareDensitePopulation(const Pays &pays1, const Pays &pays2) {
	return pays1.densitePopulation() < pays2.densitePopulation();
}

int ex7_3() {
	vector<Pays> pays = {
		Pays("Suisse", 8.121830, 41290),
		Pays("France", 66.663766, 547030),
		Pays("Italie", 61.855120, 301230),
		Pays("Allemagne", 80.854408, 357021),
	};

	cout << "Plus grande superficie: "
		  << max_element(pays.begin(), pays.end(), compareSuperficie)->getNom()
		  << endl;

	cout << "Plus grande population: "
		  << max_element(pays.begin(), pays.end(), comparePopulation)->getNom()
		  << endl;

	cout << "Plus grande densité: "
		  << max_element(pays.begin(), pays.end(), compareDensitePopulation)->getNom()
		  << endl;

	return EXIT_SUCCESS;
}
