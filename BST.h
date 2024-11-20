#pragma once

#include "Node.h"

class BST
{
private:
	Node* root;
	void inOrderRecurse(Node* node);
	Node* getInOrderSuccessor(Node* node);
	void replaceChild(Node* node, Node* newChild);

public:
	BST();
	
	bool isEmpty();

	void insert(int id, long data);
	void insert(Node* node);

	bool update(int id, long newData);

	Node* search(int id);

	Node* getMin();
	Node* getMax();

	void inOrderTraverse();

	void deleteNode(Node* node);
	void deleteNode(int id);
};

