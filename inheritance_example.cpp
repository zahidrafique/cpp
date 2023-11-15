#include <iostream>

using namespace std;

//Todo: Implement Circle class
class Circle {
protected:
	double radius;

public:
	const double PI = 3.14159;

	Circle() { radius = 0.0; }
	Circle(double radius) { this->radius = radius; }
	double getArea();
};

double Circle::getArea() {
	return PI * radius * radius;
}

//Todo: Implement Cylinder class
class Cylinder : public Circle {
protected:
	double height;

public:
	Cylinder() { height = 0; radius = 0; }
	Cylinder(double radius, double height);

	double getArea();	//Surface area of cylinder
	double getFuelVolume();
};

Cylinder::Cylinder(double radius, double height) {
	//Circle(radius);
	this->radius = radius;
	this->height = height;
}

double Cylinder::getArea() {
	return 2 * Circle::getArea() + 2 * PI * radius * height;
}

double Cylinder::getFuelVolume() {
	return PI * radius * radius * height;
}

//Todo: Implement Rocket class
class Rocket : public Cylinder {
private:
	double coneHeight;

public:
	Rocket(double coneHeight, double height, double radius);
	double getArea();	//Surface area of whole rocket
	double getCapsuleVolume();
};

Rocket::Rocket(double coneHeight, double height, double radius) {
	this->coneHeight = coneHeight;
	this->height = height;
	this->radius = radius;
	//Cylinder(height, radius);
}

double Rocket::getArea() {
	double l = sqrt(radius * radius + coneHeight * coneHeight);

	return PI * radius * l + 2 * PI * radius + PI * radius * radius;
}

double Rocket::getCapsuleVolume() {
	return (PI * radius * radius * coneHeight) / 3;
}

//int main() {
int TestInheritanceMain() {
	Circle c(5.2);
	cout << "Area of circle with radius 5.2 is: " << c.getArea() << endl;

	Cylinder y(5.2, 10);
	cout << "Surface Area of Cylinder: " << y.getArea() << endl;
	cout << "Fuel Volume: " << y.getFuelVolume() << endl;

	//c = y;

	Rocket r(2, 10, 5.2);
	cout << "Surace Area of Rocket: " << r.getArea() << endl;
	cout << "Capsule Volume: " << r.getCapsuleVolume() << endl;
	cout << "Fuel Volume: " << r.getFuelVolume() << endl;

	return 0;
}