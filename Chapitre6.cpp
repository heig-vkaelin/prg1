//
// Created by Valentin on 03.12.2020.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

string vraiFaux(bool b) { return b ? "vrai" : "faux"; }

int ex6_1() {
	unsigned char c;
	cout << "Entrez un caractere :";
	cin >> c;

	cout << endl
		  << "Code ASCII de '" << c << "'"
		  << setw(21) << ": " << (int) c << endl
		  << "'" << c << "' est une lettre de l'alphabet"
		  << setw(6) << ": " << vraiFaux(isalpha(c)) << endl
		  << "'" << c << "' est une lettre minuscule"
		  << setw(10) << ": " << vraiFaux(islower(c)) << endl
		  << "'" << c << "' est un chiffre"
		  << setw(20) << ": " << vraiFaux(isdigit(c)) << endl
		  << "'" << c << "' est un caractere de ponctuation"
		  << setw(3) << ": " << vraiFaux(ispunct(c)) << endl;

	return EXIT_SUCCESS;
}

string milieu(const string &str) {
	size_t TAILLE = str.length();
	return TAILLE == 0 ? str : str.substr((TAILLE - 1) / 2, 2 - TAILLE % 2);
}

int ex6_7() {
	cout << milieu("") << endl;
	cout << milieu("ABC") << endl;
	cout << milieu("ABCD") << endl;

	return EXIT_SUCCESS;
}

int nombreRomainEnDecimal(const string &romain) {
	int decimal = 0;
	map<char, int> valRomaines = {{'I', 1},
											{'V', 5},
											{'X', 10},
											{'L', 50},
											{'C', 100},
											{'D', 500},
											{'M', 1000}};

	for (size_t i = 0; i < romain.length(); i++) {
		int val = valRomaines[romain[i]];
		decimal += valRomaines[romain[i + 1]] <= val ? val : val * -1;
	}
	return decimal;
}

int ex6_9() {
	string exemple = "XIV";
	cout << exemple << " -> " << nombreRomainEnDecimal(exemple) << endl;

	return EXIT_SUCCESS;
}

int ex6_10() {
	const unsigned W = 20;
	int n;
	cout << "Entrez un nombre entier >= 0 :";
	cin >> n;

	string s = to_string(n);

	cout << endl
		  << left << setw(W) << "Nombre saisi" << ": " << s << endl
		  << left << setw(W) << "Nombre de chiffres" << ": " << s.length() << endl
		  << left << setw(W) << "Premier chiffre " << ": " << s.front() << endl
		  << left << setw(W) << "Dernier chiffre" << ": " << s.back() << endl;

	return EXIT_SUCCESS;
}

int ex6_11() {
	const unsigned W = 19;
	string prenom, nom;
	cout << "Entrez votre prenom et votre nom :";
	cin >> prenom >> nom;

	string acronyme{prenom.front(), nom.front(), nom.back()};
	transform(acronyme.begin(), acronyme.end(), acronyme.begin(), ::toupper);

	cout << left << setw(W) << "Votre prenom est" << ": " << prenom << endl
		  << left << setw(W) << "Votre nom est" << ": " << nom << endl
		  << left << setw(W) << "Votre acronyme est" << ": " << acronyme << endl;

	return EXIT_SUCCESS;
}

unsigned occurrencesCaractereV1(const string &chaine, char car) {
	unsigned occurrences = 0;
	size_t index = 0;
	while ((index = chaine.find(car, index)) != string::npos) {
		occurrences++;
		index++;
	}
	return occurrences;
}

unsigned occurrencesCaractereV2(const string &chaine, char car) {
	return (unsigned) count(chaine.begin(), chaine.end(), car);
}

int ex6_13() {
	string chaine = "Ceci est une chaine de caractere";
	char caractere = 'e';
	cout << occurrencesCaractereV1(chaine, caractere) << endl;
	cout << occurrencesCaractereV2(chaine, caractere) << endl;

	return EXIT_SUCCESS;
}

int ex6_14() {
	string entree;
	cout << "Entrez le nom et le numero de la rue :";
	getline(cin, entree);

	unsigned pos = (unsigned) distance(
		entree.begin(),
		find_if(entree.begin(), entree.end(), [](char c) { return isdigit(c); })
	);

	cout << "Le nom de la rue est : " << entree.substr(0, pos - 1) << endl;
	cout << "Le no de la rue est  : " << entree.substr(pos) << endl;

	return EXIT_SUCCESS;
}

int ex6_15() {
	const unsigned W = 19;
	string prenom, nom;
	cout << "Entrez votre prenom et votre nom :";
	getline(cin, prenom, ' ');
	getline(cin, nom);

	string acronyme{prenom.front(), nom.front(), nom.back()};
	transform(acronyme.begin(), acronyme.end(), acronyme.begin(), ::toupper);

	cout << left << setw(W) << "Votre prenom est" << ": " << prenom << endl
		  << left << setw(W) << "Votre nom est" << ": " << nom << endl
		  << left << setw(W) << "Votre acronyme est" << ": " << acronyme << endl;

	return EXIT_SUCCESS;
}

int ex6_16() {
	const int MAX_HIVER = 3 * 100 + 20,
		MAX_PRINTEMPS = 6 * 100 + 20,
		MAX_ETE = 9 * 100 + 20,
		MAX_AUTOMNE = 12 * 100 + 20;
	string date, saison;
	cout << "Entrez une date sous la forme jj.mm (par ex 31.12) :";
	cin >> date;
	int jour = stoi(date.substr(0, date.find('.')));
	int mois = stoi(date.substr(date.find('.') + 1));

	int dateMois = mois * 100 + jour;
	if (dateMois <= MAX_HIVER) {
		saison = "hiver";
	} else if (dateMois <= MAX_PRINTEMPS) {
		saison = "printemps";
	} else if (dateMois <= MAX_ETE) {
		saison = "ete";
	} else if (dateMois <= MAX_AUTOMNE) {
		saison = "automne";
	} else {
		saison = "hiver";
	}
	cout << "Le " << date << " se situe en " << saison;

	return EXIT_SUCCESS;
}

int ex6_17() {
	const unsigned W = 20;
	int n;
	cout << "Entrez un nombre entier >= 0 :";
	cin >> n;

	stringstream convert;
	convert << n;
	string s = convert.str();

	cout << endl
		  << left << setw(W) << "Nombre saisi" << ": " << s << endl
		  << left << setw(W) << "Nombre de chiffres" << ": " << s.length() << endl
		  << left << setw(W) << "Premier chiffre " << ": " << s.front() << endl
		  << left << setw(W) << "Dernier chiffre" << ": " << s.back() << endl;

	return EXIT_SUCCESS;
}

int lireEntier(int min, int max, const string &msgInvite, const string &msgErreur) {
	int val;
	bool saisieOk;
	do {
		cout << msgInvite;
		if (!(saisieOk = cin >> val && val >= min && val <= max)) {
			cin.clear();
			cout << msgErreur << endl << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!saisieOk);
	return val;
}

int ex6_21() {
	const int BORNE_MIN = 1;
	const int BORNE_MAX = 10;
	const string MSG_INVITE = "Donnez un entier dans l'intervalle [" +
									  to_string(BORNE_MIN) + ", " + to_string(BORNE_MAX) +
									  "] :";
	const string MSG_ERREUR = "Saisie incorrecte. Veuillez SVP recommencer.";

	const int SAISIE = lireEntier(
		BORNE_MIN,
		BORNE_MAX,
		MSG_INVITE,
		MSG_ERREUR
	);
	cout << "L'entier que vous avez saisi est " << to_string(SAISIE) << "." << endl;

	return EXIT_SUCCESS;
}
