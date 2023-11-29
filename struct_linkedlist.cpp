#include <iostream>

using namespace std;

int main() {
//int structLinkedlistMain() {
	struct link {
		int id;
		string name;
		link* next = nullptr;
	};

	link first = { 1, "Joe Biden" };
	link second = { 2, "Kamala Harris" };
	first.next = &second;
	link third = { 3, "Anthony Blinken" };
	second.next = &third;

	link* c = &first;
	while (c != nullptr) {
		cout << c->name << " -> ";
		c = c->next;
	}
	cout << endl;

	return 0;
}