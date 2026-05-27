#pragma once
class Stack
{
private:
	char* data;
	int top;
	int capacity;
	const int _DEFAULT_SIZE = 10;

public:
	Stack();
	Stack(int capacity);
	~Stack();

	bool push(char d);
	char pop();
	char peek();

	bool isEmpty();
	bool isFull();

	void print();
};

