#pragma once

#include <string>
#include <iostream>

class Date {
private:
	int month;
	int day;
	int year;

public:
	//Date() { month = 1; day = 1; year = 1970; }
	//Date(int month, int day, int year) : month(month), day(day), year(year) {}
	Date(int month = 1, int day = 1, int year = 1970) { set(month, day, year); }

	void show();
	std::string get();
	void set(int, int, int);

	bool isLeapYear();
	long convert() const;

	bool operator==(const Date&);
	bool operator<(const Date&);
};