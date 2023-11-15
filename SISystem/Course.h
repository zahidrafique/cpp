#pragma once
#include <string>

class Course
{
private:
	std::string code;
	int credits;

public:
	Course(std::string code, int credits);
	std::string getCode();
	int getCredits();
};

