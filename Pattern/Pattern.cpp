#include "PatternAFX.h"

#include "Pattern.h"
#include <cstring>

using namespace oart;

Pattern::Pattern()
{
	this->mid = 0;
	this->name = nullptr;
	this->visible = false;
	this->colliding = false;
	this->mwidth = 0;
	this->mcenter = Point();
	this->marker = nullptr;
}

Pattern::Pattern(int id, char * name, double width, Point & center)
{
	this->mid = id;
	int size = strlen(name);
	strcpy_s(this->name, size, name);
	this->mwidth = width;
	this->mcenter = center;
	this->visible = false;
	this->colliding = false;
	this->marker = nullptr;
}

Pattern::Pattern(Pattern & p)
{
	this->mid = p.id();
	int size = strlen(p.name);
	strcpy_s(this->name, size, p.name);
	this->mwidth = p.width();
	this->mcenter = p.center();
	this->visible = p.visible;
	this->colliding = p.colliding;
	this->marker = new Marker();
	(*(this->marker)) = (*(p.marker));
}

Pattern & Pattern::operator=(const Pattern & p)
{
	if(this == &p){
		return (*this);
	} else{
		this->mid = p.id();
		int size = strlen(p.name);
		strcpy_s(this->name, size, p.name);
		this->mwidth = p.width();
		this->mcenter = p.center();
		this->visible = p.visible;
		this->colliding = p.colliding;
		this->marker = new Marker();
		(*(this->marker)) = (*(p.marker));
		return (*this);
	}
}

Pattern::~Pattern()
{
	delete[] this->name;
	delete[] this->marker;
}

const int & Pattern::id() const
{
	return this->mid;
}

const double & Pattern::width() const
{
	return this->mwidth;
}

const Point & Pattern::center() const
{
	return this->mcenter;
}