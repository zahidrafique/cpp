#pragma once
#include <iostream>

class Complex {
private:
	double real;
	double imaginary;

public:
	//Constructors
	Complex();
	Complex(double, double);

	~Complex();	//Destructor

	//Accessors
	double getReal() { return real; }
	double getImaginary() { return imaginary; }

	//Mutators
	void setReal(double real) { this->real = real; }
	void setImaginary(double imaginary) { this->imaginary = imaginary; }

	void printValues();		//Accessor
	void assignValues(double, double);		//Mutator

	double getAbsolute();	//Utility
};
