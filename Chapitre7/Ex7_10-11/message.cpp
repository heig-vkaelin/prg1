//
// Created by Valentin on 22.12.2020.
//

#include "message.h"
#include <iostream>
#include <ctime>

using namespace std;

Message::Message(const string &expediteur, const string &destinataire)
	: expediteur(expediteur), destinataire(destinataire) {
	time_t tempsActuel;
	time(&tempsActuel);
	char buffer[17];
	strftime(buffer, 17, "%d.%m.%Y %H:%M", localtime(&tempsActuel));
	dateCreation = buffer;
}

void Message::ajouterLigne(const string &ligne) {
	contenu += ligne + '\n';
}

string Message::toString() const {
	return "From : " + expediteur + "\nTo   : " + destinataire + "\nDate : "
			 + dateCreation + " \n\n" + contenu;
}

void Message::afficher() {
	cout << this->toString();
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>

int ex7_10() {
	Message m("Pierre Burki", "Alfred Strohmeier");
	m.ajouterLigne("Cher ami, ");
	m.ajouterLigne("RDV demain a 9h.");
	m.ajouterLigne("Meilleures salutations.");
	m.ajouterLigne("");
	m.ajouterLigne("Pierre");
	m.afficher();

	return EXIT_SUCCESS;
}
