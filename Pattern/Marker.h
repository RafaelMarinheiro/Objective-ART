// Marker.h

#pragma once

#include "PatternAFX.h"

namespace oart {
	class Marker
	{
	public:
		Marker();
		Marker(int id, int area, int direction, double cf, double **& tm, Point & position, Line *& edge, Point *& vertex);
		Marker(Marker & m);
		Marker & operator=(Marker & m);
	private:
		int id;
		int area;
		int direction;
		double confidenceValue;
		double ** transformationMatrix;
		Point position;
		Line * edges;
		Point * vertex;
	};
}
