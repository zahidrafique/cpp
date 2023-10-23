#include "Date.h"
#include "IntDate.h"
#include <iostream>

using namespace std;

int main() {
//int dateMain() {
	Date a, b(11, 8, 2024);

	a.show();

	
	cout << b.get() << endl;
	
	a.set(4, 17, 2023);
	a.show();
	
	Date c(7, 4, 1900);
	cout <<a.get() << " is a Leap Year? " << (a.isLeapYear() ? "Yes" : "No") << endl;
	cout << b.get() << " is a Leap Year? " << (b.isLeapYear() ? "Yes" : "No") << endl;
	cout << c.get() << " is a Leap Year? " << (c.isLeapYear() ? "Yes" : "No") << endl;
	
	//a.set(11, 8, 2024);
	cout << "Is " << a.get() << " equal to " << b.get() << "? " << (a == b ? "Yes" : "No") << endl;
	
	Date d(a); //Date d = a;		// Copy constructor & operator==() are provide by default if not overridden in class
	cout << "Is " << a.get() << " equal to " << d.get() << "? " << (a.operator==(d) ? "Yes" : "No") << endl;
	
	cout << d.get() << " -- " << d.convert() << endl;
	
	cout << "Is " << b.get() << " smaller than " << a.get() << "? " << ((b < a) ? "Yes" : "No") << endl;
	/*
	cout << "The day on " << a.get() << " is " << a.dayOfWeek() << endl;
	cout << "The day on " << b.get() << " is " << b.dayOfWeek() << endl;

	cout << "Enter a new date for object a: ";
	cin >> a;
	cout << "The date of object a is " << a << endl;

	//int i = (int)a;
	//cout << "Conversion of " << a << " to int is: " << i << endl;

	int i2 = 20250604;
	Date e(i2);
	cout << "Graduation date in 2 years: " << e << endl;

	IntDate id(19690720);
	//Date f = Date(id);		//C++ style
	//Date f = (Date)id;			//C style
	//cout << "Apollo 11 landed on Moon on: " << f << endl;

	IntDate id2 = IntDate(e);
	/*
	int z = int(e);
	IntDate id2 = IntDate(z);
	*/
	//cout << "Converting from Date " << e << " to IntDate " << id2.get() << endl;

	return 0;
}