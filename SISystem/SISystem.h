#pragma once
#include "User.h"
#include "Student.h"
#include "Course.h"
#include <map>

class SISystem
{
private:
	User* user;
	bool gradesUpdated;
	std::map<long, Student*> students;
	std::map<std::string, Course*> courses;

	void loadStudentsData();
	void loadCoursesData();
	void updateGradesFile();

public:
	SISystem();
	~SISystem();

	void printReport();
	void printReport(long);
	void addCourse(long, std::string, char);
	void updateGrade(long, std::string, char);

	void handleRequest(char);
	bool login();
	void printMenu();

};

