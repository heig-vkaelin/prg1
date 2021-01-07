//
// Created by Valentin on 15.12.2020.
//

#include <cstdlib>
#include <iostream>

using namespace std;

enum class Direction {
	GAUCHE = -1, DROITE = 1
};

class Robot {
public:
	Robot(int posInitiale = 0);

	void faireDemiTour();

	void deplacer(unsigned short nbUnites = 1);

	int getPosition() const;

private:
	Direction direction;
	int position;
};

Robot::Robot(int posInitiale)
	: direction(Direction::DROITE), position(posInitiale) {}

void Robot::faireDemiTour() {
	direction = (Direction) (-(int) direction);
}

void Robot::deplacer(unsigned short nbUnites) {
	position += (int) direction * nbUnites;
}

int Robot::getPosition() const {
	return position;
}

int ex7_4() {
	Robot r1, r2(10);
	cout << "Position courante de r2: " << r2.getPosition() << endl;
	r1.deplacer();
	cout << "Position courante de r1: " << r1.getPosition() << endl;
	r1.deplacer(2);
	cout << "Position courante de r1: " << r1.getPosition() << endl;
	r1.faireDemiTour();
	r1.deplacer(4);
	cout << "Position courante de r1: " << r1.getPosition() << endl;

	return EXIT_SUCCESS;
}
