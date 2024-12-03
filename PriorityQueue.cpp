#include "PriorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue() {
	data = new long[DEFAULT_SIZE];
	this->size = DEFAULT_SIZE;
}

PriorityQueue::PriorityQueue(int size) {
	data = new long[size];
	this->size = size;
}

PriorityQueue::~PriorityQueue() {
	if (data != nullptr) {
		delete[] data;
	}
}

void PriorityQueue::insert(long value) {
	if (isFull()) {
		cout << "Internal storage is Full!!" << endl;
		return;				//Extend array size in this case
	}

	if (isEmpty()) {
		data[0] = value;
	} 
	else {
		int i = dataSize;

		while (i >= 0 && data[i-1] < value) {
			data[i] = data[i-1];
			i--;
		}

		data[i] = value;
	}

	dataSize++;
}

long PriorityQueue::remove() {
	if (isEmpty()) {
		cout << "Queue is empty!!!" << endl;
		return 0;
	}
	long temp = data[--dataSize];
	;

	return temp;
}

long PriorityQueue::peek() {
	if (isEmpty()) {
		cout << "Queue is empty!!!" << endl;
		return 0;
	}

	return data[dataSize-1];
}

bool PriorityQueue::isEmpty() {
	return dataSize == 0;
}
bool PriorityQueue::isFull() {
	return dataSize == size;
}

int PriorityQueue::getSize() {
	return dataSize;
}

void PriorityQueue::print() {
	cout << "[";
	if (!isEmpty()) {
		for (int i = 0; i < dataSize; i++) {
			if (i > 0) {
				cout << ", ";
			}
			cout << data[i];
		}
	}
	cout << "]" << endl;
}