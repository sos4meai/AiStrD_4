#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AiStrD3Lab4/Sorts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsLab4
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(correct_is_correct)
		{
			int* arr = new int[5];
			for (int i = 0; i < 5; i++)
				arr[i] = i;
			Assert::IsTrue(correct(arr, 5));
			delete[] arr;
		}
		//bogo
		TEST_METHOD(bogosort_3elem)
		{
			int* arr = new int[3];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = 1;
			bogoSort(arr, 3);
			Assert::IsTrue(correct(arr, 3));
			delete[] arr;
		}

		TEST_METHOD(bogosort_4elem)
		{
			int* arr = new int[4];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = 6;
			arr[3] = -8;
			bogoSort(arr, 4);
			Assert::IsTrue(correct(arr, 4));
			delete[] arr;
		}
		//heap
		TEST_METHOD(heapsort_7elem)
		{
			int* arr = new int[7];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = -1;
			arr[3] = 4;
			arr[4] = 0;
			arr[5] = 1; 
			arr[6] = -2;
			heapSort(arr, 7);
			Assert::IsTrue(correct(arr, 7));
			delete[] arr;
		}

		TEST_METHOD(heapsort_4elem)
		{
			int* arr = new int[4];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = 6;
			arr[3] = -8;
			heapSort(arr, 4);
			Assert::IsTrue(correct(arr, 4));
			delete[] arr;
		}
		//bubble
		TEST_METHOD(bubblesort_7elem)
		{
			int* arr = new int[7];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = -1;
			arr[3] = 4;
			arr[4] = 0;
			arr[5] = 1;
			arr[6] = -2;
			BubbleSort(arr, 7);
			Assert::IsTrue(correct(arr, 7));
			delete[] arr;
		}

		TEST_METHOD(bubblesort_4elem)
		{
			int* arr = new int[4];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = 6;
			arr[3] = -8;
			BubbleSort(arr, 4);
			Assert::IsTrue(correct(arr, 4));
			delete[] arr;
		}
		//quick
		
		TEST_METHOD(quicksort_7elem)
		{
			int* arr = new int[7];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = -1;
			arr[3] = 4;
			arr[4] = 0;
			arr[5] = 1;
			arr[6] = -2;
			StartQuickSort(arr, 7);
			Assert::IsTrue(correct(arr, 7));
			delete[] arr;
		}

		TEST_METHOD(quicksort_4elem)
		{
			int* arr = new int[4];
			arr[0] = 4;
			arr[1] = 2;
			arr[2] = 6;
			arr[3] = -8;
			StartQuickSort(arr, 4);
			Assert::IsTrue(correct(arr, 4));
			delete[] arr;
		} 
		//binary
		TEST_METHOD(binary_find_first)
		{
			int* arr = new int[7];
			arr[0] = -1;
			arr[1] = 0;
			arr[2] = 3;
			arr[3] = 8;
			arr[4] = 48;
			arr[5] = 56;
			arr[6] = 200;
			Assert::AreEqual(0, BinarySearch(arr, 7, -1));
			delete[] arr;
		}
		TEST_METHOD(binary_find_last)
		{
			int* arr = new int[7];
			arr[0] = -1;
			arr[1] = 0;
			arr[2] = 3;
			arr[3] = 8;
			arr[4] = 48;
			arr[5] = 56;
			arr[6] = 200;
			Assert::AreEqual(6, BinarySearch(arr, 7, 200));
			delete[] arr; 
		}
		TEST_METHOD(binary_find_middle)
		{
			int* arr = new int[7];
			arr[0] = -1;
			arr[1] = 0;
			arr[2] = 3;
			arr[3] = 8;
			arr[4] = 48;
			arr[5] = 56;
			arr[6] = 200;
			Assert::AreEqual(3, BinarySearch(arr, 7, 8));
			delete[] arr;
		}
		TEST_METHOD(binary_find_somewhere)
		{
			int* arr = new int[7];
			arr[0] = -1;
			arr[1] = 0;
			arr[2] = 3;
			arr[3] = 8;
			arr[4] = 48;
			arr[5] = 56;
			arr[6] = 200;
			Assert::AreEqual(5, BinarySearch(arr, 7, 56));
			delete[] arr;
		}
		TEST_METHOD(binary_not_found)
		{
			int* arr = new int[7];
			arr[0] = -1;
			arr[1] = 0;
			arr[2] = 3;
			arr[3] = 8;
			arr[4] = 48;
			arr[5] = 56;
			arr[6] = 200;
			Assert::AreEqual(-1, BinarySearch(arr, 7, 99));
			delete[] arr;
		}
		TEST_METHOD(correct_char_array_test_true)
		{
			
			char* arr = new char[5];
			arr[0] = '!';
			arr[1] = '5';
			arr[2] = 'T';
			arr[3] = 's';
			arr[4] = '~';
			Assert::IsTrue(correct_char_array(arr, 5));
			delete[] arr;
		}
		TEST_METHOD(correct_char_array_test_false)
		{
			
			char* arr = new char[5];
			arr[4] = '!'; 
			arr[1] = '5';
			arr[2] = 'T';
			arr[3] = 's';
			arr[0] = '~';
			Assert::IsFalse(correct_char_array(arr, 5));
			delete[] arr;
		}
		TEST_METHOD(correct_char_array_test)
		{
			
			char* arr = new char[5];
			arr[0] = '5';
			arr[1] = 'u';
			arr[2] = 'T';
			arr[3] = '0';
			arr[4] = '!';
			CountingSort(arr, 5);
			Assert::IsTrue(correct_char_array(arr, 5));
			delete[] arr;
		}
	};
}
