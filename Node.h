#pragma once
class Node
{
private:
	int id;
	long data;

	Node* leftChild;
	Node* rightChild;

	Node* parent;

public:
	Node();
	Node(int id, long data);

	int getId();
	long getData();
	Node* getLeftChild();
	Node* getRightChild();
	Node* getParent();

	void setId(int id);
	void setData(long data);
	void setLeftChild(Node* leftChild);
	void setRightChild(Node* rightChild);
	void setParent(Node* parent);

	void print();
};

