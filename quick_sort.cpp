#include <iostream>

using namespace std;

void quickSort(int data[], int left, int right);
int partitionIt(int data[], int left, int right);
void print(int data[], int SIZE);

/*
 * This program uses quick sort algorithm to sort a random array
 */

int main() {
//int quickSort() {
	const int SIZE = 10;
	int data[SIZE] = { 34, 12, 67, 89, 45, 54, 10, 5, 66, 26 };

	print(data, SIZE);
	quickSort(data, 0, SIZE-1);
	print(data, SIZE);

	//Todo: Implement template for quickSort()
	//double data2[SIZE] = { 34.5, 12.1, 67.3, 89.5, 45.2, 54.8, 10.9, 5.1, 66.6, 26.4 };

	//Todo: Seperate header & implementation
	
	return 0;
}

//Todo: Implement quickSort() function
void quickSort(int data[], int left, int right) {

}

//Todo: Implement partitionIt function
int partitionIt(int data[], int left, int right) {
	int leftPtr = left - 1;
	int rightPtr = right;

	int pivotValue = data[right];

	while (true) {	//Infinite loop -
		while (data[++leftPtr] <= pivotValue && leftPtr <= right);
		while (data[--rightPtr] >= pivotValue && rightPtr >= left);

		if (rightPtr < leftPtr) {
			int temp = data[leftPtr];
			data[leftPtr] = data[right];
			data[right] = temp;

			break;	//break when pointer cross each other
		}

		int temp = data[leftPtr];
		data[leftPtr] = data[rightPtr];
		data[rightPtr] = temp;
	}

	return leftPtr;
}

void print(int data[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << data[i] << " ";
	}

	cout << endl;
}
