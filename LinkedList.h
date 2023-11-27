#pragma once
#include "Link.h"

class LinkedList
{
private:
	Link* first;
	Link* last;

public:
	LinkedList() { first = nullptr; last = nullptr; }

	bool isEmpty();

	void insertFirst(long, std::string);
	void insertFirst(Link*);
	void deleteFirst();

	void insertLast(long, std::string);
	void insertLast(Link*);
	void deleteLast();

	Link* find(long);
	void print();
};


