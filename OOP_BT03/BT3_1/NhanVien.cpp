#include "NhanVien.h"
NhanVien::NhanVien(string StaffCode, string StaffName, Date StartDay, bool Sex, double Salary)
{
	this->StaffCode = StaffCode;
	this->StaffName = StaffName;
	this->StartDay = StartDay;
	this->Sex = Sex;
	this->Salary = Salary;
}
NhanVien::~NhanVien()
{
}
ostream& operator<<(ostream &o, const NhanVien &p)
{
	o << "Ma nhan vien: " << p.StaffCode << endl;
	o << "Ten nhan vien: " << p.StaffName << endl;
	o << "Ngay nhan vao lam viec: " << p.StartDay << endl;
	o << "Gioi tinh: " << ((p.Sex == true) ? "Nu" : "Nam") << endl;
	o << "Luong: " << p.Salary << endl;
	return o;
}
