#pragma once
#include<string>
#include<iostream>
using namespace std;

class CTKH
{
public:
	string WorkCode;
	int Year;
	bool Area;
public:
	CTKH(string = "TH1589", int = 1969, bool = 1);
	~CTKH();
	friend ostream& operator<<(ostream &, const CTKH &);
	friend istream& operator>>(istream &, CTKH &);
};