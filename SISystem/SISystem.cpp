#include "SISystem.h"
#include <fstream>
#include <iostream>

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
	ofstream gradeFile(GRADE_FILENAME.c_str());
	if (gradeFile.fail()) throw GRADE_DATA_FILE_WRITE_ERROR;

	for (auto it = students.begin(); it != students.end(); it++) {
		long id = it->first;
		Student* s = it->second;

		for (int i = 0; i < s->getCourseCount(); i++) {
			gradeFile << id << " " << s->getCourseGrades(i) << endl;
		}
	}

	gradeFile.close();
}

SISystem::SISystem() {
	gradesUpdated = false;

	loadCoursesData();
	loadStudentsData();
}

SISystem::~SISystem() {
	if (gradesUpdated) {
		updateGradesFile();
	}

	
	for (auto it = students.begin(); it != students.end(); it++) {
		Student* s = it->second;
		delete s;
	}
	
	for (auto it = courses.begin(); it != courses.end(); it++) {
		Course* cp = it->second;
		delete cp;
	}

	delete user;
}

void SISystem::printReport() {
	for (auto it = students.begin(); it != students.end(); it++) {
		Student* s = it->second;

		cout << s->getReport() << endl;
	}
}

void SISystem::printReport(long id) {
	Student* s = students[id];
	
	if (s == nullptr) {
		cout << "Student with id: " << id << " does not exist!" << endl;
	}
	else {
		cout << s->getReport();
	}
}

void SISystem::addCourse(long id, std::string code, char grade) {
	Student* s = students[id];
	
	if (s == nullptr) {
		cout << "Student with id: " << id << " does not exist!" << endl;
	}
	else {
		Course* c = courses[code];

		if (c == nullptr) {
			cout << "Invalid course code: " << code << endl;
		}
		else {
			s->addCourse(c, grade);
			gradesUpdated = true;
		}
	}
}

void SISystem::updateGrade(long id, std::string code, char grade) {
	Student* s = students[id];

	if (s == nullptr) {
		cout << "Student with id: " << id << " does not exist!" << endl;
	}
	else {
		Course* c = courses[code];

		if (c == nullptr) {
			cout << "Invalid course code: " << code << endl;
		}
		else {
			s->updateGrade(code, grade);
			gradesUpdated = true;
		}
	}
}

void SISystem::handleRequest(char option) {
	if (user->isAuthorized()) {
		if (option == 'p' && (user->getRole() == Role::Student || user->getRole() == Role::Staff || user->getRole() == Role::Faculty)) {
			if (user->getRole() == Role::Student) {
				printReport(user->getId());
			}
			else {
				long id;
				cout << "Please enter the student Id: ";
				cin >> id;

				printReport(id);
			}
		}
		else if (option == 'a' && (user->getRole() == Role::Staff || user->getRole() == Role::Faculty)) {
			printReport();
		}
		else if ((option == 'c' || option == 'u') && user->getRole() == Role::Faculty) {
			long id;
			string code;
			char grade;

			cout << "Pleaes enter the student id: ";
			cin >> id;
			cout << "Please enter the course code: ";
			cin >> code;
			cout << "Please enter the grade: ";
			cin >> grade;

			if (option == 'c') {
				addCourse(id, code, grade);
			}
			else {
				updateGrade(id, code, grade);
			}
		}
		else if (option == 'q') {
			exit(0);
		}
		else {
			throw INVALID_REQUEST_OPTION;
		}
	}
}

bool SISystem::login() {
	string email, password;
	cout << "Please enter your email: ";
	cin >> email;
	cout << "Please enter your password: ";
	cin >> password;

	User* u = new User(email, password);
	if (u->authenticate()) {
		cout << "Welcome " << u->getFirstName() << " " << u->getLastName() << endl << endl;
		user = u;
		printMenu();
		return true;
	}
	else {
		cout << "Please check your email & password and try again!!!" << endl;
	}

	return false;
}

void SISystem::printMenu() {
	if (user->isAuthorized()) {
		cout << "Choose one of the options below:" << endl;
		cout << "\tType p for print report" << endl;
		if (user->getRole() == Role::Staff || user->getRole() == Role::Faculty) {
			cout << "\tType a for print report for all students" << endl;
		}
		
		if (user->getRole() == Role::Faculty) {
			cout << "\tType c to add a new course for a student" << endl;
			cout << "\tType u to update the grade for a student" << endl;
		}

		cout << "\tType q for Quit" << endl;
	}
	else {
		cout << "You are not authroized to perform any operations!!!" << endl;
	}
}