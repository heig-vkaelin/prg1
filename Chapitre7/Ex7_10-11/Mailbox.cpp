//
// Created by Valentin on 22.12.2020.
//

#include <vector>
#include <algorithm>
#include "Message.h"

using namespace std;

class Mailbox {
public:
	void ajouterMessage(const Message &message);

	void supprimerMessage(size_t i);

	Message getMessage(size_t i) const;

	size_t nbMessages() const;

private:
	vector<Message> messages;
};

void Mailbox::ajouterMessage(const Message &message) {
	if (find(messages.begin(), messages.end(), message) == messages.end()) {
		messages.push_back(message);
	}
}

void Mailbox::supprimerMessage(size_t i) {
	if (!messages.empty() && i < messages.size()) {
		messages.erase(messages.begin() + (int) i);
	}
}

Message Mailbox::getMessage(size_t i) const {
	return messages.at(i);
}

size_t Mailbox::nbMessages() const {
	return messages.size();
}

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>
#include <iostream>

void afficher(const Mailbox &mbx) {
	cout << "---- Contenu Mailbox ----" << endl;
	for (size_t i = 0; i < mbx.nbMessages(); ++i) {
		Message msg = mbx.getMessage(i);
		cout << "-- Message #" << i + 1 << endl;
		msg.afficher();
		cout << endl;
	}
}

int ex7_11() {
	Message msg1("A", "B"),
		msg2("C", "D");

	msg1.ajouter("Blabla from A to B");
	msg2.ajouter("Blabla from C to D");

	Mailbox mbx;
	mbx.supprimerMessage(0); // sans effet
	mbx.ajouterMessage(msg1);
	mbx.ajouterMessage(msg2);
	cout << "Nb de messages : " << mbx.nbMessages() << endl;

	mbx.ajouterMessage(msg1); // ajout doublon impossible
	cout << "Nb de messages : " << mbx.nbMessages() << endl << endl;

	mbx.supprimerMessage(2); // sans effet
	afficher(mbx);

	return EXIT_SUCCESS;
}
