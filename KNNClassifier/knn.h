#pragma once
#include "vec.h"

struct Sample
{
	Vector* position;
	char label[32];
};

struct Group {
	int count;
	char label[32];
};
bool areEqualSamples(Sample* s1, Sample* s2);
Sample* createSampleFromString(char* line, int vectorSize);
char** splitString(char* line, int pieces);
Sample** readDataFromFile(char* filename, int* size);
bool areEqualGroups(Group* g1, Group* g2);
int saveDataToFile(char* filename, Sample** samples, int size);
Group** createGroups(Sample** samples, int* groupCounter, int k);