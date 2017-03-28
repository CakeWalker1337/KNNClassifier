#include <iostream>
#include "stdafx.h"
#include "vec.h"
#include <stdarg.h>

bool areEqualVectors(Vector left, Vector right)
{
	if (left.size != right.size) return false;

	for (int i = 0; i < left.size; i++)
	{
		if (left.components[i] != right.components[i]) return false;
	}
	return true;
}

Vector createVectorFromArray(int size, ...)
{
	Vector vec;
	if (size > 0)
	{
		vec.size = size;
		vec.components = new double[size];
		va_list list;
		va_start(list, size);
		for (int i = 0; i < size; i++)
		{
			vec.components[i] = va_arg(list, double);
		}
		va_end(list);
	}
	return vec;
}