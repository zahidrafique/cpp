#include <iostream>

using namespace std;

int main() {
//int pointersAdvanced() {

	int sArray[3][5] = { {1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15} };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << sArray[i][j] << " ";
		}
	}
	cout << endl;

	//Todo: declare a 2-dimensional int array using pointers, assign values, display data and clean up memory


	return 0
}