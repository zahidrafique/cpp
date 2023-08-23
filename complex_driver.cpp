#include <iostream>
#include "Complex.h"

//int main() {
int complexDriver() {
	Complex c1;
	Complex c2(4.5, 5.6);
	c1.printValues();
	cout << endl;
	c2.printValues();
	cout << endl;

	c1.assignValues(1.2, -4.3);
	c1.printValues();
	cout << endl;

	cout << "Absolute value for ";
	c2.printValues();
	cout << " is " << c2.getAbsolute() << endl;

	Complex c3(5.5, 5.6);
	if (c2 == c3)
		cout << "c2 is equal to c3" << endl;
	else 
		cout << "c2 is NOT equal to c3" << endl;

	//Complex* c3 = new Complex(1.1, 2.2);
	//delete c3;

	cout << "Enter new value for c2: ";
	cin >> c2;
	cout << "c2: " << c2 << endl;

	c1.~Complex();		//Manual call of the destructor

	return 0;
}