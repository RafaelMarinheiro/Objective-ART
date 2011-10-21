// Marker.h

#pragma once

#include "PatternAFX.h"
#include "Pattern.h"

namespace oart {
	class Marker
	{
	public:
		Marker();
		Marker(int id, int area, int direction, double cf, Point & position, Line *& edge, Point *& vertex);
		Marker(Marker & m);
		Marker & operator=(Marker & m);

		~Marker();

		const int & id() const;
		const double & confidenceValue() const;
		void setTransformationMatrix(Pattern & p);
		const double * getTransformationMatrix() const;
	private:
		int mid;
		int area;
		int direction;
		double mconfidenceValue;
		double transformationMatrix[3][4];
		Point position;
		Line * edges;
		Point * vertex;
	};
}
