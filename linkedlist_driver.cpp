#include <iostream>
#include "LinkedList.h"

using namespace std;

//int main() {
int LinkedListDriver() {

	LinkedList list;

	list.insertFirst(3456L, "Ronald Raegan");
	list.insertLast(2345L, "John Adams");
	list.print();

	list.insertFirst(1234L, "George Washington");
	list.print();

	list.insertAfter(3456L, 4567L, "George H. W. Bush");
	list.print();

	list.deleteFirst();
	list.print();

	list.deleteLast();
	list.print();

	list.deleteLink(4567L);
	list.print();

	list.deleteLink(3456L);
	list.print();

	return 0;
}