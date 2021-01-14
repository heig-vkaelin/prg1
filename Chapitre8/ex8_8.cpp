//
// Created by Valentin on 14.01.2021.
//

#include <cstdlib>
#include <iostream>

using namespace std;

namespace Ex8_8 {

	template<typename T, size_t n>
	class Array;

	template<typename T, size_t n>
	ostream &operator<<(ostream &os, const Array<T, n> &a);

	// Surcharge ici pour le type bool
	template<size_t n>
	ostream &operator<<(ostream &os, const Array<bool, n> &a);

	template<typename T, size_t n>
	class Array {
		friend ostream &operator<< <>(ostream &os, const Array &a);

	public:
		Array(const T &valeur);

	private:
		T tab[n];
	};

	template<typename T, size_t n>
	ostream &operator<<(ostream &os, const Array<T, n> &a) {
		os << "[";
		for (size_t i = 0; i < n; ++i) {
			if (i > 0) { os << ", "; }
			os << a.tab[i];
		}
		return os << "]";
	}

	template<size_t n>
	ostream &operator<<(ostream &os, const Array<bool, n> &a) {
		os << "[" << boolalpha;
		for (size_t i = 0; i < n; ++i) {
			if (i > 0) { os << ", "; }
			os << a.tab[i];
		}
		return os << "]" << noboolalpha;
	}

	template<typename T, size_t n>
	Array<T, n>::Array(const T &valeur) {
		for (T &elem : tab) {
			elem = valeur;
		}
	}
}

using namespace Ex8_8;

int ex8_8() {
	Array<int, 3> a1(1);
	cout << a1 << endl;
	Array<double, 4> a2(1.5);
	cout << a2 << endl;
	Array<bool, 5> a3(true);
	cout << a3 << endl;
	return EXIT_SUCCESS;
}
