#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "knn.h"

using namespace std;

bool areEqualSamples(Sample* s1, Sample* s2)
{
	if (strcmp(s1->label, s2->label) != 0) return false;
	return (areEqualVectors(s1->position, s2->position));
}

char** splitString(char* line, int pieces)
{
	char** s = new char*[pieces];
	int left = 0, count = 0;
	bool flag = false;
	for (int i = 1; i < strlen(line); i++)
	{
		if (i == strlen(line) - 1)
		{
			s[count] = new char[i - left + 2];
			for (int j = left, c = 0; j <= i; j++, c++)
			{
				s[count][c] = line[j];
			}
			s[count][i - left + 1] = '\0';
		}
		if (line[i] == ',')
		{
			s[count] = new char[i - left + 1];
			for (int j = left, c = 0; j < i; j++, c++)
			{
				s[count][c] = line[j];
			}
			s[count][i - left] = '\0';
			count++;
			left = i + 2;
		}
	}
	return s;
}

Sample* createSampleFromString(char* line, int vectorSize)
{
	if (vectorSize < 1) return NULL;

	Sample* s = new Sample();
	char** m = splitString(line, vectorSize + 1);
	strcpy(s->label, m[0]);
	double* t = new double[vectorSize];
	for (int i = 0; i < vectorSize; i++)
	{
		t[i] = 0.0;
		t[i] = atof(m[i+1]);
	}
	Vector* v = new Vector;
	v->components = t;
	v->size = vectorSize;
	s->position = v;
	for (int i = 0; i <= vectorSize; i++)
	{
		delete[] m[i];
	}
	delete[] m;
	return s;
}