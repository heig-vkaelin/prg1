//
// Created by Valentin on 21.01.2021.
//

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

namespace Ex9_10 {
	using ullong = unsigned long long;

	class Argument_Non_Valide : public logic_error {
	public:
		explicit Argument_Non_Valide(const string &what_arg)
			: logic_error(what_arg) {};

		explicit Argument_Non_Valide(const char *&what_arg)
			: logic_error(what_arg) {};
	};

	class Debordement : public runtime_error {
	public:
		explicit Debordement(const string &what_arg) : runtime_error(what_arg) {}

		explicit Debordement(const char *what_arg) : runtime_error(what_arg) {}
	};

	int sommeNPremiersEntiers(int n) {
		if (n < 0) {
			throw Argument_Non_Valide("Argument non valide: n doit etre >= 0");
		}
		const ullong SOMME = (ullong) n * ((ullong) n + 1) / 2;
		if (SOMME > numeric_limits<int>::max()) {
			throw Debordement("Un debordement est survenu dans les calculs");
		}
		return (int) SOMME;
	}

	void test(int n) {
		cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
		try {
			cout << " = " << sommeNPremiersEntiers(n) << endl;
		} catch (const exception &e) {
			cout << ": " << e.what() << endl;
		}
	}
}

using namespace Ex9_10;

int ex9_10() {
	test(-1);
	test(0);
	test(1);
	test(65535);
	test(65536);

	return EXIT_SUCCESS;
}
