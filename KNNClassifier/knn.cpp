#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "knn.h"

using namespace std;

bool areEqualGroups(Group* g1, Group* g2)
{
	if (strcmp(g1->label, g2->label) != 0) return false;
	return (g1->count == g2->count);
}

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
	
	double* t = new double[vectorSize];
	for (int i = 0; i < vectorSize; i++)
	{
		t[i] = 0.0;
		t[i] = atof(m[i]);
	}
	strcpy_s(s->label, m[vectorSize]);
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

Sample** readDataFromFile(char* filename, int* size)
{
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("Can't open file! ");
		return NULL;
	}

	int vectorSize = 0;
	if (fscanf(f, "%d %d\n", size, &vectorSize) != 2)
	{
		printf("Can't read sample size!");
		return NULL;
	}
	Sample** samples = new Sample*[*size];
	char line[1024];
	int k = 0;

	while (fgets(line, sizeof(line), f) != NULL)
	{
		samples[k] = createSampleFromString(line, vectorSize);
		k++;
	}
	return samples;
}

int saveDataToFile(char* filename, Sample** samples, int size)
{
	if (size == 0)
		return 0;
	FILE *f = fopen(filename, "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		return 1;
	}

	fprintf(f, "%d %d \n", size, samples[0]->position->size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < samples[i]->position->size; j++)
			fprintf(f, "%f, ", samples[i]->position->components[j]);
		fprintf(f, "%s\n", samples[i]->label);
	}

	fclose(f);

	return 0;
}