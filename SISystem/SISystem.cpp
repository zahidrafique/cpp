#include "SISystem.h"
#include <fstream>

using namespace std;

void SISystem::loadStudentsData() {
	ifstream gradeFile(GRADE_FILENAME.c_str());
	if (gradeFile.fail()) throw COURSE_DATA_FILE_READ_ERROR;

	long id = 0, current_id = -1;
	string code;
	char grade;

	while (true) {
		gradeFile >> id;
		if (gradeFile.eof()) break;

		gradeFile >> code;
		gradeFile >> grade;

		Course* course = courses[code];

		if (id != current_id) {
			ifstream userFile(USER_FILENAME.c_str());
			if (userFile.fail()) throw USER_DATA_FILE_READ_ERROR;

			long user_id = -1;
			string firstName, lastName, temp;

			while (true) {
				userFile >> user_id;
				if (userFile.eof()) {
					user_id = -1;
					break;
				}

				userFile >> firstName;
				userFile >> lastName;
				userFile >> temp;		//Read email & ignore
				userFile >> temp;		//Read password & ignore
				userFile >> temp;		//Read role & ignore

				if (id == user_id) break;
			}

			if (user_id > 0) {
				Student* student = new Student(id, firstName, lastName);
				student->addCourse(course, grade);
				students.insert({ id, student });
			}
			else {
				throw STUDENT_DATA_MISMATCH;
			}

			current_id = id;
			userFile.close();
		}
		else {
			Student* student = students[id];
			student->addCourse(course, grade);
		}
	}

	gradeFile.close();
}

void SISystem::loadCoursesData() {
	ifstream courseFile(COURSE_FILENAME.c_str());
	if (courseFile.fail()) throw COURSE_DATA_FILE_READ_ERROR;

	string code;
	int credits;

	while (true) {
		courseFile >> code;
		if (courseFile.eof()) break;

		courseFile >> credits;

		Course* course = new Course(code, credits);
		courses.insert({ code, course });		//equivalent to courses.insert(pair<string, Course*>(code, course));
	}

	courseFile.close();
}

void SISystem::updateGradesFile() {
	
}

SISystem::SISystem() {
	loadCoursesData();
	loadStudentsData();
}

SISystem::~SISystem() {
	
	for (auto it = courses.begin(); it != courses.end(); ) {
		Course* cp = it->second;
		courses.erase(it++);

		delete cp;
	}
	
}
