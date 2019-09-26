#include "NVHD.h"
NVHD::NVHD(string StaffCode, string StaffName, Date StartDay, bool Sex, double DailySalary) :
	NhanVien(StaffCode, StaffName, StartDay, Sex)
{
	this->DailySalary = DailySalary;
	this->Salary = DailySalary * 20;
}
NVHD::~NVHD()
{
}
istream& operator>>(istream &i, NVHD &p)
{
	cout << "Ma nhan vien: "; i >> p.StaffCode;
	cout << "Ten nhan vien: "; i >> p.StaffName;
	cout << "Lam vien lan dau khi: "; i >> p.StartDay;
	cout << "Gioi tinh:(Nam/Nu)(0/1) "; i >> p.Sex;
	cout << "Luong cong nhat:"; i >> p.DailySalary;
	return i;
}
