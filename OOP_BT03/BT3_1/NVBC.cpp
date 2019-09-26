#include "NVBC.h"
NVBC::NVBC(string StaffCode, string StaffName, Date StartDay, bool Sex, double SalaryFactor, double Seniority) :
	NhanVien(StaffCode, StaffName, StartDay, Sex)
{
	this->SalaryFactor = SalaryFactor;
	this->Seniority = Seniority;
	this->Salary = SalaryFactor * 1390000 * (1 + Seniority);
}
NVBC::~NVBC()
{
}
istream& operator>>(istream &i, NVBC &p)
{
	int temp;
	cout << "Ma nhan vien: "; i >> p.StaffCode;
	cout << "Ten nhan vien: "; i >> p.StaffName;
	cout << "Lam vien lan dau khi: "; i >> p.StartDay;
	cout << "Gioi tinh(Nam/Nu)(0/1):  "; i >> p.Sex;
	cout << "He so luong: "; do (i >> p.SalaryFactor); while ((p.SalaryFactor < 2.34) || (p.SalaryFactor > 10));
	cout << "So nam lam viec: "; i >> temp;
	(temp < 5) ? (p.Seniority = 0) : (p.Seniority = temp / 100);
	return i;
}