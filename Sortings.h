#pragma once
int BinarySearch(int* Array, size_t array_size, int to_find);

void StartQuickSort(int* Array, size_t array_size);
void QuickSort(int* Array, int first_index, int last_index);

void BubbleSort(int* Array, size_t array_size);

void heapSort(int * numbers, size_t array_size);

bool correct(int *arr, size_t array_size);
void shuffle(int *arr, size_t array_size);
void bogoSort(int *arr, size_t array_size);

void CountingSort(char* Array, size_t array_size);

bool correct_char_array(char* Array, size_t array_size);