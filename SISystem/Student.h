#pragma once
#include "User.h"
#include "Course.h"
#include <vector>

class Student : public User
{
private:
	std::vector<Course*> courses;
	std::vector<char> grades;

	double getNumericGrade(char letterGrade);
	int getTotalCourseCredits();

public:
	//Student() {}
	Student(long, std::string, std::string);

	void addCourse(Course*, char);
	void updateGrade(std::string, char);

	std::string getReport();
	double getGPA();

	std::vector<char> getCourseGrades();
};

