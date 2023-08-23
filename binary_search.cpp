#include <iostream>

using namespace std;

int binarySearch(int[], int, int);				//Iterative technique
int binarySearch(int[], int, int, int, int);	//Recurive technique

/*
 * This program uses binary search algorithm to find a search key in a sorted array
 */

//int main() {
int binarySearchMain() {
	const int SIZE = 10;
	int data[SIZE] = {2, 5, 7, 12, 19, 23, 25, 31, 35, 40};

	int searchKey = 31;

	int found = binary_search(data, SIZE, searchKey);
	if (found < 0)
		cout << "Value " << searchKey << " not found!!" << endl;
	else
		cout << "Value " << searchKey << (" found at index ") << found << endl;

	found = binary_search(data, SIZE, searchKey, 0, SIZE - 1);
	cout << "Value " << searchKey;
	(found < 0) ? (cout << " not found!!") : (cout << " found at index " << found);
	cout << endl;

	return 0;
}

//Todo: Implement binarySearch() using iteration
int binarySearch(int data[], int SIZE, int searchKey) {

}

//Todo: Impleent binarSearch() using recursion
int binarySearch(int data[], int SIZE, int searchKey, int lowBound, int upperBound) {

}