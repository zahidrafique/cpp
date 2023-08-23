#include <iostream>
#include <string>

using namespace std;

bool isValidScientificNumber(string s, double& retVal);

//int main() {
int chracterManip() {
	string s;
	double d = 0.0;

	cout << "Enter a decimal number in scientific notation: ";
	cin >> s;

	if (isValidScientificNumber(s, d)) {
		cout << "You entered value equals: " << d << endl;
	}
	else {
		cout << "You did not provide a valid number in scientific notation!!" << endl;
	}

	return 0;
}

//Todo: Implement isValidScientificNumber()

