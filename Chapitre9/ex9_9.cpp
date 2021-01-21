//
// Created by Valentin on 21.01.2021.
//

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

namespace Ex9_9 {
	using ullong = unsigned long long;

	int sommeNPremiersEntiers(int n) {
		if (n < 0) {
			throw invalid_argument("Argument non valide: n doit etre >= 0");
		}
		const ullong SOMME = (ullong) n * ((ullong) n + 1) / 2;
		if (SOMME > numeric_limits<int>::max()) {
			throw overflow_error("Un debordement est survenu dans les calculs");
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

using namespace Ex9_9;

int ex9_9() {
	test(-1);
	test(0);
	test(1);
	test(65535);
	test(65536);

	return EXIT_SUCCESS;
}
