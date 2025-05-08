#pragma once
class Queue
{
public:
	const int DEFAULT_SIZE = 10;

private:
	int capacity;
	long* data = nullptr;
	int front = -1;
	int rear = -1;
	int dataSize = 0;

public:
	Queue();
	Queue(int capacity);
	~Queue();

	void insert(long value);
	long remove();
	long peek();

	bool isEmpty();
	bool isFull();

	int getSize();

	void print();
};

