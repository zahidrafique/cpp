#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

/*
 * This program converts cartesian coordinates to polar coordinates
 */

//Todo: Implement getInput() function
void getInput(double&, double&);		//Prototype

//Todo: Implement calculateRadius() function
double calculateRadius(double x, double y) {		//Passing by value
	return int(sqrt(x * x + pow(y, 2)) * 100) / 100.0;		//Limit to 2 decimal points by 1. multiply by 100, 2. type cast to int, 3. divide by 100.0
}

//Todo: Implement calculateAngle() function
double calculateAngle(double x, double y) {
	return atan(y / x);
}

//Todo: Implement printOutput() function
void printOutput(double r, double theta) {
	double degrees = theta * 180 / 3.14159;
	cout << "r: " << r << ", theta: " << theta << "radians - " << degrees << "degrees" << endl;
}

//int main() {
int coordinateConversionMain() {
	double x, y, r, theta;

	getInput(x, y);

	//trying to anticipate run time error and handle it
	if (x == 0) {
		cout << "Error: value of x cannot be zero!" << endl;
		return -1;
	}

	r = calculateRadius(x, y);
	theta = calculateAngle(x, y);

	printOutput(r, theta);

	return 0;
}

//Implementation
void getInput(double& a, double& y) {			//Passing by reference
	cout << "Enter the value of x: ";
	cin >> a;
	cout << "Enter the value of y: ";
	cin >> y;
}