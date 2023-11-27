#include "LinkedList.h"
#include <iostream>

using namespace std;

bool LinkedList::isEmpty() {
	return first == nullptr;
}

void LinkedList::insertFirst(long id, string name) {
	Link* link = new Link(id, name);
	this->insertFirst(link);
}

void LinkedList::insertFirst(Link* link) {
	if (!isEmpty()) {
		link->setNextLink(first);	//Store pointer of current first in the next of new link
		first->setPrevLink(link);
	}
	else {
		last = link;
	}

	first = link;
}

void LinkedList::deleteFirst() {
	if (isEmpty())
		return;

	Link* temp = first;
	if (first->getNextLink() == nullptr) {	//Only link left in the list
		first = nullptr;
		last = nullptr;
	}
	else {
		first = first->getNextLink();
		first->setPrevLink(nullptr);
	}

	delete temp;
}

void LinkedList::insertLast(long id, string name) {
	Link* link = new Link(id, name);
	this->insertLast(link);
}

void LinkedList::insertLast(Link* link) {
	if (!isEmpty()) {
		link->setPrevLink(last);
		last->setNextLink(link);	//Store pointer of current first in the next of new link
	}
	else {
		first = link;
	}

	last = link;
}


void LinkedList::deleteLast() {
	if (isEmpty())
		return;

	Link* temp = last;
	if (first->getNextLink() == nullptr) {	//Only link left in the list
		first = nullptr;
		last = nullptr;
	}
	else {
		last = last->getPrevLink();
		last->setNextLink(nullptr);
	}

	delete temp;
}

Link* LinkedList::find(long id) {
	Link* current = first;

	while (current != nullptr) {
		if (id == current->getId()) {
			return current;
		}

		current = current->getNextLink();
	}

	return nullptr;
}

void LinkedList::print() {
	Link* current = first;

	while (current != nullptr) {
		cout << current->getName() << " -> ";
		current = current->getNextLink();
	}
	cout << endl;
}
