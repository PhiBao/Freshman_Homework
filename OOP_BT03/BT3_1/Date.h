#pragma once
#include <iostream>
using namespace std;
class Date
{
public:
	int day;
	int month;
	int year;
public:
	Date(int = 12, int = 5, int = 2015);
	virtual ~Date();
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
};

