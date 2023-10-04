#include <iostream>

using namespace std;

//int main() {
int pointersAdvanced() {

	int sArray[3][5] = { {1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15} };

	cout << &sArray[0][0] << endl << endl;


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << i << " " << j << " " << &sArray[i][j] << "  ---   " << sArray[i][j] << endl;
		}
	}
	cout << endl;

	//Todo: declare a 2-dimensional int array using pointers, assign values, display data and clean up memory

	int** mdPointerArray = new int* [3];
	*mdPointerArray = new int[5];		//	mdPointerArray[0] = new int[5];
	mdPointerArray[1] = new int[5];		//  *(mdPointerArray + 1) = new int[5];
	*(mdPointerArray + 2) = new int[5];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			//mdPointerArray[i][j] = i + j;
			*(*(mdPointerArray + i) + j) = i + j;	//This is equivalent to line above
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << i << " " << j << " " << &mdPointerArray[i][j] << "  ---   " << mdPointerArray[i][j] << endl;
		}
	}
	cout << endl;


	//Clean up dynamic multi-dimensional array

	for (int i = 0; i < 3; i++) {
		//delete[] mdPointerArray[i];
		delete[] * (mdPointerArray + i);
	}
	delete[] mdPointerArray;

	return 0;
}