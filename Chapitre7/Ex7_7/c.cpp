//
// Created by Valentin on 17.12.2020.
//

#include <cstdlib>
#include <iostream>

using namespace std;

namespace Ex7_7 {
	class C {
		friend ostream &operator<<(ostream &lhs, const C &rhs) {
			lhs << "n = " << rhs.n;
			return lhs;
		};

		friend bool operator==(const C &lhs, const C &rhs) { return lhs.n == rhs.n; }

		friend bool operator!=(const C &lhs, const C &rhs) { return !(lhs == rhs); }

		friend C operator+(C lhs, const C &rhs) {
			lhs += rhs;
			return lhs;
		}

	public:
		C() : C(0) {}

		C(int n) : n(n) {};

		C &operator++() {
			++n;
			return *this;
		}

		C operator++(int) {
			C temp = *this;
			++*this;
			return temp;
		}

		C &operator+=(const C &rhs) {
			n += rhs.n;
			return *this;
		}

	private:
		int n;
	};
}

using namespace Ex7_7;

int ex7_7() {
	C c0, c1(1), c2 = 5;
	const C C3{7};

	cout << c0 << endl
		  << c1 << endl;

	cout << boolalpha;
	cout << (c0 == c1) << endl;
	cout << (c0 != c1) << endl;
	cout << noboolalpha;

	cout << c1++ << endl;
	cout << c1 << endl;
	cout << ++c1 << endl;

	cout << c1 + c2 << endl;
	c1 += c2;
	cout << c1 << endl;
	cout << C3 + c2 << endl;

	return EXIT_SUCCESS;
}
