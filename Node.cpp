#include <iostream>
#include "Node.h"

Node::Node() {
	id = 0;
	data = 0;
	leftChild = nullptr;
	rightChild = nullptr;
	parent = nullptr;
}

Node::Node(int id, long data) {
	this->id = id;
	this->data = data;
	leftChild = nullptr;
	rightChild = nullptr;
	parent = nullptr;
}

int Node::getId() {
	return id;
}

long Node::getData() {
	return data;
}

Node* Node::getLeftChild() {
	return leftChild;
}

Node* Node::getRightChild() {
	return rightChild;
}

Node* Node::getParent() {
	return parent;
}

void Node::setId(int id) {
	this->id = id;
}

void Node::setData(long data) {
	this->data = data;
}

void Node::setLeftChild(Node* leftChild) {
	this->leftChild = leftChild;
}

void Node::setRightChild(Node* rightChild) {
	this->rightChild = rightChild;
}

void Node::setParent(Node* parent) {
	this->parent = parent;
}

void  Node::print() {
	std::cout << "{" << id << ", " << data << "}";
}