#pragma once
#include <stdarg.h>
#include "math.h"

struct Vector {
	double* components;
	int size;
};

bool areEqualVectors(Vector v1, Vector v2);
Vector createVectorFromArray(int size, ...);
Vector getVectorSum(Vector v1, Vector v2);
Vector getVectorDif(Vector v1, Vector v2);