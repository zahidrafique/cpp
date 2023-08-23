#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "pollen_count_updates.h"

using namespace std;

/*
*	This program updates a file containing the 10 most recent pollen counts.
*	As a new count is obtained, it’s added to the end of the file, and the oldest count is deleted
*	from the file. Additionally, the average of the new file’s data is calculated and displayed
*/

//int main() {
int PollenReadings() {
	const int SIZE = 10;
	int data[SIZE] = { 0 };

	int new_reading = 0;

	read_data(data, SIZE);

	cout << "Enter the new pollen reading: ";
	cin >> new_reading;

	int sum = accumulate_write_data(data, SIZE, new_reading);

	double average = double(sum) / SIZE;
	cout << "Average Pollen Reading: " << average << endl;

	return 0;
}

//Todo: Implement read_data()


//Todo: Implement accumulate_write_data()


//Todo: Implement namespace 


//Todo: Implement exception handling

