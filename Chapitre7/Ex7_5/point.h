//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_POINT_7_5_H
#define PRG1_EXERCICES_POINT_7_5_H

namespace Ex7_5 {
	class Point {
	public:
		Point(float x, float y);

		void translation(float deplacementX, float deplacementY);

		float getAbscisse() const;

		float getOrdonnee() const;

		Point operator+(const Point &p) const;

	private:
		float coordX;
		float coordY;
	};
}

#endif // PRG1_EXERCICES_POINT_7_5_H
