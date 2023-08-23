#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int main() {
int vectorMain() {
	vector<int> data;

	cout << "Vector Capacity: " << data.capacity() << endl;

	int value = 0;

	while (true) {
		cout << "Enter a positive integer: ";
		cin >> value;
		if (value == -1)
			break;

		//Add data to the vector
		data.push_back(value);
	}

	//Todo: Use standard for loop to print data


	cout << "Vector Capacity: " << data.capacity() << endl;

	//Todo: Use enhanced for loop to print data


	//Todo: Sort data in vector


	//Todo: Using iterators (named vs auto) with for loop and print data


	return 0;
}