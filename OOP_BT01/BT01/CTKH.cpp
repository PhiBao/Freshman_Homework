#include "CTKH.h"
#include<iostream>
#include<string>
using namespace std;
CTKH::CTKH(string WorkCode, int Year, bool Area)
{
	this->WorkCode = WorkCode;
	this->Year = Year;
	this->Area = Area;
}
CTKH::~CTKH()
{
}
ostream& operator<<(ostream &o, const CTKH &p)
{
	o << "Ma Cong Trinh:" << p.WorkCode << endl;
	o << "Nam Xuat Ban:" << p.Year << endl;
	o << "Khu Vuc Xuat Ban:" << ((p.Area == true) ? "Quoc Te" : "Trong Nuoc") << endl;
	return o;
}
istream& operator>>(istream &i, CTKH &p)
{
	cout << "Ma Cong Trinh:" << endl; i >> p.WorkCode;
	cout << "Nam Xuat Ban:" << endl; do (i >> p.Year); while (p.Year < 1900);
	cout << "Khu Vuc Xuat Ban O Quoc Te?(1/0)" << endl; i >> p.Area;
	return i;
}