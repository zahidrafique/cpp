#include <iostream>
#include "Complex.h"

using namespace std;

double addReal(const Complex& complex1, const Complex& complex2) {
	return complex1.real + complex2.real;
}

int main() {
//int complexDriver() {
	Complex c1;
	Complex c2(-4.5, 5.6);
	Complex* c3 = new Complex();

	cout << "C1: ";
	c1.printValues();
	cout << endl;

	cout << "C2: ";
	c2.printValues();
	cout << endl;

	
	c1.assignValues(1.2, -4.3);
	cout << "C1: ";
	c1.printValues();
	cout << endl;

	
	cout << "Absolute value for ";
	c2.printValues();
	cout << " is " << c2.getAbsolute() << endl;


	Complex c4 = c1.multScalar(3);
	cout << "C4 Values: ";
	c4.printValues();
	cout << endl;

	Complex c5(1.2, -4.3);
	if (c1 == c5) {
		cout << "C1 & C5 are equal!" << endl;
	}
	else {
		cout << "C1 & C5 are NOT equal!" << endl;
	}

	Complex c6 = c1 + c2;			// Equivalent to Complex c6 = c1.operator+(c2);
	cout << "C6: " << c6.getName() << " ";
	c6.printValues();
	cout << endl;

	Complex c7 = c1;		//Equivalent to Complex c7(c1);
	cout << "C7: ";
	c7.printValues();
	cout << endl;

	double totalReal = addReal(c1, c2);
	cout << "Total Real: " << totalReal << endl;

	/*
	cout << "Enter new value for c2: ";
	cin >> c2;
	cout << "c2: " << c2 << endl;
	*/

	c1.~Complex();		//Manual call of the destructor

	cout << "--------------- Explicit deletion of objects created on heap --------------- " << endl;

	delete c3;

	cout << " --------- End of main() ---------------- " << endl;


	return 0;
}