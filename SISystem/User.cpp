#include "User.h"
#include "utilities.h"
#include <fstream>
#include <string>

using namespace std;

User::User() {
	id = -1;
	firstName = "";
	lastName = "";
	role = Role::Invalid;
	email = "";
	password = "";
	authenticated = false;
}

User::User(string email, string password) { 
	id = -1;
	firstName = "";
	lastName = "";
	role = Role::Invalid;
	this->email = email; 
	this->password = password; 
	authenticated = false;
}

bool User::isAuthorized() {
	return this->role == Role::Student || this->role == Role::Staff || this->role == Role::Faculty;
}

bool User::authenticate() {
	ifstream userFile(USER_FILENAME.c_str());
	if (userFile.fail()) throw USER_DATA_FILE_READ_ERROR;

	string temp;

	while (true) {
		userFile >> this->id;	//Read temp and throw away
		if (userFile.eof()) break;

		userFile >> temp; //Read first name and throw away
		this->firstName = temp;
		userFile >> this->lastName; //Read last name and throw away

		userFile >> temp; //Read email
		if (temp == this->email) {
			userFile >> temp; //Read password
			if (temp == this->password) {
				authenticated = true;

				userFile >> temp; //Read role
				if (temp == "Student")	this->role = Role::Student;
				else if (temp == "Staff") this->role = Role::Staff;
				else if (temp == "Faculty") this->role = Role::Faculty;

				break;
			}
			else {
				break;
			}
		}
		else {
			getline(userFile, temp);	//Read to the end of line and throw away
		}
	}

	return authenticated;
}