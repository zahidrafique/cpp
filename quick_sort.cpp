#include <iostream>
#include "quick_sort.h"

using namespace std;

/*
 * This program uses quick sort algorithm to sort a random array
 */

//int main() {
int quickSort() {
	const int SIZE = 10;
	int data[SIZE] = { 34, 12, 67, 89, 45, 54, 10, 5, 66, 26 };

	print(data, SIZE);
	quickSort(data, 0, SIZE-1);
	print(data, SIZE);

	//Todo: Implement template for quickSort()
	double data2[SIZE] = { 34.5, 12.1, 67.3, 89.5, 45.2, 54.8, 10.9, 5.1, 66.6, 26.4 };
	print(data2, SIZE);
	quickSort(data2, 0, SIZE - 1);
	print(data2, SIZE);

	//Todo: Seperate header & implementation
	
	return 0;
}

//Todo: Implement quickSort() function
template <class T>
void quickSort(T data[], int left, int right) {
	if (right < left) {	//base case
		return;
	}
	else {
		int partitionIndex = partitionIt(data, left, right);

		quickSort(data, left, partitionIndex - 1);
		quickSort(data, partitionIndex + 1, right);
	}
}

//Todo: Implement partitionIt function
template <class T>
int partitionIt(T data[], int left, int right) {
	int leftPtr = left - 1;
	int rightPtr = right;

	T pivotValue = data[right];

	while (true) {	//Infinite loop -
		while (data[++leftPtr] < pivotValue);
		while (data[--rightPtr] >= pivotValue && rightPtr >= left);

		if (rightPtr < leftPtr) {
			swapIt(data, leftPtr, right);

			break;	//break when pointer cross each other
		}

		swapIt(data, leftPtr, rightPtr);
	}

	return leftPtr;
}

template <class T>
void print(T data[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << data[i] << " ";
	}

	cout << endl;
}

template <class T>
void swapIt(T data[], int left, int right) {
	T temp = data[left];
	data[left] = data[right];
	data[right] = temp;
}