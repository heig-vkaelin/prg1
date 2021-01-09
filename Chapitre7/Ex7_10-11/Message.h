//
// Created by Valentin on 22.12.2020.
//

#ifndef PRG1_EXERCICES_MESSAGE_7_10_H
#define PRG1_EXERCICES_MESSAGE_7_10_H

#include <ctime>
#include <string>
#include <vector>

using TexteMessage = std::vector<std::string>;

class Message {
public:
	Message(const std::string &expediteur, const std::string &destinataire);

	void ajouter(const std::string &ligneTexte);

	std::string toString() const;

	void afficher() const;

	Message& operator=(const Message& message);
	bool operator==(const Message& msg) const;

private:
	const std::time_t dateCreation;
	const std::string expediteur, destinataire;
	TexteMessage texteMessage;
};

#endif // PRG1_EXERCICES_MESSAGE_7_10_H
