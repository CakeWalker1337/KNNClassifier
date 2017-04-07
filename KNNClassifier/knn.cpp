#include "stdafx.h"
#include <iostream>

#include "knn.h"

using namespace std;

bool areEqualSamples(Sample* s1, Sample* s2)
{
	if (strcmp(s1->label, s2->label) != 0) return false;
	return (areEqualVectors(s1->position, s2->position));
}