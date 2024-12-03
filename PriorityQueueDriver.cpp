#include <iostream>
#include "PriorityQueue.h"

using namespace std;

void removeItem(PriorityQueue* q) {
	long x = q->remove();
	cout << "Removed: " << x << ", Queue: ";
	q->print();
}

int main() {
	PriorityQueue* q = new PriorityQueue(5);

	q->insert(92);
	q->insert(13);
	q->insert(5);
	q->insert(57);
	q->insert(11);

	cout << "Size: " << q->getSize() << ", Queue: ";
	q->print();
	cout << endl;

	removeItem(q);
	removeItem(q);
	removeItem(q);

	return 0;
}