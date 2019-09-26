#pragma once
#include"NhanVien.h"
class NVBC:
	public NhanVien
{
private:
	double SalaryFactor;
	double Seniority;
public:
	NVBC(string = "TXA12789", string = "Nhung", Date = (12, 5, 2015), bool = 0, double = 3.5, double = 0.1);
	~NVBC();
	friend istream& operator>>(istream&, NVBC&);
};

