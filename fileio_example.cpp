#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void print(ifstream&);
void printFormatted(ifstream&);

//int main() {
int FileIOExample() {
	const string filename = "C:\\Temp\\CmpSci236\\fileio_example.txt";

	//Todo: Create ofstream object outFile


	//Todo: Write data to outFile - ID\tProduct Name\tPrice


	//Todo: close outFile stream


	//Todo: Create ifstream object inFile


	//Todo: call print()


	cout << "--------------------------------" << endl;

	//Todo: call printFormatted()


	//Todo: close inFile stream


	return 0;
}

void print(ifstream& inFile) {
//Todo: Read file line by line and print on screen


}

void printFormatted(ifstream& inFile) {
//Todo: Read each line, split into tokens, format and print to screen


//Todo: standard input stream ghost character 


}