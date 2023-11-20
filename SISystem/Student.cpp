#include "Student.h"

using namespace std;

double Student::getNumericGrade(char letterGrade) {
	switch (letterGrade) {
	case 'A':
		return 4.0;
	case 'B':
		return 3.0;
	case 'C':
		return 2.0;
	case 'D':
		return 1.0;
	}

	return 0.0;
}

int Student::getTotalCourseCredits() {
	int total = 0;
	for (Course* c : courses) {
		total += c->getCredits();
	}

	return total;
}

int Student::getCourseCount() {
	return courses.size();
}

Student::Student(long id, string firstName, string lastName) {
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
}

void Student::addCourse(Course* course, char grade) {
	courses.push_back(course);
	grades.push_back(grade);
}

void Student::updateGrade(string code, char grade) {
	for (int i = 0; i < courses.size(); i++) {
		if (code == courses[i]->getCode()) {
			grades[i] = grade;
			break;
		}
	}
}

string Student::getReport() {
	string report = "";

	report += "Student Name: " + firstName + " " + lastName;
	report += "\nStudent ID Number: " + to_string(id);
	report += "\n\nCourse Code\tCourse Credits\tCourse Grade";
	report += "\n-----------------------------------------------";
	
	for (int i = 0; i < courses.size(); i++) {
		string c = courses[i]->getCode();
		if (c.size() < 10) {
			c += "\t";
		}

		report += "\n" + c + "\t\t" + to_string(courses[i]->getCredits()) + "\t\t" + grades[i];
	}

	report += "\n\nTotal Semester Course Credits Completed: " + to_string(getTotalCourseCredits());
	report += "\nSemester GPA: " + to_string(getGPA()) + "\n";

	return report;
}

double Student::getGPA() {
	double gradePoints = 0.0;
	int totalCredits = 0;

	for (int i = 0; i < courses.size(); i++) {
		gradePoints += courses[i]->getCredits() * getNumericGrade(grades[i]);
		totalCredits += courses[i]->getCredits();
	}

	return gradePoints / totalCredits;
}

std::string Student::getCourseGrades(int index) {
	return courses[index]->getCode() + " " + grades[index];
}