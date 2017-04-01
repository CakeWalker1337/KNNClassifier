#include "stdafx.h"
#include "CppUnitTest.h"
#include "../KNNClassifier/vec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KNNClassifier_Test
{		
	TEST_CLASS(GetVectorSum)
	{
	public:
		TEST_METHOD(getVectorSum_Test)
		{
			Vector a = createVectorFromArray(2, 2.0, 1.0);
			Vector b = createVectorFromArray(2, 1.0, 1.0);
			Vector c = createVectorFromArray(2, 3.0, 2.0);
			Assert::AreEqual(true, areEqualVectors(getVectorSum(a, b), c));
		}
	};

	TEST_CLASS(CreateVectorFromArray)
	{
	public:
		TEST_METHOD(createVectorFromArray_Test)
		{
			Vector a, b;
			a.size = 2;
			a.components = new double[2];
			a.components[0] = a.components[1] = 1.0;
			b = createVectorFromArray(2, 1.0, 1.0); //��������� ���� �������
			Assert::AreEqual(true, areEqualVectors(a, b));
		}
	};

	TEST_CLASS(AreEqualVectors)
	{
	public:

		TEST_METHOD(areEqualVectors_True)
		{
			Vector a, b; // ������� ��� �������
			a.size = b.size = 2; //������ �� ���������� ������ � ���������� ��������
			a.components = new double[a.size];
			b.components = new double[b.size];
			a.components[0] = b.components[0] = 1.0;
			a.components[1] = b.components[1] = 2.0;
			Assert::AreEqual(true, areEqualVectors(a, b)); //��������� ������������ ��������
		}

		TEST_METHOD(areEqualVectors_False)
		{
			Vector a, b; // ������� ��� �������
			a.size = b.size = 2; //������ �� ���������� ������ � ������ ��������
			a.components = new double[a.size];
			b.components = new double[b.size];
			a.components[0] = b.components[0] = 1.0;
			a.components[1] = 2.0;  b.components[1] = 1.0;
			Assert::AreNotEqual(true, areEqualVectors(a, b)); //��������� ������������ ��������
		}

		TEST_METHOD(areEqualVectors_DiffSizes)
		{
			Vector a, b; // ������� ��� �������
			a.size = 2; b.size = 1; //������ �� ������ ������
			a.components = new double[a.size];
			b.components = new double[b.size];
			a.components[0] = b.components[0] = 1.0;
			a.components[1] = 2.0;
			if (areEqualVectors(a, b))
				Assert::Fail(); //���� ������� ������� true, ��������� ���� �������
		}
	};
}