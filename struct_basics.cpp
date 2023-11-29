#include <iostream>

using namespace std;

//Todo: Create struct Date
struct Date {
	int month = 1;
	int day = 1;
	int year = 1970;

	void print() {
		cout << month << "/" << day << "/" << year << endl;
	}
};

//Todo: Create struct Person and test functions
struct Person {
	long id = 0;
	string name = "John Doe";
	Date birthDate;
};


void printInfo(Person p) {
	cout << "\nRecieved p by value in printInfo()" << endl;
	cout << "Name: " << p.name << ", id: " << p.id << ", DOB: ";
	p.birthDate.print();
	p.name = "Superman";
}

void printInfoReference(Person& p) {
	cout << "\nRecieved p by reference in printInfo()" << endl;
	cout << "Name: " << p.name << ", id: " << p.id << ", DOB: ";
	p.birthDate.print();
	p.name = "Spiderman";
}

void printInfoPointer(Person* p) {
	cout << "\nRecieved p by pointer in printInfo()" << endl;
	cout << "Name: " << (*p).name << ", id: " << (*p).id << ", DOB: ";
	(*p).birthDate.print();
	(*p).name = "Batman";
}

Person createPerson() {
	Person p{ 9876L, "Joe Black", {8, 22, 1972} };
	return p;
}

Person& createPersonReferenceOnStack() {
	Person p{ 9876L, "Joe Black", {8, 22, 1972} };
	return p;
}

Person& createPersonReferenceOnHeap() {
	Person* p = new Person;
	(*p).id = 4572L;
	(*p).name = "Steve Jobs";
	(*p).birthDate.month = 7;
	(*p).birthDate.day = 20;
	(*p).birthDate.year = 1965;

	cout << "Address: " << p << endl;
	return *p;
}

Person* createPersonPointer() {
	Person* p = new Person;
	(*p).id = 8888L;
	(*p).name = "Bill Gates";
	(*p).birthDate.month = 7;
	(*p).birthDate.day = 20;
	(*p).birthDate.year = 1961;

	return p;
}

//int main() {
int structureBasicsMain() {
	Person p;
	//Todo: Assign data to struct variable p and display on screen
	
	p.id = 12345L;
	p.name = "Elon Musk";
	p.birthDate.month = 5;
	p.birthDate.day = 20;
	p.birthDate.year = 1971;
	cout << "Name: " << p.name << ", id: " << p.id << ", DOB: "; // << p.birthDate.month << "/" << p.birthDate.day << "/" << p.birthDate.year << endl;
	p.birthDate.print();

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
	Person pa[3];
	pa[0] = p;
	pa[1] = { 7777L, "Kamala Harris" };
	pa[2] = createPerson();

	for (Person p : pa) {
		cout << p.name << " ";
	}
	cout << endl;

	return 0;
}