#include <iostream>

using namespace std;

//Todo: Create struct Date


//Todo: Create struct Person and test functions


//int main() {
int structureBasicsMain() {
	Person p;
	//Todo: Assign data to struct variable p and display on screen


	Person jr{ 5678L, "Joe Rogan", {8, 11, 1967}};
	cout << "Name: " << jr.name << ", id: " << jr.id << ", DOB: " << jr.birthDate.month << "/" << jr.birthDate.day << "/" << jr.birthDate.year << endl;

	printInfo(jr);
	printInfo(jr);
	cout << endl;
	printInfoReference(jr);
	printInfo(jr);
	cout << endl;
	printInfoPointer(&jr);
	printInfo(jr);


	printInfo(createPerson());
	printInfo(createPersonReferenceOnStack());

	Person prh = createPersonReferenceOnHeap();
	printInfo(prh);
	cout << "Address: " << &prh << endl;

	Person* pp = createPersonPointer();
	printInfoPointer(pp);
	delete pp;

	//Todo: Create array of struct Person, assign data and display

	return 0;
}