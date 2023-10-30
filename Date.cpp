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

string Date::get() const {
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

int Date::dayOfWeek() {
	int mm = this->month;
	int yy = this->year;

	if (mm < 3) {
		mm += 12;
		yy--;
	}

	int century = int(yy / 100);
	yy %= 100;

	int T = this->day + int(26 * (mm + 1) / 10) + yy + int(yy / 4) + int(century / 4) - 2 * century;

	int dd = T % 7;
	if (dd < 0) {
		dd += 7;
	}

	return dd;
}


bool Date::operator==(const Date& date2) {
	return this->month == date2.month && this->day == date2.day && this->year == date2.year;
}

bool Date::operator<(const Date& date2) {
	return this->convert() < date2.convert();
}

ostream& operator<<(ostream& xout, const Date& date) {
	xout << date.get();

	return xout;
}

istream& operator>>(istream& xin, Date& date) {
	string s;
	xin >> s;		//In format: mm/dd/yyyy

	int b = 0;
	int e = s.find('/');
	string m = s.substr(b, e);
	b = e + 1;
	e = s.find('/', b);
	string d = s.substr(b, e - b);
	b = e + 1;
	string y = s.substr(b, s.size() - b);

	date.month = atoi(m.c_str());
	date.day = atoi(d.c_str());
	date.year = atoi(y.c_str());

	return xin;
}