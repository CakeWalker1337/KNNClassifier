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

bool areEqualGroups(Group* g1, Group* g2);