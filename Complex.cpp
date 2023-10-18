#include <iostream>
#include "Complex.h"
#include <string>
#include <math.h>

using namespace std;

Complex::Complex() {
	real = 0;
	imaginary = 0;
	cout << "Default constructor called!" << endl;

	name = new string("__DEFAULT__");
}

Complex::Complex(double real, double imaginary) {
	this->real = real;
	//(*this).real = real; //equivalent to line above
	this->imaginary = imaginary;
	cout << "Overlaoded constructor called with values - real: " << real << ", imaginary: " << imaginary << endl;
	
	name = new string("__CUSTOM__");
}

Complex::Complex(const Complex& complex2) {
	this->real = complex2.real;
	this->imaginary = complex2.imaginary;
	this->name = new string(*complex2.name);
}

Complex::~Complex() {
	cout << "Destructor called! ";

	cout << "name pointer: " << name;
	if (name != nullptr) {
		cout << ", " << *name;
		delete name;
		this->name = nullptr;
	}
	cout << endl;
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

inline double Complex::getImaginary() { 
	return imaginary; 
}

Complex Complex::multScalar(double scale) {
	Complex temp;
	temp.real = this->real * scale;
	temp.imaginary = this->imaginary * scale;

	return temp;
}
//Todo: Implement operator overloading
bool Complex::operator==(const Complex& complex2) {
	return this->real == complex2.real && this->imaginary == complex2.imaginary;
}

Complex Complex::operator+(const Complex& complex2) {
	Complex temp;
	temp.real = this->real + complex2.real;
	temp.imaginary = this->imaginary + complex2.imaginary;

	return temp;
}

Complex Complex::operator=(const Complex& complex2) {
	Complex temp;
	temp.real = complex2.real;
	temp.imaginary = complex2.imaginary;
	delete temp.name;			//To avoid the memory leak
	temp.name = new string(*complex2.name);

	return temp;
}


//Todo: Implement class IO capabitlity

