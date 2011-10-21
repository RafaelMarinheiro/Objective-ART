#pragma once

#include "Marker.h"
#include "Pattern.h"

namespace oart{
	class MarkerTracker
	{
	public:
		MarkerTracker(void);
		~MarkerTracker(void);

		Marker * detectMarkers(unsigned char * image, int thresh);
		int assignMarkers(int numberOfPatterns, Pattern * pattern);

	private:
		int numDetectedMarkers;
		Marker * mdetectedMarkers;
	};
}

