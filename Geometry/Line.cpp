#include "GeometryAFX.h"
#include "Geometry.h"
#include <cmath>

using namespace oart;

Line::Line()
{
	this->a = 1;
	this->b = 1;
	this->c = 1;
}

Line::Line(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
Line::Line(const Line & l)
{
	this->a = l.a;
	this->b = l.b;
	this->c = l.c;
}

Line & Line::operator=(const Line & l)
{
	if(this == &l){
		return (*this);
	} else{
		this->a = l.a;
		this->b = l.b;
		this->c = l.c;
		return (*this);
	}
}

Line::~Line()
{
	//Using default destructor
}

bool Line::isIn(Point & p, double eps)
{
	double value = this->a * p.x + this->b * p.y + this->c;
	if(abs(value) < eps){
		return true;
	} else{
		return false;
	}
}
