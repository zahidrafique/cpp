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

	while (true) {
		try {
			cmpsci236_fall2023::read_data(data, SIZE);

			cout << "Enter the new pollen reading: ";
			cin >> new_reading;

			//Input data validation
			if (new_reading < 0 || new_reading > 150) throw cmpsci236_fall2023::INVALID_POLLEN_READING;

			int sum = cmpsci236_fall2023::accumulate_write_data(data, SIZE, new_reading);

			double average = double(sum) / SIZE;
			cout << "Average Pollen Reading: " << average << endl;

			break;
		}
		catch (int e) {
			cmpsci236_fall2023::handle_exceptions(e);
			return e;
		}
		catch (string e) {
			if (e == cmpsci236_fall2023::INVALID_POLLEN_READING) {
				cout << e << " ";
			}
			return cmpsci236_fall2023::OUTPUT_FILE_STREAM_EXCEPTION;
		}
		catch (exception e) {
			cout << e.what() << "Good bye!" << endl;
		}
	}

	return 0;
}

namespace cmpsci236_fall2023 {
	//Todo: Implement read_data()
	void read_data(int data[], int SIZE) {
		ifstream inFile(FILENAME.c_str());
		if (inFile.fail()) throw INPUT_FILE_STREAM_EXCEPTION;

		int val;
		int i = 0;
		while (i < SIZE) {
			inFile >> val;
			if (inFile.eof()) {
				break;
			}

			data[i++] = val;
		}

		/*
		for (int i = 0; i < SIZE; i++) {
			inFile >> data[i];
		}
		*/

		inFile.close();
	}

	//Todo: Implement accumulate_write_data()
	int accumulate_write_data(int data[], int SIZE, int new_reading) {
		ofstream outFile(FILENAME.c_str(), ios::app);
		//if (outFile.fail()) throw OUTPUT_FILE_STREAM_EXCEPTION;
		if (outFile.fail()) throw exception("Error: Output File Stream faield to open. ");

		int sum = 0;
		for (int i = 1; i < SIZE; i++) {
			outFile << data[i] << endl;
			sum += data[i];
		}

		outFile << new_reading << endl;
		sum += new_reading;

		outFile.close();

		return sum;
	}

	//Todo: Implement namespace 


	//Todo: Implement exception handling
	void handle_exceptions(int e) {
		if (e == INPUT_FILE_STREAM_EXCEPTION) {
			cout << "Error: Input File Stream faield to open for " << FILENAME.c_str() << endl;
		}

		if (e == OUTPUT_FILE_STREAM_EXCEPTION) {
			cout << "Error: Output File Stream faield to open for " << FILENAME.c_str() << endl;
		}
	}
}
