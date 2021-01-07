//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_POINT_7_5_H
#define PRG1_EXERCICES_POINT_7_5_H

namespace Ex7_5 {
	class Point {
	public:
		Point(float x = 0.f, float y = 0.f);

		void deplacer(float dx, float dy);

		float abscisse() const;

		float ordonnee() const;

		Point operator+(const Point &p) const;

	private:
		float x, y;
	};
}

#endif // PRG1_EXERCICES_POINT_7_5_H
