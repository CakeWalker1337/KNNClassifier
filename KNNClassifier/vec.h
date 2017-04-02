#pragma once
#include <stdarg.h>
#include "math.h"

struct Vector {
	double* components;
	int size;
};

bool areEqualVectors(Vector* v1, Vector* v2);
Vector* createVectorFromArray(int size, ...);
Vector* getReverseVector(Vector* v);
Vector* getVectorDif(Vector* v1, Vector* v2);
double getDistanceBetweenVectors(Vector* v1, Vector* v2);