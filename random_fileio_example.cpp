#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//int main() {
int RandomFileIOExample() {
	const string filename = "C:\\Temp\\CmpSci236\\fileio_example.txt";

	ifstream inFile(filename.c_str());

	if (inFile.fail()) {	//Error (Runtime) handling in case a stream is not allocated
		cout << filename << " refused to open for input!!" << endl;
		return 1;
	}

	//Todo: display current character and current marker before & after


	//Todo: change marker to 10 characters from current


	//Todo: display current character and current marker before & after


	//Todo: change marker to 8 characters before current


	//Todo: display current character and current marker before & after


	//Todo: change marker to 12 characters before end


	return 0;
}
