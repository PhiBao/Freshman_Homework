#include "Date.h"
Date::Date(int day,int month,int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date::~Date()
{
}
ostream& operator<<(ostream &o, const Date &p)
{
	o << p.day << "/" << p.month << "/" << p.year;
	return o;
}
istream& operator>>(istream &i, Date &p)
{
	cout << "Ngay di lam: "; do (i >> p.day); while (p.day > 31);
	cout << "Thang di lam: "; do (i >> p.month); while (p.month > 12);
	cout << "Nam di lam: "; do (i >> p.year); while (p.year < 1950 || p.year > 2018);
	return i;
}
