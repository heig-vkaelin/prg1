//
// Created by Valentin on 21.01.2021.
//
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Erreur : public runtime_error {
public:
	Erreur(int no, const string &what_arg = "") noexcept
		: runtime_error(what_arg), no(no) {}

	int noErreur() const noexcept { return no; }

private:
	int no;
};

void f() {
	throw Erreur(999, "blablabla...");
}

int ex9_13() {
	try {
		f();
	} catch (const Erreur &e) {
		cout << "L'erreur suivante est survenue:" << endl
			  << " - numero : " << e.noErreur() << endl
			  << " - message: " << e.what() << endl << endl;
	}

	return EXIT_SUCCESS;
}
