#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void print(ifstream&);
void printFormatted(ifstream&);

int main() {
//int FileIOExample() {
	const string filename = "C:\\Temp\\CmpSci236\\fileio_example.txt";

	//Todo: Create ofstream object outFile
	ofstream outFile(filename.c_str());

	if (outFile.fail()) {	//exception handling
		cout << "Error: file output stream failed to open for " << filename << endl;
		return 1;
	}

	//Todo: Write data to outFile - ID\tProduct Name\tPrice
	outFile << "1\tApples\t5.50" << endl;
	outFile << "2\tOranges\t15.50" << endl;
	outFile << "3\tBananas\t50.50" << endl;
	outFile << "4\tStrawberries\t25.50" << endl;
	outFile << "5\tMangoes\t55.50" << endl;

	//Todo: close outFile stream
	outFile.close();

	//Todo: Create ifstream object inFile
	ifstream inFile;
	inFile.open(filename.c_str());

	if (inFile.fail()) {
		cout << "Error: file input stream failed to open for " << filename << endl;
		return 1;
	}

	/*
	while (!inFile.eof()) {
		inFile >> id;
		inFile >> name;
		inFile >> price;

		cout << id << " - " << name << " - $" << price << endl;
	}
	

	*/
	//Todo: call print()
	print(inFile);

	cout << "--------------------------------" << endl;

	//Todo: call printFormatted()
	inFile.clear();
	inFile.seekg(0L, ios::beg);
	//cout << (char)inFile.tellg() << endl;

	printFormatted(inFile);

	//Todo: close inFile stream
	inFile.close();

	return 0;
}

void print(ifstream& inFile) {
//Todo: Read file line by line and print on screen
	string line;
	while (!inFile.eof()) {
		getline(inFile, line);

		cout << line << endl;
	}
}

void printFormatted(ifstream& inFile) {
//Todo: Read each line, split into tokens, format and print to screen


//Todo: standard input stream ghost character 
	int id;
	string name;
	double price;
	string line;

	//Sequential file access
	while (inFile.good()) {
		inFile >> id;			//Reading using the stream character extraction operator
		if (inFile.eof()) {
			break;
		}
		inFile >> name;
		inFile >> price;

		inFile.ignore();		//Ignore Phantom new line character
		getline(inFile, line);	//Reading using the getline() function

		cout << id << " - " << name << " - $" << price << endl;
		cout << line << endl;
	}

}