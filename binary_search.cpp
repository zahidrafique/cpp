#include <iostream>

using namespace std;

int linearSearch(int[], int, int);
int binarySearch(int[], int, int);				//Iterative technique
int binarySearch(int[], int, int, int, int);	//Recurive technique

/*
 * This program uses binary search algorithm to find a search key in a sorted array
 */

//int main() {
int binarySearchMain() {
	const int SIZE = 10;
	int data[SIZE] = {2, 5, 7, 12, 19, 23, 25, 31, 35, 40};

	int searchKey = 32;

	int found = linearSearch(data, SIZE, searchKey);
	if (found < 0)
		cout << "LinearSearch - Value " << searchKey << " not found!!" << endl;
	else
		cout << "LinearSearch - Value " << searchKey << (" found at index ") << found << endl;

	found = binarySearch(data, SIZE, searchKey);
	if (found < 0)
		cout << "BinarySearch - Value " << searchKey << " not found!!" << endl;
	else
		cout << "BinarySearch - Value " << searchKey << (" found at index ") << found << endl;

	found = binarySearch(data, SIZE, searchKey, 0, SIZE - 1);
	cout << "BinarySearch - Value " << searchKey;
	(found < 0) ? (cout << " not found!!") : (cout << " found at index " << found);
	cout << endl;

	return 0;
}

int linearSearch(int data[], int SIZE, int searchKey) {
	for (int i = 0; i < SIZE; i++) {
		if (searchKey == data[i]) {
			return i;
		}
	}

	return -1; //If we do not find searchKey in array
}

//Todo: Implement binarySearch() using iteration
int binarySearch(int data[], int SIZE, int searchKey) {
	int lowerBound = 0;
	int upperBound = SIZE - 1;
	int midPoint;

	while (lowerBound <= upperBound) {
		midPoint = (lowerBound + upperBound) / 2;

		if (searchKey == data[midPoint]) {	//Its a match, return midPoint index
			return midPoint;
		}
		else if (searchKey > data[midPoint]) {	//searchKey is in upper half
			lowerBound = midPoint + 1;
		}
		else {		//searchKey is in lower half
			upperBound = midPoint - 1;
		}
	}

	return -1;		//searchKey was not found
}

//Todo: Impleent binarSearch() using recursion
int binarySearch(int data[], int SIZE, int searchKey, int lowerBound, int upperBound) {
	if (lowerBound > upperBound) {	//base case - exausted whole array but not found
		return -1;
	}

	int midPoint = (lowerBound + upperBound) / 2;

	if (searchKey == data[midPoint]) {
		return midPoint;
	}
	else if (searchKey > data[midPoint]) {
		return binarySearch(data, SIZE, searchKey, midPoint + 1, upperBound);
	}
	else {
		return binarySearch(data, SIZE, searchKey, lowerBound, midPoint - 1);
	}
}