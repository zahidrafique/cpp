#pragma once
#include <string>

class Link
{
private:
	long id;
	std::string name;
	Link* next;
	Link* prev;

public:
	Link();
	Link(long, std::string);

	void setId(long);
	void setName(std::string);
	void setNextLink(Link*);
	void setPrevLink(Link*);

	long getId();
	std::string getName();
	Link* getNextLink();
	Link* getPrevLink();
};


