#pragma once
#include "vec.h"

struct Sample
{
	Vector* position;
	char label[32];
};

bool areEqualSamples(Sample* s1, Sample* s2);