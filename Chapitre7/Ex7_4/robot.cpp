//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>

using namespace std;

class Robot {
public:
	Robot() : Robot(0) {}

	Robot(int posInitiale) : position(posInitiale), directionAdroite(true) {};

	void deplacer(unsigned unites = 1);

	int getPosition() const;

	void faireDemiTour();

private:
	int position;
	bool directionAdroite;
};

void Robot::deplacer(unsigned unites) {
	directionAdroite ? position += (int) unites : position -= (int) unites;
}

void Robot::faireDemiTour() {
	directionAdroite = !directionAdroite;
}

int Robot::getPosition() const {
	return position;
}

int ex7_4() {
	Robot r1;
	cout << "Pos initiale: " << r1.getPosition() << endl;
	r1.deplacer();
	cout << "Pos après 1 déplacement: " << r1.getPosition() << endl;
	r1.deplacer(15);
	cout << "Pos après 2 déplacements: " << r1.getPosition() << endl;
	r1.faireDemiTour();
	r1.deplacer(10);
	cout << "Pos après demi tour: " << r1.getPosition() << endl;

	Robot r2(15);
	cout << "Pos initiale différente: " << r2.getPosition() << endl;

	return EXIT_SUCCESS;
}
