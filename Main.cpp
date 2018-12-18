#include <ctime>
#include <iostream>
#include <iomanip>
#include "Sorts.h"

using namespace std;

int main()
{
	size_t array_size;
	cout << "Array size: ";
	cin >> array_size;
	int* Array = new int[array_size];
	char* CharArray = new char[array_size];
	srand(time(0));
	cout << "\nSorting: \n1.Quick\n2.Bubble\n3.Heap\n4.Counting\n~Bogo~\n";
	int choice_sorting;
	cin >> choice_sorting;
	if (choice_sorting == 4)
	{
		for (int i = 0; i < array_size; i++)
		{
			CharArray[i] = rand() % 94 + 33; // îò ! äî ~
			if (array_size<=1000)
			cout << CharArray[i] << " ";
		}
	}
	else
	{
		for (int i = 0; i < array_size; i++)
		{
			if (i % 25 == 0)
				cout << '\n';
			Array[i] = rand() % 101;
			if (array_size<=1000)
			cout << Array[i] <<"  ";
			
		}
	}
	cout << "\n\n\n";
	unsigned int start_time = clock();
	switch (choice_sorting)
	{
	case 1: StartQuickSort(Array, array_size); break;
	case 2: BubbleSort(Array, array_size); break;
	case 3: heapSort(Array, array_size); break;
	case 4:	CountingSort(CharArray, array_size); break;
	default: bogoSort(Array, array_size); break;
	}
	unsigned int end_time = clock();
	cout << "\n";
	if (choice_sorting!=4)
	 for (int i = 0; i < array_size; i++)
		 if (array_size <= 1000) {
			 if (i % 25 == 0)
				 cout << '\n';
			 cout << Array[i] << "  ";
		 }
	cout << "\nTime: " << end_time - start_time << " ms\n";
	if (choice_sorting != 4)
	{
		cout << "\nBinarySearch?\n1. Yes\nElse. Oh, God, no\n";
		unsigned choice_search; cin >> choice_search;
		if (choice_search == 1)
		{
			cout << "To find: ";
			int to_find; cin >> to_find;
			int index = BinarySearch(Array, array_size, to_find);
			if (index != -1)
				cout << "\nIndex: " << index<<endl;
			else
				cout << "\nThereis no such element\n";

		}
	}
	delete[] Array;
	delete[] CharArray;
	system("pause");
	return 0;
}
