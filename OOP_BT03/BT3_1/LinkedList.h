#pragma once
#include"Node.h"
class LinkedList
{
public:
	Node *head;
	Node *tail;
	int size;
public:
	LinkedList();
	~LinkedList();
	int IsEmpty();
	Node* Create(NhanVien);
	void Print();
	void AddTail(NhanVien);
	void AddFirst();
	void AddLast();
	void Add(const int&);
	void Update(NhanVien &p);
	void DeleteFirst();
	void DeleteLast();
	void Delete(const int&);
	void Sort();
	Node* Search(double);
};

