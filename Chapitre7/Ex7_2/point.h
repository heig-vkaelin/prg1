//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_POINT_7_2_H
#define PRG1_EXERCICES_POINT_7_2_H

namespace Ex7_2 {
	class Point {
	public:
		Point(float x, float y);

		void translation(float deplacementX, float deplacementY);

		float getAbscisse() const;

		float getOrdonnee() const;

	private:
		float coordX;
		float coordY;
	};
}

#endif // PRG1_EXERCICES_POINT_7_2_H
