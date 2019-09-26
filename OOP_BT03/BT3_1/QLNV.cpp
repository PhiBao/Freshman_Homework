#include "QLNV.h"
QLNV::QLNV(string PersonalName)
{
	this->StaffAmount = 0;
	List = new LinkedList();
	this->PersonalName = PersonalName;
}
QLNV::~QLNV()
{
	delete[] this->List;
}
void QLNV::Print()
{
	cout << "Ten ca nhan: " << this->PersonalName << endl;
	cout << "So luong nhan vien: " << this->StaffAmount + 1 << endl;
	List->Print();
}
NhanVien& QLNV::operator[](int i)
{
	static NhanVien *temp = nullptr;
	Node *PT = this->List->head;
	for (int j = 0; j < i; j++)
		PT = PT->next;
	return (i >= 0 && i < this->StaffAmount) ? PT->data : *temp;
}
void QLNV::AddTail(NhanVien data)
{
	List->AddTail(data);
	this->StaffAmount = this->List->size;
}
void QLNV::AddFirst()
{
	List->AddFirst();
	this->StaffAmount = this->List->size;
}
void QLNV::AddLast()
{
	List->AddLast();
	this->StaffAmount = this->List->size;
}
void QLNV::Add(const int &legth)
{
	List->Add(legth);
	this->StaffAmount = this->List->size;
}
void QLNV::Update(const int &legth)
{
	List->Update((*this)[legth]);
}
void QLNV::DeleteFirst()
{
	List->DeleteFirst();
	this->StaffAmount = this->List->size;
}
void QLNV::DeleteLast()
{
	List->DeleteLast();
	this->StaffAmount = this->List->size;
}
void QLNV::Delete(const int &legth)
{
	List->Delete(legth);
	this->StaffAmount = this->List->size;
}
void QLNV::Sort()
{
	List->Sort();
}
Node* QLNV::Search(double Salary)
{
	return List->Search(Salary);
}