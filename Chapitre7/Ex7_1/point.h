//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_POINT_7_1_H
#define PRG1_EXERCICES_POINT_7_1_H

namespace Ex7_1 {
	class Point {
	public:
		Point(float x, float y);

		void translation(float deplacementX, float deplacementY);

		void afficher() const;

	private:
		float coordX;
		float coordY;
	};
}

#endif // PRG1_EXERCICES_POINT_7_1_H
