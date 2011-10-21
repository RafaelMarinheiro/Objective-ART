#pragma once
#include "Pattern.h"

namespace oart{

	class PatternLoader
	{
	public:
		PatternLoader(char * filePath);
		PatternLoader(PatternLoader & p);
		PatternLoader & operator=(PatternLoader & p);
		~PatternLoader();

		const int & numberOfPatternsLoaded() const;

		Pattern * loadPatterns();

	private:
		int numberPatterns;
		char * filePath;
	};
}

