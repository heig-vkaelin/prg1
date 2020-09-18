//
// Created by Valentin Kaelin on 18.09.20.
//

#include <iostream>
#include <string>

using namespace std;

void ex1_2() {
	cout << "  /////" << endl;
	cout << " +-----+" << endl;
	cout << "(| o o |)" << endl;
	cout << " |  ^  |" << endl;
	cout << " | '-' |" << endl;
	cout << " +-----+" << endl;
}

void ex1_3() {
	cout << "------------------------------------------------" << endl;
	cout << "| Type       |	Nom     | Gaz prin. | Gaz sec. |" << endl;
	cout << "| Tellurique |	Mercure | -         | -        |" << endl;
	cout << "| Tellurique |	Vénus   | CO2       | N2       |" << endl;
	cout << "| Tellurique |	Terre   | N2        | 02       |" << endl;
	cout << "| Tellurique |	Mars    | CO2       | N2       |" << endl;
	cout << "| Gazeuse    |	Jupiter | H2        | He       |" << endl;
	cout << "| Gazeuse    |	Saturne | H2        | He       |" << endl;
	cout << "| Gazeuse    |	Uranus  | H2        | He       |" << endl;
	cout << "| Gazeuse    |	Neptune | H2        | He       |" << endl;
	cout << "------------------------------------------------" << endl;
}

void ex1_4() {
	string prenom;
	int age;
	int annee_naissance;

	cout << "Entrez votre prenom:" << endl;
	getline(cin, prenom);

	cout << "Entrez votre age:" << endl;
	cin >> age;
	annee_naissance = 2020 - age;

	cout << "Bonjour " << prenom << endl;
	cout << "Vous avez " << age << " ans et vous etes ne(e) en " << annee_naissance
	<<  "." << endl;
}

void ex1_5() {
	/* calculer coutTotalDuTrain = cout du billet simple course
	 * calculer consommationEssence = distance * consommation / 100
	 * calculer coutEssence = consommationEssence * prix du litre d'essence
	 * caculer coutAmortissementVoiture = coûts d'amortisssment * distance
	 * calculer coutTotalVoiture = coutEssence + coutAmortissementVoiture
	 *
	 * si coutTotalDuTrain < coutTotalVoiture
	 * 	choisir train
	 * sinon
	 *  	choisir voiture
	 */
}

void ex1_6() {
	/* calculer solde = solde du compte bancaire initial (10000)
	 * calculer mois = 0
	 * tant que solde > 0
	 *  	calculer intérêts mensuel = (1 + intérêts annuel / 100)^(1/12) - 1) * 100
	 * 	calculer solde = solde * intérêts mensuels
	 *		calculer solde = solde - retrait (500)
	 *		calculer mois = mois + 1
	 *
	 *	afficher la valeur de mois
	 */
}

void ex1_7() {
	/* afficher un message demandant le solde à l'utilisateur
	 * calculer solde = entrée de l'utilisateur
	 * afficher un message demandant le taux d'intérêt annuel
	 * calculer intérêt annuel = entrée de l'utilisateur
	 * afficher un message demandant le retrait mensuel
	 * calculer retrait mensuel = entrée de l'utilisateur
	 * calculer mois = 0
	 * tant que solde > 0
	 *  	calculer intérêts mensuel = (1 + intérêts annuel / 100)^(1/12) - 1) * 100
	 * 	calculer solde = solde * intérêts mensuels
	 *		calculer solde = solde - retrait mensuel
	 *		calculer mois = mois + 1
	 *
	 *	afficher la valeur de mois
	 */
}
