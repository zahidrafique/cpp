#pragma once
#include <iostream>
#include <string>

class Complex {
private:
	double real;
	double imaginary;
	std::string* name;

public:
	//Constructors
	Complex();
	Complex(const Complex& complex2);
	Complex(double, double);

	//Base-Member iniatialization
	//Complex(double realPart, double imaginaryPart) : real(realPart), imaginary(imaginaryPart) {};


	~Complex();	//Destructor

	//Accessors
	double getReal() { return real; }
	//double getImaginary() { return imaginary; }
	double getImaginary();		//Alternate inline implementation
	std::string getName() { return *name; }

	void printValues();		//Accessor

	//Mutators
	void setReal(double real) { this->real = real; }
	void setImaginary(double imaginary) { this->imaginary = imaginary; }
	void setName(std::string* name) { this->name = name; }

	void assignValues(double, double);		//Mutator

	double getAbsolute();	//Utility

	Complex multScalar(double);

	//operator functions
	bool operator==(const Complex& complex2);
	Complex operator+(const Complex& complex2);
	Complex operator=(const Complex& complex2);

	//Friend functions
	friend double addReal(const Complex& complex1, const Complex& complex2);

};
