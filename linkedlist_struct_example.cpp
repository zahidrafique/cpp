#include <iostream>

using namespace std;

//int main() {
int linkedListStructuresMain() {
	//Todo: Create struct Person
	struct Person {
		long id = 0L;
		string name = "Unknown";
		Person* next = nullptr;
	};


	//Todo: Create linked list of persons & display

	Person p1 = {1, "Tom"};
	Person p2 = { 2, "John" };
	Person p3 = { 3, "Garry" };

	p1.next = &p2;
	p2.next = &p3;

	Person* current = &p1;

	while (current != nullptr) {
		cout << current->name << "->";
		current = current->next;
	}


	return 0;
}