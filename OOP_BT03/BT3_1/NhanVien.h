#pragma once
#include<string>
#include"Date.h"
using namespace std;
class NhanVien
{
public:
	string StaffCode;
	string StaffName;
	Date StartDay;
	bool Sex;
	double Salary;
public:
	NhanVien(string = "TXA12769", string = "Quan", Date = (12, 5, 2015), bool = 1, double = 4000000);
	virtual ~NhanVien();
	friend ostream& operator<<(ostream&, const NhanVien&);
	friend class Node;
	friend class LinkedList;
};