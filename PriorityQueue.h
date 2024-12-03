#pragma once
class PriorityQueue
{
public:
	const int DEFAULT_SIZE = 10;

private:
	int size;
	long* data = nullptr;
	int dataSize = 0;

public:
	PriorityQueue();
	PriorityQueue(int size);
	~PriorityQueue();

	void insert(long value);
	long remove();
	long peek();

	bool isEmpty();
	bool isFull();

	int getSize();

	void print();
};

