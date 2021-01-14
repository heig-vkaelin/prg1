//
// Created by Valentin on 14.01.2021.
//

#include <cstdlib>
#include <iostream>

using namespace std;

namespace Ex8_6 {
	template<typename T, size_t n>
	class Array {
	public:
		Array(const T &valeur);

		void afficher() const;

	private:
		T tab[n];
	};

	template<typename T, size_t n>
	Array<T, n>::Array(const T &valeur) {
		for (T &elem : tab) {
			elem = valeur;
		}
	}

	template<typename T, size_t n>
	void Array<T, n>::afficher() const {
		cout << "[";
		for (size_t i = 0; i < n; ++i) {
			if (i > 0) { cout << ", "; }
			cout << tab[i];
		}
		cout << "]";
	}
}

using namespace Ex8_6;

int ex8_6() {
	Array<int, 3> a1(1);
	a1.afficher();
	cout << endl;
	Array<double, 4> a2(1.5);
	a2.afficher();
	cout << endl;
	return EXIT_SUCCESS;
}
