#include "Sorts.h"
#include <iostream>
using namespace std;

int BinarySearch(int * Array, size_t array_size, int to_find)
{
	int left = 0; 
	int right = array_size-1;
	int search = -1;
	while (left <= right) 
	{
		int mid = (left + right) / 2; 
		if (to_find == Array[mid]) {  
			search = mid;    
			break;            
		}
		if (to_find < Array[mid])   
			right = mid - 1;  
		else                  
			left = mid + 1;   
	}
	
		return search;
}

void StartQuickSort(int* Array, size_t array_size)
{
	QuickSort(Array, 0, (int)array_size-1);
}

void QuickSort(int * Array, int first_index, int last_index)
{

	int l = first_index, r = last_index;
	int middle = Array[(l + r) / 2]; 
	while (l <= r)
	{
		while (Array[l] < middle)
			l++;
		while (Array[r] > middle)
			r--;
		if (l <= r)
			swap(Array[l++], Array[r--]);
	}
	if (first_index < r)
		QuickSort(Array, first_index, r);
	if (last_index > l)
		QuickSort(Array, l, last_index);
}

void BubbleSort(int * Array, size_t array_size)
{
	int i, j;
	for (i = 1; i < array_size; i++) {
		for (j = 1; j < array_size; j++) {
			if (Array[j] < Array[j - 1])
				swap(Array[j - 1], Array[j]);

		}
	}

}


void siftDown(int* numbers, int root, int bottom)
{
	int maxChild;
	bool done = false;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else done = true;
	}
}

void heapSort(int *numbers, size_t array_size)
{
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size);
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}




/***************BOGO***************/
bool correct(int *arr, size_t array_size) {
	while (--array_size > 0)
		if (arr[array_size - 1] > arr[array_size])
			return false;
	return true;
}

void shuffle(int *arr, size_t array_size) {
	int i;
	for (i = 0; i < array_size; ++i)
		swap(arr[i], arr[(rand() % array_size)]);
}

void bogoSort(int *arr, size_t array_size) {
	while (!correct(arr, array_size))
		shuffle(arr, array_size);
}

void CountingSort(char* Array, size_t array_size)
{
	size_t* SortingArray = new size_t[127];
	for (int i = 0; i < 127; i++)
		SortingArray[i] = 0;
	for (int i = 0; i < array_size; i++)
	{
		int buffer = Array[i];
		SortingArray[buffer]++;
	}
	int j = 0;
	for (int i = 0; i < 127; i++)
	{
		while (SortingArray[i] != 0)
		{
			char c = i;
			Array[j] = c;
			j++;
			SortingArray[i]--;
		}
	}

	for (int i = 0; i < array_size; i++)
		cout << Array[i] << "  ";
}

bool correct_char_array(char * Array, size_t array_size)
{
	for (size_t i = 1; i < array_size; i++)
		if (Array[i] < Array[i - 1])
			return false;
	return true;
}
