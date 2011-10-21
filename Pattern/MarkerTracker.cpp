#include "MarkerTracker.h"

#include <AR\ar.h>

using namespace oart;

MarkerTracker::MarkerTracker()
{
}


MarkerTracker::~MarkerTracker()
{
	delete[] this->mdetectedMarkers;
}

Marker * MarkerTracker::detectMarkers(unsigned char * image, int thresh)
{
	int number_marker;
	ARMarkerInfo * marker_info;

	int detection = arDetectMarker(image, thresh, &marker_info, &number_marker);
	if(detection < 0){
		//DetectionError
	}
	Marker * markers = new Marker[number_marker];
	for(int i = 0; i < number_marker; i++){
		int id = marker_info[i].id;
		int area = marker_info[i].area;
		int direction = marker_info[i].dir;
		double cf = marker_info[i].cf;
		Line * lines = new Line[4];
		for(int j = 0; j<4; j++){
			lines[j] = Line(marker_info[i].line[j][0], marker_info[i].line[j][1], marker_info[i].line[j][2]);
		}
		Point pos = Point(marker_info[i].pos[0], marker_info[i].pos[1]);
		Point * vert = new Point[4];
		for(int j = 0; j<4; j++){
			vert[j] = Point(marker_info[i].vertex[j][0], marker_info[i].vertex[j][1]);
		}
		Marker m = Marker(id, area, direction, cf, pos, lines, vert);
		markers[i] = m;
		delete[] lines;
		delete[] vert;
	}
	this->mdetectedMarkers = markers;
	this->numDetectedMarkers = number_marker;
	return markers;
}

int MarkerTracker::assignMarkers(int numberOfPatterns, Pattern * pattern)
{
	int matched = 0;
	for(int i = 0 ; i<numberOfPatterns; i++){
		int idealMarker = -1;
		for(int j = 0; j<numDetectedMarkers; j++){
			if(pattern[i].id() == this->mdetectedMarkers[j].id()){
				if(idealMarker == -1){
					idealMarker = j;
				} else{
					if(this->mdetectedMarkers[j].confidenceValue() > this->mdetectedMarkers[idealMarker].confidenceValue()){
						idealMarker = j;
					}
				}
			}
		}
		if(idealMarker == -1){
			pattern[i].marker = nullptr;
		} else{
			this->mdetectedMarkers[idealMarker].setTransformationMatrix(pattern[i]);
			pattern[i].marker = &(this->mdetectedMarkers[idealMarker]);
			matched++;
		}
	}
	return matched;
}
