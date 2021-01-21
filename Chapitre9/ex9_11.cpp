//
// Created by Valentin on 21.01.2021.
//

#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

using namespace std;

namespace Ex9_11 {
	using ullong = unsigned long long;

	unsigned sommeNPremiersEntiers(unsigned n) {
		const ullong SOMME = (ullong) n * ((ullong) n + 1) / 2;
		if (SOMME > numeric_limits<unsigned>::max()) {
			throw overflow_error("Un debordement est survenu dans les calculs");
		}
		return (unsigned) SOMME;
	}

	void test(unsigned n) {
		cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
		try {
			cout << " = " << sommeNPremiersEntiers(n) << endl;
		} catch (const exception &e) {
			cout << ": " << e.what() << endl;
		}
	}
}

using namespace Ex9_11;

int ex9_11() {
	test(-1);
	test(0);
	test(1);
	test(65535);
	test(65536);
	test(92681);
	test(92682);

	return EXIT_SUCCESS;
}
