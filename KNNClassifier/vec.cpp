#include <iostream>
#include "stdafx.h"
#include "vec.h"
#include <stdarg.h>

bool areEqualVectors(Vector* left, Vector* right)
{
	if (left->size != right->size) return false;

	for (int i = 0; i < left->size; i++)
	{
		if (left->components[i] != right->components[i]) return false;
	}
	return true;
}

Vector* createVectorFromArray(int size, ...)
{
	if (size < 1) return NULL;
	
	Vector* vec = new Vector();
	vec->size = size;
	vec->components = new double[size];
	va_list list;
	va_start(list, size);
	for (int i = 0; i < size; i++)
	{
		vec->components[i] = va_arg(list, double);
	}
	va_end(list);
	return vec;
}

Vector* getVectorSum(Vector* v1, Vector* v2)
{
	if (v1->size != v2->size) return NULL;

	Vector* res = new Vector();
	res->size = v1->size;
	double* a = new double[v1->size];
	res->components = a;
	for (int i = 0; i < v1->size; i++)
		res->components[i] = v1->components[i] + v2->components[i];

	return res;
}

Vector* getVectorDif(Vector* v1, Vector* v2)
{
	if (v1->size != v2->size) return NULL;

	Vector* res = new Vector();
	res->size = v1->size;
	double* a = new double[v1->size];
	res->components = a;
	for (int i = 0; i < v1->size; i++)
		res->components[i] = v1->components[i] - v2->components[i];

	return res;
}

double getDistanceBetweenVectors(Vector* v1, Vector* v2)
{
	if (v1->size != v2->size) return -1.0;

	double dis = 0;
	for (int i = 0; i < v1->size; i++)
		dis += pow((v1->components[i] - v2->components[i]), 2);

	return sqrt(dis);
}

Vector getReverseVector(Vector v)
{
	Vector* res = new Vector();
	res->size = v.size;
	double* a = new double[v.size];
	res->components = a;
	for (int i = 0; i < v.size; i++)
		res->components[i] = -v.components[i];

	return *res;
}