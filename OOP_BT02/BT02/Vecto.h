#pragma once
#include<iostream>
using namespace std;
class Vecto
{
private:
	int size;
	int *data;
public:
	Vecto(int = 2, int = 2);
	~Vecto();
	friend ostream& operator<<(ostream&, const Vecto&);
	friend istream& operator>>(istream&, Vecto&);
	friend const Vecto operator+(const Vecto&, const Vecto&);
	friend const Vecto operator-(const Vecto&, const Vecto&);
	friend const Vecto operator*(const Vecto&, const Vecto&);
	friend const Vecto operator*(const int&, const Vecto&);
	friend const Vecto operator*(const Vecto&, const int&);
	friend const Vecto operator>>(const Vecto&, const int&);
	friend const Vecto operator<<(const Vecto&, const int&);
	Vecto& operator=(const Vecto&);
	int& operator[](const int&);
	const float operator^(const int&);
};