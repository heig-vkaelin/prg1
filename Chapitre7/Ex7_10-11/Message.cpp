//
// Created by Valentin on 22.12.2020.
//

#include <iostream>
#include "Message.h"

using namespace std;

Message::Message(const string &expediteur, const string &destinataire)
	: dateCreation(time(NULL)), expediteur(expediteur), destinataire(destinataire) {
}

void Message::ajouter(const string &ligneTexte) {
	texteMessage.push_back(ligneTexte);
}

string Message::toString() const {
	const string FORMAT = "%d.%m.%Y %H:%M";
	char buffer[256];
	strftime(buffer, sizeof(buffer), FORMAT.c_str(), localtime(&dateCreation));
	string str = "From : " + expediteur + '\n' +
					 "To   : " + expediteur + '\n' +
					 "Date : " + buffer + '\n';
	str += '\n';
	for (const string &s : texteMessage) {
		str += s + '\n';
	}
	return str;
}

void Message::afficher() const {
	cout << toString();
}

Message &Message::operator=(const Message &message) {
	if (this != &message) {
		(time_t &) dateCreation = message.dateCreation;
		(string &) expediteur = message.expediteur;
		(string &) destinataire = message.destinataire;
		texteMessage = message.texteMessage;
	}
	return *this;
}

bool Message::operator==(const Message &msg) const {
	return dateCreation == msg.dateCreation &&
			 expediteur == msg.expediteur &&
			 destinataire == msg.destinataire &&
			 texteMessage == msg.texteMessage;
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>

int ex7_10() {
	Message msg("Pierre Burki", "Alfred Strohmeier");
	msg.ajouter("Cher ami, ");
	msg.ajouter("RDV demain a 9h.");
	msg.ajouter("Meilleures salutations.");
	msg.ajouter("\nPierre");
	msg.afficher();

	return EXIT_SUCCESS;
}
