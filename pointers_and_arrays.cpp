#include <iostream>

using namespace std;

//int main() {
int pointerAndArrays() {
	const int SIZE = 5;
	int xArray[SIZE] = { 12, 18, 21, 27, 33 };	//Statically declared array. It will be stored on heap.

	for (int i = 0; i < SIZE; i++) {
		cout << (i+1) << ". " << xArray[i] << endl;
	}

	//Todo: access array using pointers
	cout << "Value at index 2: " << *(&xArray[0] + 2) << endl;

	int* xArrayPtr = &xArray[0];	//this is equivalent to: int* xArrayPtr = xArray;
	cout << "Address of xArray: " << xArray << ", value of xArrayPtr: " << xArrayPtr << endl;

	//Todo: loop through array using pointers

	for (int i = 0; i < SIZE; i++) {
		cout << (i + 1) << ". " << *(xArrayPtr + i) << endl;
	}

	cout << endl;

	while (xArrayPtr < (&xArray[0] + SIZE)) {
		cout << xArrayPtr << " -- " << *(xArrayPtr++) << endl;
		//xArrayPtr = xArrayPtr + 1;  //This is equivalent to: xArrayPtr++
	}

	int s;
	cout << "Enter data size: ";
	cin >> s;
	
	//Todo: create a Dynamic Array, assign values, display data and clean up memory

	int* yArrayPtr = new int[s];		//Dynamic array declared using new operator returns address of first byte of array

	for (int i = 0; i < s; i++) {
		cout << "Enter value " << (i+1) << ": ";
		int y;
		cin >> y;

		*(yArrayPtr + i) = y;		//Using pointer notation to write to array
	}

	for (int i = 0; i < s; i++) {
		cout << "Value " << (i + 1) << ". " << yArrayPtr[i] << endl;	//Using array notation to read from array
	}

	delete[] yArrayPtr;		//Celanup memory using array delete


	int* dPtr = new int();		//A scalar (single) integer variable stored on heap
	*dPtr = 10;
	delete dPtr;		//Cleanup memory using scalar delete

	// Valgrind program can report any memory leaks in your code

	return 0;
}