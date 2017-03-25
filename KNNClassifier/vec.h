#pragma once

struct Vector {
	double* components;
	int size;
};

bool areEqualVectors(Vector v1, Vector v2);