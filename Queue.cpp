#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
	data = new long[DEFAULT_SIZE];
	this->capacity = DEFAULT_SIZE;
	//Queue(DEFAULT_SIZE);
}

Queue::Queue(int size) {
	data = new long[size];
	this->capacity = size;
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

	if (isEmpty()) {
		front = 0;
		rear = 0;
	} else {
		if (rear == capacity - 1) {
			rear = 0;
		}
		else {
			rear++;
		}
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

	if (isEmpty()) {
		front = -1;
		rear = -1;
	}
	else {
		front++;

		if (front >= capacity) {
			front = 0;
		}
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
	return dataSize == capacity;
}

int Queue::getSize() {
	return dataSize;
}

void Queue::print() {
	cout << "[";
	if (!isEmpty()) {
		int endIndex = (rear >= front) ? rear : capacity - 1;

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