#include <iostream>
#include "Complex.h"
#include <string>
#include <math.h>

using namespace std;

Complex::Complex() {
	real = 0;
	imaginary = 0;
	cout << "Default constructor called!" << endl;
}

Complex::Complex(double real, double imaginary) {
	this->real = real;
	//(*this).real = real; //equivalent to line above
	this->imaginary = imaginary;
	cout << "Overlaoded constructor called with values - real: " << real << ", imaginary: " << imaginary << endl;
}

Complex::~Complex() {
	cout << "Destructor called!" << endl;
}

//Todo: Implement basics 

void Complex::printValues() {
	string imaginarySign = "+";
	if (imaginary < 0) {
		imaginarySign = "-";
	}
	cout << real;
	
	if (imaginary != 0) {
		cout << imaginarySign << abs(imaginary) << "i";
	}
}

void Complex::assignValues(double real, double imaginary) {
	this->real = real;
	this->imaginary = imaginary;
}

double Complex::getAbsolute() {
	double absolute = sqrt(pow(real, 2) + pow(imaginary, 2));
	return (int)(absolute * 100) / 100.0;
}

//Todo: Implement operator overloading


//Todo: Implement class IO capabitlity

