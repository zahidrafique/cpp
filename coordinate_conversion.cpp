#include <iostream>
#include <cmath>

using namespace std;

/*
 * This program converts cartesian coordinates to polar coordinates
 */

//Todo: Implement getInput() function


//Todo: Implement calculateRadius() function


//Todo: Implement calculateAngle() function


//Todo: Implement printOutput() function

//int main() {
int coordinateConversionMain() {
	double x, y, r, theta;

	getInput(x, y);

	if (x == 0) {
		cout << "Error: value of x cannot be zero!" << endl;
		return -1;
	}

	r = calculateRadius(x, y);
	theta = calculateAngle(x, y);

	printOutput(r, theta);

	return 0;
}
