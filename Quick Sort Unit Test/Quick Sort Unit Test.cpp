#include "pch.h"
#include "CppUnitTest.h"
#include "../Quick Sort/Quick Sort.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(QuickSortUnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			QuickSort Q1;
			int count = 0;
			int actual[] = { -5,0,-7,10,2 };
			int expected[] = { -7,-5,0,2,10 }; // sorted array
			int size = sizeof(actual) / sizeof(actual[0]);
			Q1.Sort(actual,size );
			for (int i = 0; i < 5; i++)
			{
				if (expected[i] == actual[i])
				{
					count += 1;
				}
			}
			if (count == size)
			{
				Logger::WriteMessage("Successful sorting");
			}
		}
		TEST_METHOD(TestMethod2)
		{
			QuickSort Q1;
			int count = 0;
			int expected[] = { -5,0,-5,10,2,10 };
			int actual[] = { -5,-5,0,2,10,10 }; // sorted array
			int size = sizeof(actual) / sizeof(actual[0]);
			Q1.Sort(expected, size);
			for (int i = 0; i < 6; i++)
			{
				if (expected[i] == actual[i])
				{
					count += 1;
				}
			}

			if (count == size)
			{
				Logger::WriteMessage("Successful sorting");
			}
		}
		TEST_METHOD(TestMethod3)
		{
			QuickSort Q1;
			int count = 0;
			int expected[] = { 2,2,2,2,2 };
			int actual[] = { 2,2,2,2,2 }; // sorted array
			int size = sizeof(actual) / sizeof(actual[0]);
			Q1.Sort(expected, size);
			for (int i = 0; i < 5; i++)
			{
				if (expected[i] == actual[i])
				{
					count += 1;
				}
			}
			if (count == size)
			{
				Logger::WriteMessage("Successful sorting");
			}
		}
		TEST_METHOD(TestMethod4)
		{
			QuickSort Q1;
			int* Array1 = new int[0];
			
			try
			{
				Q1.Sort(Array1, 0);
			}
			catch (const std::exception& p1)
			{
				Logger::WriteMessage(p1.what());
			}
			delete[] Array1;
		}
		TEST_METHOD(TestMethod5)
		{
			int* Array1 = NULL;

			QuickSort Q1;
			try
			{
				Q1.Sort(Array1, NULL);
			}
			catch (const std::exception& p1)
			{
				Logger::WriteMessage(p1.what());
			}
			delete[] Array1;
		}

	};
}