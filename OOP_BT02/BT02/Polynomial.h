#pragma once
#include<iostream>
using namespace std;
class Polynomial
{
private:
	int level;
	int *data;
public:
	Polynomial(int = 3, int = 1);
	~Polynomial();
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
	friend const Polynomial operator+(const Polynomial&, const Polynomial&);
	friend const Polynomial operator+(const int&, const Polynomial&);
	friend const Polynomial operator+(const Polynomial&, const int&);
	friend const Polynomial operator-(const Polynomial&, const Polynomial&);
	friend const Polynomial operator-(const int&, const Polynomial&);
	friend const Polynomial operator-(const Polynomial&, const int&);
	friend const Polynomial operator*(const Polynomial&, const Polynomial&);
	friend const Polynomial operator*(const int&, const Polynomial&);
	friend const Polynomial operator*(const Polynomial&, const int&);
	friend const Polynomial operator>>(const Polynomial&, const int&);
	friend const Polynomial operator<<(const Polynomial&, const int&);
	Polynomial& operator=(const Polynomial&);
	int& operator[](const int&);
	double operator()(const int&);
};

