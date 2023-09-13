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
	for (int i = 0; i < data.size(); i++) {
		//cout << data[i] << " " << endl;
		cout << data.at(i) << " ";
	}
	cout << endl;

	cout << "Vector Capacity: " << data.capacity() << endl;

	//Todo: Use enhanced for loop to print data
	for (int d : data) {
		cout << d << " ";
	}
	cout << endl;

	//Todo: Sort data in vector
	for (vector<int>::iterator itr = data.begin(); itr != data.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	//Todo: Using iterators (named vs auto) with for loop and print data
	for (auto itr = data.begin(); itr != data.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	return 0;
}