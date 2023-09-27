#include <iostream>
#include <string>
#include <math.h>

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

bool isValidScientificNumber(string s, double& retVal) {
	int eIndex = -1;

	//Verify there is only one 'e' or 'E'
	for (int i = 0; i < s.size(); i++) {
		if (eIndex < 0 && (s[i] == 'e' || s[i] == 'E')) {	//Found our first e or E
			eIndex = i;
			continue;
		}

		if (eIndex >= 0 && (s[i] == 'e' || s[i] == 'E')) {	//Found a 2nd e or E
			return false;
		}
	}

	if (eIndex < 0) {
		return false;
	}

	//Split input string into base & exponent
	string base = s.substr(0, eIndex);
	string exponent = s.substr(eIndex + 1);

	//Validate base
	int bIndex = 0;
	if (base[bIndex] == '-' || base[bIndex] == '+') {
		bIndex++;
	}

	if (!isdigit(base[bIndex])) {
		return false;
	}
	else {
		bIndex++;
	}

	if (base[bIndex++] != '.') {
		return false;
	}

	for (int i = bIndex; i < base.length(); i++) {
		if (!isdigit(base[i])) {
			return false;
		}
	}

	//Validate exponent
	int xIndex = 0;
	if (exponent[xIndex] == '-' || exponent[xIndex] == '+') {
		xIndex++;
	}

	for (int i = xIndex; i < exponent.length(); i++) {
		if (!isdigit(exponent[i])) {
			return false;
		}
	}

	//Convert base into double, exponent into int and calculate value
	double baseDouble = atof(base.c_str());
	int exponentInt = atoi(exponent.c_str());
	retVal = baseDouble * pow(10, exponentInt);

	return true;
}