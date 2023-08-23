#include <iostream>
#include "Circle.h"
#include "Cylinder.h"
#include "Rocket.h"

using namespace std;

//Todo: Implement Circle class


//Todo: Implement Cylinder class


//Todo: Implement Rocket class


//int main() {
int TestInheritanceMain() {
	Circle c(5.2);
	cout << "Area of circle with radius 5.2 is: " << c.getArea() << endl;

	Cylinder y(5.2, 10);
	cout << "Surface Area of Cylinder: " << y.getArea() << endl;
	cout << "Cost of Cylinder: " << y.getCost() << endl;

	//c = y;

	Rocket r(5.2, 10, 2);
	cout << "Surace Area of Rocket: " << r.getArea() << endl;
	cout << "Cost of Rocket: " << r.getCost() << endl;

	return 0;
}