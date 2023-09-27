#include <iostream>

using namespace std;

//int main() {
int pointersBasics() {
	int x = 20;
	//Todo: Create ineger pointer to x and display
	int* xPtr = &x;
	cout << "x: " << x << ", address of x: " << &x << ", xPtr: " << xPtr << ", address of xPtr: " << &xPtr << ", value of x by dereferencing xPtr: " << *xPtr << endl;

	int y = 50;
	//Todo: Create integer pointer to y and display
	int* yPtr = &y;
	cout << "y: " << y << ", address of y: " << &y << ", yPtr: " << yPtr << ", address of yPtr: " << &yPtr << ", value of y by dereferencing yPtr: " << *yPtr << endl;

	*xPtr = *yPtr;	// equivalent to x = y;
	cout << "x: " << x << ", y: " << y << ", xPtr: " << xPtr << ", yPtr: " << yPtr << endl;

	*xPtr = 35;
	*yPtr = 45;
	cout << "x: " << x << ", y: " << y << ", xPtr: " << xPtr << ", yPtr: " << yPtr << endl;

	//Todo: Assign pointer to x to pointer of y and display
	xPtr = yPtr;
	cout << "x: " << x << ", y: " << y << ", xPtr: " << xPtr << ", yPtr: " << yPtr << ", *xPtr: " << *xPtr << ", *yPtr: " << *yPtr <<  endl;

	*xPtr = 99;
	cout << "x: " << x << ", y: " << y << ", xPtr: " << xPtr << ", yPtr: " << yPtr << ", *xPtr: " << *xPtr << ", *yPtr: " << *yPtr << endl;

	double d = 34.67;
	//Todo: Create double pointer to d and display
	double* dPtr = &d;
	cout << "d: " << d << ", address of d: " << &d << ", dPtr: " << dPtr << ", address of dPtr: " << &dPtr << ", value of d by dereferencing dPtr: " << *dPtr << endl;

	char c = 'Z';
	//Todo: Create char pointer to c and display
	char* cPtr = &c;
	cout << "c: " << c << ", address of c: " << static_cast<void*> (&c) << ", cPtr: " << static_cast<void*> (cPtr) << ", address of cPtr: " << &cPtr << ", value of c by dereferencing cPtr: " << *cPtr << endl;

	int z = 45;
	//Todo: create integer pointer to z, a pointer to pointer and display
	int* zPtr = &z;
	int** zzPtr = &zPtr;
	cout << "z: " << z << ", &z: " << &z << ", zPtr: " << zPtr << ", &zPtr: " << &zPtr << ", *zPtr: " << *zPtr << ", zzPtr: " << zzPtr << ", &zzPtr: " << &zzPtr << ", *zzPtr: " << *zzPtr << ", **zzPtr: " << **zzPtr << endl;


	return 0;
}