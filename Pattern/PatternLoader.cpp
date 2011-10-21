#include "PatternAFX.h"

#include "PatternLoader.h"

#include <cstring>
#include <cstdio>
#include <AR\ar.h>

using namespace oart;

PatternLoader::PatternLoader(char * filePath)
{
	this->numberPatterns = 0;
	int size = strlen(filePath);
	this->filePath = new char[size];
	strcpy_s(this->filePath, size, filePath);
	this->mloadedPatterns = nullptr;
}

PatternLoader::PatternLoader(PatternLoader & p)
{
	this->numberPatterns = p.numberPatterns;
	int size = strlen(p.filePath);
	this->filePath = new char[size];
	strcpy_s(this->filePath, size, filePath);
	this->mloadedPatterns = p.mloadedPatterns;
}

PatternLoader & PatternLoader::operator=(PatternLoader & p)
{
	if(this == &p){
		return (*this);
	} else{
		this->numberPatterns = p.numberPatterns;
		int size = strlen(p.filePath);
		this->filePath = new char[size];
		strcpy_s(this->filePath, size, filePath);
		this->mloadedPatterns;
		return (*this);
	}
}

PatternLoader::~PatternLoader()
{
	delete[] this->filePath;
}

const int & PatternLoader::numberOfLoadedPatterns() const
{
	return this->numberPatterns;
}

const Pattern * PatternLoader::loadedPatterns() const
{
	return this->mloadedPatterns;
}

Pattern * PatternLoader::loadPatterns()
{
	FILE * input;
	int err = fopen_s(&input, this->filePath, "r");
	if(err != 0){
		//FileNotFoundException
	}
	int numberPatterns;
	fscanf_s(input, "%d", &numberPatterns);
	if(numberPatterns <= 0){
		//InputFormatException
	}
	Pattern * patterns = new Pattern[numberPatterns];
	int id;
	char * name;
	char * path;
	double size;
	double x, y;
	for(int i = 0; i<numberPatterns; i++){
		int r1 = fscanf_s(input, "%s", name);
		int r2 = fscanf_s(input, "%s", path);
		int r3 = fscanf_s(input, "%lf", &size);
		int r4 = fscanf_s(input, "%lf %lf", &x, &y);
		if(r1 != 1 || r2 != 1 || r3 != 1 || r4 != 2){
			delete[] patterns;
			//InputFormatException
		}
		id = arLoadPatt(path);
		if(id < 0){
			delete[] patterns;
			//PatternFormatException
		}
		patterns[i] = Pattern(id, name, size, Point(x, y));
	}
	this->numberPatterns = numberPatterns;
	this->mloadedPatterns = patterns;
	return patterns;
}