#pragma once
#include <stdarg.h>

struct Vector {
	double* components;
	int size;
};

bool areEqualVectors(Vector v1, Vector v2);
Vector createVectorFromArray(int size, ...);