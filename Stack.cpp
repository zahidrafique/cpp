#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
	this->data = new char[_DEFAULT_SIZE];
	this->capacity = _DEFAULT_SIZE;
	this->top = -1;
}

Stack::Stack(int capacity) {
	this->data = new char[capacity];
	this->capacity = capacity;
	this->top = -1;
}

Stack::~Stack() {
	if (data != nullptr) {
		delete[] data;
	}
}

bool Stack::push(char d) {
	if (isFull()) {
		return false;
	}

	data[++top] = d;

	return true;
}

char Stack::pop() {
	if (isEmpty()) {
		return '\0';
	}

	char temp = data[top];
	top--;

	return temp;
}

char Stack::peek() {
	if (isEmpty()) {
		return '\0';
	}

	return data[top];
}

bool Stack::isEmpty() {
	return top < 0;
}

bool Stack::isFull() {
	return top == (capacity - 1);
}

void Stack::print() {
	for (int i = top; i >= 0; i--) {
		cout << data[i] << endl;
	}
}