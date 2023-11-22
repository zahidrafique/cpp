#pragma once
#include <map>
#include <string>

class ExceptionHandler
{
private:
	std::map<int, std::string> errorMap;

public:
	ExceptionHandler();
	std::string what(int);

};

