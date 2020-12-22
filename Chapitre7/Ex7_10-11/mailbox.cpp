//
// Created by Valentin on 22.12.2020.
//

#include <vector>
#include <algorithm>
#include "message.h"

class Mailbox {
public:
	void ajouterMessage(const Message &m) {
		if (any_of(messages.begin(), messages.end(), [m](const Message &m1) {
			return m1.toString() == m.toString();
		})) {
			return;
		}
		messages.push_back(m);
	}

	Message &getMessage(size_t i) {
		return messages.at(i);
	}

	void supprimerMessage(unsigned i) {
		if (messages.empty() || i > messages.size() - 1) {
			return;
		}
		messages.erase(messages.begin() + i);
	}

	size_t nbMessages() const {
		return messages.size();
	}

private:
	std::vector<Message> messages;
};

// *************************
// FICHIER MAIN EN DESSOUS
// *************************

#include <cstdlib>
#include <iostream>

using namespace std;

int ex7_11() {
	Mailbox box;
	Message m1("Valentin", "MJ");
	m1.ajouterLigne("Super mon bro continue comme ça.");
	Message m2("Bob", "Daniel");

	cout << "Nb messages: " << box.nbMessages() << endl;
	box.ajouterMessage(m1);
	box.ajouterMessage(m2);
	cout << "Nb messages: " << box.nbMessages() << endl;
	box.ajouterMessage(m2);
	cout << "Nb messages: " << box.nbMessages() << endl;

	cout << "Expediteur msg index 0: " << endl
		  << box.getMessage(0).toString();

	box.supprimerMessage(0);
	cout << "Nb messages: " << box.nbMessages() << endl;
	cout << "Expediteur msg index 0: " << endl
		  << box.getMessage(0).toString();

	return EXIT_SUCCESS;
}
