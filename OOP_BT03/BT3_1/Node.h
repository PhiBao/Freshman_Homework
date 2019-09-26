#pragma once
#include"NhanVien.h"
#include"NVBC.h"
#include"NVHD.h"
class Node
{
private:
	NhanVien data;
	Node *next, *prev;
public:
	Node(NhanVien);
	virtual ~Node();
	void print();
	friend class LinkedList;
	friend class QLNV;
};

