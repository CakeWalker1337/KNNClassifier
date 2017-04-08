#include "stdafx.h"
#include "CppUnitTest.h"
#include "../KNNClassifier/vec.cpp"
#include "../KNNClassifier/knn.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KNNClassifier_Test
{		

	TEST_CLASS(GetReverseVector)
	{
	public:
		TEST_METHOD(getReverseVector_Normal)
		{
			Vector* a = createVectorFromArray(2, 1.0, 1.0);
			Vector* b = createVectorFromArray(2, -1.0, -1.0);
			Assert::AreEqual(true, areEqualVectors(a, getReverseVector(b)));
		}
	};

	TEST_CLASS(GetDistanceBetweenVectors)
	{
	public:
		TEST_METHOD(getDistanceBetweenVectors_Normal)
		{
			Vector* a = createVectorFromArray(2, 2.0, 1.0);
			Vector* b = createVectorFromArray(2, 1.0, 1.0);
			Assert::AreEqual(1.0, getDistanceBetweenVectors(a, b));
		}

		TEST_METHOD(getDistanceBetweenVectors_InvalidSize)
		{
			Vector* a = createVectorFromArray(1, 2.0, 1.0);
			Vector* b = createVectorFromArray(2, 1.0, 1.0);
			Assert::AreEqual(-1.0, getDistanceBetweenVectors(a, b));
		}
	};
	

	TEST_CLASS(GetVectorDif)
	{
	public:
		TEST_METHOD(getVectorDif_Normal)
		{
			Vector* a = createVectorFromArray(2, 2.0, 1.0);
			Vector* b = createVectorFromArray(2, 1.0, 1.0);
			Vector* c = createVectorFromArray(2, 1.0, 0.0);
			Assert::AreEqual(true, areEqualVectors(getVectorDif(a, b), c));
		}
		TEST_METHOD(getVectorDif_InvalidSize)
		{
			Vector* a = createVectorFromArray(2, 2.0, 1.0);
			Vector* b = createVectorFromArray(1, 1.0, 1.0);
			Assert::IsNull(getVectorDif(a, b));
		}
	};

	TEST_CLASS(GetVectorSum)
	{
	public:
		TEST_METHOD(getVectorSum_Normal)
		{
			Vector* a = createVectorFromArray(2, 2.0, 1.0);
			Vector* b = createVectorFromArray(2, 1.0, 1.0);
			Vector* c = createVectorFromArray(2, 3.0, 2.0);
			Assert::AreEqual(true, areEqualVectors(getVectorSum(a, b), c));
		}
		TEST_METHOD(getVectorSum_InvalidSize)
		{
			Vector* a = createVectorFromArray(2, 2.0, 1.0);
			Vector* b = createVectorFromArray(1, 1.0, 1.0);
			Assert::IsNull(getVectorSum(a, b));
		}
	};

	TEST_CLASS(CreateVectorFromArray)
	{
	public:
		TEST_METHOD(createVectorFromArray_Normal)
		{
			Vector* a = new Vector();
			a->size = 2;
			a->components = new double[2];
			a->components[0] = a->components[1] = 1.0;
			Vector* b = createVectorFromArray(2, 1.0, 1.0); //Применяем нашу функцию
			Assert::AreEqual(true, areEqualVectors(a, b));
		}
		TEST_METHOD(createVectorFromArray_InvalidSize)
		{
			Assert::IsNull(createVectorFromArray(0));
		}
	};
	
	TEST_CLASS(AreEqualVectors)
	{
	public:

		TEST_METHOD(areEqualVectors_True)
		{
			Vector* a = new Vector();
			Vector* b = new Vector(); // Создаем два вектора
			a->size = b->size = 2; //Задаем им одинаковый размер и одинаковые значения
			a->components = new double[a->size];
			b->components = new double[b->size];
			a->components[0] = b->components[0] = 1.0;
			a->components[1] = b->components[1] = 2.0;
			Assert::AreEqual(true, areEqualVectors(a, b)); //Проверяем возвращенное значение
		}

		TEST_METHOD(areEqualVectors_False)
		{
			Vector* a = new Vector();
			Vector* b = new Vector(); // Создаем два вектора
			a->size = b->size = 2; //Задаем им одинаковый размер и разные значения
			a->components = new double[a->size];
			b->components = new double[b->size];
			a->components[0] = b->components[0] = 1.0;
			a->components[1] = 2.0;  b->components[1] = 1.0;
			Assert::AreNotEqual(true, areEqualVectors(a, b)); //Проверяем возвращенное значение
		}

		TEST_METHOD(areEqualVectors_InvalidSize)
		{
			Vector* a = new Vector(); // Создаем два вектора
			Vector* b = new Vector();
			a->size = 2; b->size = 1; //Задаем им разный размер
			a->components = new double[a->size];
			b->components = new double[b->size];
			a->components[0] = b->components[0] = 1.0;
			a->components[1] = 2.0;
			if (areEqualVectors(a, b))
				Assert::Fail(); //Если функция вернула true, закрываем тест вручную
		}
	};
	
	TEST_CLASS(AreEqualSamples)
	{
	public:

		TEST_METHOD(areEqualSamples_True)
		{
			Sample* a = new Sample();
			Sample* b = new Sample();
			strcpy_s(a->label, "first");
			strcpy_s(b->label, "first");
			a->position = createVectorFromArray(2, 1.0, 1.0);
			b->position = createVectorFromArray(2, 1.0, 1.0);
			Assert::AreEqual(true, areEqualSamples(a, b)); 
		}

		TEST_METHOD(areEqualSamples_DifferentVectors)
		{
			Sample* a = new Sample();
			Sample* b = new Sample();
			strcpy_s(a->label, "first");
			strcpy_s(b->label, "first");
			a->position = createVectorFromArray(2, 2.0, 1.0);
			b->position = createVectorFromArray(2, 1.0, 1.0);
			Assert::AreEqual(false, areEqualSamples(a, b));
		}

		TEST_METHOD(areEqualSamples_DifferentNames)
		{
			Sample* a = new Sample();
			Sample* b = new Sample();
			strcpy_s(a->label, "first");
			strcpy_s(b->label, "second");
			a->position = createVectorFromArray(2, 1.0, 1.0);
			b->position = createVectorFromArray(2, 1.0, 1.0);
			Assert::AreEqual(false, areEqualSamples(a, b));
		}
	};

	TEST_CLASS(AreEqualGroups)
	{
	public:
		TEST_METHOD(areEqualGroups_True)
		{
			Group* a = new Group();
			Group* b = new Group();
			a->count = b->count = 2; 
			strcpy(a->label, "first");
			strcpy(b->label, "first");
			
			Assert::AreEqual(true, areEqualGroups(a, b)); 
		}

		TEST_METHOD(areEqualGroups_False)
		{
			Group* a = new Group();
			Group* b = new Group();
			a->count = b->count = 2; 
			strcpy(a->label, "first");
			strcpy(b->label, "second");
			Assert::AreNotEqual(true, areEqualGroups(a, b));
		}

		TEST_METHOD(areEqualGroups_InvalidSize)
		{
			Group* a = new Group();
			Group* b = new Group();
			a->count = 1;
			b->count = 2; 
			strcpy(a->label, "first");
			strcpy(b->label, "first");
			if (areEqualGroups(a, b))
				Assert::Fail(); 
		}
	};

	TEST_CLASS(CreateSampleFromString)
	{
	public:
		TEST_METHOD(createSampleFromString_Normal)
		{
			Sample* b = createSampleFromString("first, 1.0, 1.0", 2);
			Sample* a = new Sample();
			strcpy(a->label, "first");
			a->position = createVectorFromArray(2, 1.0, 1.0);
			Assert::AreEqual(true, areEqualSamples(a, b));
		}
		TEST_METHOD(createSampleFromString_InvalidSize)
		{
			Assert::IsNull(createSampleFromString("first, 1.0, 1.0", 0));
		}
	};

	TEST_CLASS(SplitString)
	{
	public:
		TEST_METHOD(splitString_Normal)
		{
			char** s = splitString("first, second, third", 3);
			if (strcmp(s[0], "first") != 0) Assert::Fail();
			else if (strcmp(s[1], "second") != 0) Assert::Fail();
			else if (strcmp(s[2], "third") != 0) Assert::Fail();
		}
	};

	TEST_CLASS(ReadDataFromFile)
	{
	public:
		TEST_METHOD(readDataFromFile_Normal)
		{
			int size = 0;
			Sample** s = readDataFromFile("../KNNClassifier_Test/testfile_normal.txt", &size);
			Assert::AreEqual(2, size);
		}
		TEST_METHOD(readDataFromFile_InvalidSize)
		{
			int size = 0;
			Assert::IsNull(readDataFromFile("../KNNClassifier_Test/testfile_empty.txt", &size));
		}
		TEST_METHOD(readDataFromFile_NotFound)
		{
			int size = 0;
			Assert::IsNull(readDataFromFile("testfile_notfound.txt", &size));
		}
	};
}