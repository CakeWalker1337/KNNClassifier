#include "stdafx.h"
#include <iostream>

#include "knn.h"

using namespace std;

bool areEqualGroups(Group* g1, Group* g2)
{
	if (strcmp(g1->label, g2->label) != 0) return false;
	return (g1->count == g2->count);
}