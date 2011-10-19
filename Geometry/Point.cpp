#include "Point.h"
#include <math.h>

using namespace oart;

Point::Point()
{
	this->x = 0.0;
	this->y = 0.0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point & v)
{
	this->x = v.x;
	this->y = v.y;
}

Point & Point::operator=(const Point & v)
{
	if(this == &v){
		return (*this);
	} else{
		this->x = v.x;
		this->y = v.y;
		return (*this);
	}
}

Point::~Point()
{
	//Using default destructor
}

Point & Point::operator+(const Point & v) const
{
	Point * p = new Point();
	p->x = this->x + v.x;
	p->y = this->y + v.y;
	return (*p);
}

Point & Point::operator+=(const Point & v)
{
	this->x += v.x;
	this->y += v.y;
	return (*this);
}

Point & Point::operator-(const Point & v) const
{
	Point * p = new Point();
	p->x = this->x - v.x;
	p->y = this->y - v.y;
	return (*p);
}

Point & Point::operator-=(const Point & v)
{
	this->x -= v.x;
	this->y -= v.y;
	return (*this);
}

const double Point::operator*(const Point & v) const
{
	const double ret = this->x * v.x + this->y * v.y;
	return ret;
}

const bool Point::operator==(const Point & v) const
{
	if(this->x == v.x && this->y == v.y){
		return true;
	} else{
		return false;
	}
}

const bool Point::operator!=(const Point & v) const
{
	return !((*this) == v);
}

const double Point::norm() const
{
	return (sqrt((this->x)*(this->x) + (this->y)*(this->y)));
}