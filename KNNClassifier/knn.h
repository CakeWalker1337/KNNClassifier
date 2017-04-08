#pragma once
#include "vec.h"

struct Sample
{
	Vector* position;
	char label[32];
};

bool areEqualSamples(Sample* s1, Sample* s2);
Sample* createSampleFromString(char* line, int vectorSize);
char** splitString(char* line, int pieces);
Sample** readDataFromFile(char* filename, int* size);