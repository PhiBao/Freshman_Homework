#pragma once
#include<iostream>
using namespace std;
class Matrix
{
private:
	int **data;
	int row, col;
public:
	Matrix(int = 2, int = 3, int = 1);
	~Matrix();
	friend ostream& operator<<(ostream &, const Matrix&);
	friend istream& operator>>(istream &, Matrix &);
	friend const Matrix operator+(const Matrix&, const Matrix&);
	friend const Matrix operator-(const Matrix&, const Matrix&);
	friend const Matrix operator*(const Matrix&, const Matrix&);
	friend const Matrix operator*(const Matrix&, const int&);
	friend const Matrix operator*(const int&, const Matrix&);
	friend const Matrix operator>>(const Matrix&, const int&);
	friend const Matrix operator<<(const Matrix&, const int&);
	Matrix& operator=(const Matrix&);
	int& operator()(const int&, const int&);
	const int operator^(const int&);
};