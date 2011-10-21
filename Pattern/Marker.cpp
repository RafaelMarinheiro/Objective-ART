#include "PatternAFX.h"

#include "Marker.h"
#include <AR\ar.h>
#include <cstring>

using namespace oart;

Marker::Marker()
{
	this->mid = -1;
	this->area = -1;
	this->direction = -1;
	this->mconfidenceValue = -1.0;
	this->position = Point();
	this->edges = nullptr;
	this->vertex = nullptr;
}

Marker::Marker(int id, int area, int direction, double cf, Point & position, Line *& edge, Point *& vertex){
	this->mid = id;
	this->area = area;
	this->direction = direction;
	this->mconfidenceValue = cf;
	this->position = position;
	this->edges = new Line[4];
	for(int i = 0; i<4; i++){
		(this->edges)[i] = edge[i];
	}
	this->vertex = new Point[4];
	for(int i = 0; i<4; i++){
		(this->vertex)[i] = vertex[i];
	}
}

Marker::Marker(Marker & m)
{
	this->mid = m.id();
	this->area = m.area;
	this->direction = m.direction;
	this->mconfidenceValue = m.confidenceValue();
	for(int i = 0 ; i<3; i++){
		for(int j = 0 ; j<4; j++){
			this->transformationMatrix[i][j] = m.transformationMatrix[i][j];
		}
	}
	this->edges = new Line[4];
	for(int i = 0; i<4; i++){
		(this->edges)[i] = m.edges[i];
	}
	this->vertex = new Point[4];
	for(int i = 0; i<4; i++){
		(this->vertex)[i] = m.vertex[i];
	}
	//DoNothing
}

Marker & Marker::operator=(Marker & m)
{
	if(this == &m){
		return (*this);
	} else{
		this->mid = m.id();
		this->area = m.area;
		this->direction = m.direction;
		this->mconfidenceValue = m.confidenceValue();
		for(int i = 0 ; i<3; i++){
			for(int j = 0 ; j<4; j++){
				this->transformationMatrix[i][j] = m.transformationMatrix[i][j];
			}
		}
		this->edges = new Line[4];
		for(int i = 0; i<4; i++){
			(this->edges)[i] = m.edges[i];
		}
		this->vertex = new Point[4];
		for(int i = 0; i<4; i++){
			(this->vertex)[i] = m.vertex[i];
		}
		return (*this);
	}
}

const int & Marker::id() const
{
	return this->mid;
}

const double & Marker::confidenceValue() const
{
	return this->mconfidenceValue;
}

void Marker::setTransformationMatrix(Pattern & p)
{
	double tm[3][4];
	ARMarkerInfo a;
	a.id = this->mid;
	a.area = this->area;
	a.dir = this->direction;
	a.cf = this->mconfidenceValue;
	for(int i = 0; i<4; i++){
		a.line[i][0] = this->edges[i].a;
		a.line[i][1] = this->edges[i].b;
		a.line[i][2] = this->edges[i].c;
	}
	a.pos[0] = this->position.x;
	a.pos[1] = this->position.y;
	for(int i = 0 ; i<4; i++){
		a.vertex[i][0] = this->vertex[i].x;
		a.vertex[i][1] = this->vertex[i].y;
	}
	double center[2];
	center[0] = p.center().x;
	center[1] = p.center().y;
	arGetTransMat(&a, center, p.width(), tm);
	for(int i = 0 ; i<3; i++){
		for(int j = 0; j<4; j++){
			this->transformationMatrix[i][j] = tm[i][j];
		}
	}
}

Marker::~Marker()
{
	delete[] this->edges;
	delete[] this->vertex;
}