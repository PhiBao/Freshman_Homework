#pragma once
#include"CTKH.h"
#include<iostream>
#include<string>
using namespace std;
class List
{
public:
	CTKH *data;
	int size;
public:
	List(int = 0);
	~List();
	CTKH& operator[](int);
	friend ostream& operator<<(ostream &, const List &);
	friend istream& operator>>(istream &, List &);
	void Show();
	void Add(const int&);
	void Update(const int&);
	void Delete(const int&);
	void Swap(CTKH &, CTKH &);
	void ShellSort(bool(*)(const int&, const int&));
	CTKH* InterpolationSearch(const int&);
};