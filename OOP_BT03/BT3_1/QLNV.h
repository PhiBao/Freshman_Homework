#pragma once
#include"LinkedList.h"
class QLNV
{
public:
	string PersonalName;
	LinkedList *List;
	int StaffAmount;
public:
	QLNV(string = "Tran Mua Phi Bao");
	virtual ~QLNV();
	void Print();
	NhanVien& operator[](int);
	void AddTail(NhanVien);
	void AddFirst();
	void AddLast();
	void Add(const int&);
	void Update(const int&);
	void DeleteFirst();
	void DeleteLast();
	void Delete(const int&);
	void Sort();
	Node* Search(double);
};

