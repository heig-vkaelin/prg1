//
// Created by Valentin on 15.12.2020.
//

#ifndef PRG1_EXERCICES_POINT_7_1_H
#define PRG1_EXERCICES_POINT_7_1_H

namespace Ex7_1 {
	class Point {
	public:
		Point(float x = 0.f, float y = 0.f);

		void deplacer(float dx, float dy);

		void afficher() const;

	private:
		float x, y;
	};
}

#endif // PRG1_EXERCICES_POINT_7_1_H
