#include <iostream>
#include "vec.h"

bool areEqualVectors(Vector left, Vector right)
{
	if (left.size != right.size) return false;

	for (int i = 0; i < left.size; i++)
	{
		if (left.components[i] != right.components[i]) return false;
	}
	return true;
}