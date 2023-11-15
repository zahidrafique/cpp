#include "Course.h"

Course::Course(std::string code, int credits) {
	this->code = code;
	this->credits = credits;
}

std::string Course::getCode() {
	return code;
}

int Course::getCredits() {
	return credits;
}