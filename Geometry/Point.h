// Point.h
#pragma once

namespace oart {
	class Point
	{
	public:
		double x;
		double y;

		Point();
		Point(double x, double y);
		Point(const Point & v);
		Point & operator=(const Point& v);

		~Point();

		Point & operator+(const Point & v) const;
		Point & operator+=(const Point & v);
		Point & operator-(const Point & v) const;
		Point & operator-=(const Point & v);

		//Scalar product
		const double operator*(const Point & v) const;

		const bool operator==(const Point & v) const;
		const bool operator!=(const Point & v) const;

		const double norm() const;
	};
}