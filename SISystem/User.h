#pragma once
#include <string>
#include "utilities.h"

class User
{
protected:
	long id;
	std::string firstName;
	std::string lastName;
	Role role;

private:
	std::string email;
	std::string password;
	bool authenticated;

public:
	User();
	User(std::string email, std::string password);

	long getId() { return id; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	Role getRole() { return role; }

	void setId(long id) { this->id = id; }
	void setFirstName(std::string firstName) { this->firstName = firstName; }
	void setLastName(std::string lastName) { this->lastName = lastName; }
	void setEmail(std::string email) { this->email = email; }
	void setPassword(std::string password) { this->password = password; }
	void setRole(Role role) { this->role = role; }

	bool isAuthenticated() { return authenticated; }
	bool isAuthorized();
	bool authenticate();
};

