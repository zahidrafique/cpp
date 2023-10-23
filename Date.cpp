#include "Date.h"
#include "IntDate.h"
#include <string>
#include <iostream>
#include <iomanip>

//Todo: Implement basic Date functions

using namespace std;

void Date::show() {
	cout << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0')  << day << "/" << setw(4) << setfill('0') << year << endl;
}

string Date::get() {
	string d;
	d = to_string(month);
	if (month < 10)
		d.insert(0, "0");
	d = d + "/" + to_string(day);
	if (day < 10)
		d.insert(3, "0");

	d = d + "/" + to_string(year);

	return d;
}

void Date::set(int month = 1, int day = 1, int year = 1970) {
	if (month >= 1 && month <= 12)
		this->month = month;
	if (day >= 1 && day <= 31)
		this->day = day; 
	if (year >=0 && year <= 9999)
		this->year = year; 
}

bool Date::isLeapYear() {
	return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}

long Date::convert() const {
	return year * 10000 + month * 100 + day;
}

bool Date::operator==(const Date& date2) {
	return this->month == date2.month && this->day == date2.day && this->year == date2.year;
}

bool Date::operator<(const Date& date2) {
	return this->convert() < date2.convert();
}