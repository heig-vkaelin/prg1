//
// Created by Valentin on 22.12.2020.
//

#ifndef PRG1_EXERCICES_MESSAGE_7_10_H
#define PRG1_EXERCICES_MESSAGE_7_10_H

#include <string>

class Message {
public:
	Message(const std::string &expediteur, const std::string &destinataire);

	void ajouterLigne(const std::string &ligne);

	std::string toString() const;

	void afficher();

private:
	std::string expediteur, destinataire, dateCreation, contenu;
};

#endif // PRG1_EXERCICES_MESSAGE_7_10_H
