#include <iostream>
#include "BST.h"

BST::BST() {
	root = nullptr;
}

bool BST::isEmpty() {
	return root == nullptr;
}

void BST::insert(int id, long data) {
	Node* node = new Node(id, data);
	insert(node);
}

void BST::insert(Node* node) {
	if (isEmpty()) {
		root = node;
		return;
	} 

	Node* current = root;
	Node* parent = nullptr;
	bool isLeft = false;

	while (current != nullptr) {
		parent = current;

		if (node->getId() < current->getId()) {
			current = current->getLeftChild();
			isLeft = true;
		} else {
			current = current->getRightChild();
			isLeft = false;
		}
	}

	if (isLeft) {
		parent->setLeftChild(node);
	}
	else {
		parent->setRightChild(node);
	}

	node->setParent(parent);
}

bool BST::update(int id, long newData) {
	Node* node = search(id);
	if (node == nullptr) {
		return false;
	}

	node->setData(newData);
	return true;
}

Node* BST::search(int id) {
	Node* current = root;

	while (current != nullptr) {
		//current->print();
		//std::cout << " -> ";

		if (id == current->getId()) {
			//std::cout << std::endl;
			return current;
		}
		else if (id < current->getId()) {
			current = current->getLeftChild();
		}
		else {
			current = current->getRightChild();
		}
	}

	//std::cout << std::endl;
	return nullptr;
}

Node* BST::getMin() {
	Node* current = root;

	if (isEmpty()) {
		return nullptr;
	}

	while (current->getLeftChild() != nullptr) {
		current = current->getLeftChild();
	}

	return current;

}

Node* BST::getMax() {
	Node* current = root;
	Node* maximum = nullptr;

	while (current != nullptr) {
		maximum = current;
		current = current->getRightChild();
	}

	return maximum;
}

void BST::inOrderRecurse(Node* node) {
	if (node == nullptr) {			//Base case for recursion
		return;			
	}

	inOrderRecurse(node->getLeftChild());
	node->print();
	std::cout << " -> ";
	inOrderRecurse(node->getRightChild());
}

void BST::inOrderTraverse() {
	inOrderRecurse(root);
	std::cout << std::endl << std::endl;

}

Node* BST::getInOrderSuccessor(Node* node) {
	Node* successor = node->getRightChild();

	while (successor->getLeftChild() != nullptr) {
		successor = successor->getLeftChild();
	}

	return successor;
}

void BST::replaceChild(Node* node, Node* newChild) {
	Node* parent = node->getParent();
	if (parent != nullptr) {		//For all non-root nodes
		if (parent->getLeftChild() == node) {
			parent->setLeftChild(newChild);
		}
		else {
			parent->setRightChild(newChild);
		}
	}
	else {
		root = newChild;
	}

	if (newChild != nullptr) {
		newChild->setParent(parent);
	}
}

void BST::deleteNode(Node* node) {
	if (node == nullptr || root == nullptr) {
		return;
	}

	if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr) {	//Case 2: when delete node is a leaf
		replaceChild(node, nullptr);
	}	
	else if (node->getLeftChild() == nullptr) {		//Case 3a: when delete node has only right child
		replaceChild(node, node->getRightChild());
	} 
	else if (node->getRightChild() == nullptr) {		//Case 3b:when delete node has only left child
		replaceChild(node, node->getLeftChild());
	}
	else {			//Case 4: when delete node has both children
		Node* successor = getInOrderSuccessor(node);

		if (node->getRightChild() != successor) {
			successor->getParent()->setLeftChild(successor->getRightChild());
			successor->getRightChild()->setParent(successor->getParent());

			successor->setRightChild(node->getRightChild());
			node->getRightChild()->setParent(successor);
		}

		successor->setLeftChild(node->getLeftChild());
		node->getLeftChild()->setParent(successor);

		successor->setParent(node->getParent());
	}

	delete node;
}

void BST::deleteNode(int id) {
	Node* node = search(id);
	if (node != nullptr) {
		deleteNode(node);
	}
}