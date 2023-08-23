#include <iostream>

using namespace std;

void swapIt(int&, int&);
void swapIt(int*, int*);
double calculateAverage(int*, int);

int tellMe();
int* surpriseMe();

//int main() {
int pointersAndFunctions() {
	int x = 20;
	int y = 55;

	cout << "Before Swap - x: " << x << ", y: " << y << endl;
	swapIt(x, y);
	cout << "After Swap - x: " << x << ", y: " << y << endl;

	cout << "Before Swap - x: " << x << ", y: " << y << endl;
	swapIt(&x, &y);
	cout << "After Swap - x: " << x << ", y: " << y << endl;

	const int SIZE = 5;
	int xArray[SIZE] = { 10, 20, 30, 40, 50 };

	double d1 = calculateAverage(xArray, SIZE);
	cout << "Average: " << d1 << endl;

	int* s = surpriseMe();
	cout << "Surprise - s: " << s << ", *s: " << *s << endl;
	delete s;

	int t = tellMe();
	cout << "Tell - &t: " << &t << ", t: " << t << endl;

	return 0;
}

//Todo: Implement swapIt() with reference parameters


//Todo: Implement swapIt() with pointer parameters


//Todo: Implement calculateAverage()


//Todo: Implement tellMe() - create int variable, assign value and return


//Todo: Implement surpriseMe() - create int with new operator, assign value and return

