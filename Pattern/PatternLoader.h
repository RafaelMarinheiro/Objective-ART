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

		const int & numberOfLoadedPatterns() const;
		const Pattern * loadedPatterns() const;

		Pattern * loadPatterns();

	private:
		int numberPatterns;
		char * filePath;
		Pattern * mloadedPatterns;
	};
}

