#include "Link.h"

Link::Link() {
	id = 0;
	name = "";
	next = nullptr;
	prev = nullptr;
}

Link::Link(long id, std::string name) {
	this->id = id;
	this->name = name;
	this->next = nullptr;
	this->prev = nullptr;
}

void Link::setId(long id) {
	this->id = id;
}

void Link::setName(std::string name) {
	this->name = name;
}

void Link::setNextLink(Link* next) {
	this->next = next;
}

void Link::setPrevLink(Link* prev) {
	this->prev = prev;
}

long Link::getId() {
	return id;
}

std::string Link::getName() {
	return name;
}

Link* Link::getNextLink() {
	return next;
}

Link* Link::getPrevLink() {
	return prev;
}
