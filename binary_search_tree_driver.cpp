#include <iostream>
#include "BST.h"

using namespace std;

int main() {
	BST* bst = new BST();

	bst->insert(10, 1000);
	bst->insert(5, 2000);
	bst->insert(15, 3000);

	/*
	Node* found = bst->getMin();
	if (found == nullptr) {
		cout << "Node not found!" << endl;
	}
	else {
		cout << "Found: ";
		found->print();
	}
	cout << endl << endl;

	bst->inOrderTraverse();

	bst->update(15, 5000);
	*/

	bst->inOrderTraverse();
	bst->deleteNode(10);
	bst->inOrderTraverse();

	return 0;
}