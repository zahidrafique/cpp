#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
	data = new long[DEFAULT_SIZE];
	this->size = DEFAULT_SIZE;
	//Queue(DEFAULT_SIZE);
}

Queue::Queue(int size) {
	data = new long[size];
	this->size = size;
}

Queue::~Queue() {
	if (data != nullptr) {
		delete[] data;
	}
}

void Queue::insert(long value) {
	if (isFull()) {
		cout << "Internal storage is Full!!" << endl;
		return;				//Extend array size in this case
	}

	if (rear == size - 1) {
		rear = 0;
	}
	else {
		rear++;
	}

	data[rear] = value;
	dataSize++;
}

long Queue::remove() {
	if (isEmpty()) {
		cout << "Queue is empty!!!" << endl;
		return 0;
	}
	long temp = data[front];
	dataSize--;

	if (front == size - 1) {
		front = 0;
	}
	else {
		front++;
	}

	return temp;
}

long Queue::peek() {
	if (isEmpty()) {
		cout << "Queue is empty!!!" << endl;
		return 0;
	}

	return data[front];
}

bool Queue::isEmpty() {
	return dataSize == 0;
}
bool Queue::isFull() {
	return dataSize == size;
}

int Queue::getSize() {
	return dataSize;
}

void Queue::print() {
	cout << "[";
	if (!isEmpty()) {
		int count = 0;
		int endIndex = (rear >= front) ? rear : size - 1;

		for (int i = front; i <= endIndex; i++) {
			if (i > front) {
				cout << ", ";
			}
			cout << data[i];
		}

		if (rear < front) {
			for (int i = 0; i <= rear; i++) {
				cout << ", " << data[i];
			}
		}
	}
	cout << "]";
}