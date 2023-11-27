#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
//int LinkedListDriver() {

	LinkedList list;

	list.insertFirst(3456L, "Ronald Regan");
	list.print();

	list.insertLast(2345L, "John Adams");
	list.print();

	list.insertFirst(1234L, "George Washington");
	list.print();

	list.insertLast(2345L, "Joe Biden");
	list.print();

	list.deleteFirst();
	list.print();

	Link* found = list.find(1234L);
	if (found == nullptr) {
		cout << "Not Found!!!" << endl;
	}
	else {
		cout << "Found -- " << found->getName() << endl;
	}

	list.deleteLast();
	list.print();

	/*
	//list.insertAfter(3456L, 4567L, "George H. W. Bush");
	list.print();

	//list.deleteLink(4567L);
	list.print();

	//list.deleteLink(3456L);
	list.print();
	*/
	return 0;
}