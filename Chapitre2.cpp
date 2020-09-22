//
// Created by Valentin Kaelin on 18.09.20.
//
#include <iostream>

using namespace std;

void ex2_4() {
	cout << "signed char (" << sizeof(signed char) * 8 << " bits) : " << SCHAR_MIN <<
		  " .. " << SCHAR_MAX << endl;

	cout << "char (" << sizeof(char) * 8 << " bits) : " << SHRT_MIN << " .. " <<
		  SHRT_MAX << endl;

	cout << "int (" << sizeof(int) * 8 << " bits) : " << INT_MIN << " .. " <<
		  INT_MAX << endl;

	cout << "long (" << sizeof(long) * 8 << " bits) : " << LONG_MIN << " .. " <<
		  LONG_MAX << endl;

	cout << "long long (" << sizeof(long long) * 8 << " bits) : " << LONG_LONG_MIN
		  << " .. " << LONG_LONG_MAX << endl;
}
