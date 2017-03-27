#include "stdafx.h"
#include "CppUnitTest.h"
#include "../KNNClassifier/vec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KNNClassifier_Test
{		
	TEST_CLASS(UnitTest1)
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