#pragma once
#include"NhanVien.h"
class NVHD:
	public NhanVien
{
private:
	double DailySalary;
public:
	NVHD(string = "TXA12768", string = "Luan", Date = (12, 5, 2015), bool = 1, double = 100000);
	virtual ~NVHD();
	friend istream& operator>>(istream&, NVHD&);
};

