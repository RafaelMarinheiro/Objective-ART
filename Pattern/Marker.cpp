#include "PatternAFX.h"

#include "Marker.h"
#include<cstring>

using namespace oart;

Marker::Marker()
{
	this->id = -1;
	this->area = -1;
	this->direction = -1;
	this->confidenceValue = -1.0;
	this->transformationMatrix = nullptr;
	this->position = Point();
	this->edges = nullptr;
	this->vertex = nullptr;
}

Marker::Marker(int id, int area, int direction, double cf, double **& tm, Point & position, Line *& edge, Point *& vertex){
	this->id = id;
	this->area = area;
	this->direction = direction;
	this->confidenceValue = cf;
	this->transformationMatrix = tm;
	this->edges = new Line[4];
	for(int i = 0; i<4; i++){
		(this->edges)[i] = edge[i];
	}
	this->vertex = vertex;
}

Marker::Marker(Marker & m)
{
	//DoNothing
}

Marker & Marker::operator=(Marker & m)
{
	return (*this);
}