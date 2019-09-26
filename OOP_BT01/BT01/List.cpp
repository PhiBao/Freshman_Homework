#include "List.h"
#include"CTKH.h"
#include<iostream>
#include<string>
using namespace std;

List::List(int size)
{
	this->size = size;
	this->data = new CTKH[this->size];
}

List::~List()
{
	delete[] this->data;
}
CTKH& List::operator[](int i)
{
	static CTKH *temp = NULL;
	return (i >= 0 && i < this->size) ? *(this->data + i) : *temp;
}
ostream& operator<<(ostream &o, const List &p)
{
	for (int i = 0; i < p.size; i++)
		cout << p.data[i] << endl;
	return o;
}
istream& operator>>(istream &i, List &p)
{
	for (int i = 0; i < p.size; i++)
		cin >> p.data[i];
	return i;
}
void List::Show()
{
	cout << "______________________________________________________________________" << endl;
	for (int i = 0; i < this->size; i++)
		cout << this->data[i] << endl;
	cout << "______________________________________________________________________" << endl;
}
void List::Add(const int& legth)
{
	CTKH g;
	if ((legth > this->size) || (legth < 0)) cout << "---illegal---" << endl;
	else if (legth == this->size)
	{
		cout << "Input data of objective add:" << endl;
		cin >> g;
		CTKH *p = new CTKH[this->size];
		for (int i = 0; i < this->size; i++)
			p[i] = this->data[i];
		delete[] this->data;
		this->size++;
		this->data = new CTKH[this->size];
		for (int i = 0; i < this->size - 1; i++)
			this->data[i] = p[i];
		this->data[this->size - 1] = g;
	}
	else
	{
		cout << "Input data of objective add:" << endl;
		cin >> g;
		CTKH *p = new CTKH[this->size];
		for (int i = 0; i < this->size; i++)
			p[i] = this->data[i];
		delete[] this->data;
		this->size++;
		this->data = new CTKH[this->size];
		for (int i = 0; i < legth; i++)
			this->data[i] = p[i];
		for (int i = legth + 1; i < this->size; i++)
			this->data[i] = p[i - 1];
		this->data[legth] = g;
	};
}
void List::Update(const int& legth)
{
	CTKH g;
	cout << "Input update objective:" << endl;
	cin >> g;
	this->data[legth].WorkCode = g.WorkCode;
	this->data[legth].Year = g.Year;
	this->data[legth].Area = g.Area;
}

void List::Delete(const int& legth)
{
	if ((legth < 0) || (legth >= this->size)) cout << "---illegal---" << endl;
	else
	{
		CTKH *p = new CTKH[this->size - 1];
		for (int i = 0; i < legth; i++)
			p[i] = this->data[i];
		for (int i = legth; i < this->size - 1; i++)
			p[i] = this->data[i + 1];
		delete[] this->data;
		this->size--;
		this->data = new CTKH[this->size];
		for (int i = 0; i < this->size; i++)
			this->data[i] = p[i];
	}
}
void List::Swap(CTKH &a, CTKH &b)
{
	CTKH temp;
	temp = a;
	a = b;
	b = temp;
}
bool ascending(const int& left, const int& right)
{
	return left >= right;
}
bool descending(const int& left, const int& right)
{
	return left <= right;
}
void List::ShellSort(bool(*CompFunc)(const int&, const int&))
{
	int h = 0, j, A;
	while (h < this->size / 3) (h = h * 3 + 1);
	while (h > 0)
	{
		for (int i = h; i < this->size; i++)
		{
			A = this->data[i].Year;
			j = i;
			while ((CompFunc)(this->data[j - h].Year, A) && (j > h - 1))
			{
				Swap(this->data[j], this->data[j - h]);
				j -= h;
			};
			this->data[j].Year = A;
		};
		h = (h - 1) / 3;
	}

}
CTKH* List::InterpolationSearch(const int&a)
{
	ShellSort(ascending);
	CTKH *p = new CTKH[1];
	int left = 0;
	int right = this->size - 1;
	while ((left <= right) && (a >= this->data[left].Year) && (a <= this->data[right].Year))
	{
		double m1 = (double)(a - this->data[left].Year) / (this->data[right].Year - this->data[left].Year);
		int m2 = (right - left);
		int mid = left + m1 * m2;
		if (this->data[mid].Year == a)
		{
			*p = this->data[mid];
			return p;
		}
		else if (this->data[mid].Year < a) left = mid + 1;
		else right = mid - 1;
	}
	p = NULL;
	return p;
}