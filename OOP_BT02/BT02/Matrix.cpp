#include "Matrix.h"
#include<iomanip>
Matrix::Matrix(int row, int col, int n)
{
	this->row = row;
	this->col = col;
	this->data = new int*[this->row];
	for (int i = 0; i < this->row; i++)
		*(this->data + i) = new int[this->col];
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			(*this)(i, j) = n;
}
Matrix::~Matrix()
{
	for (int i = 0; i < this->row; i++)
	{
		*(this->data + i) = NULL;
		delete[] *(this->data + i);
	}
	this->data = NULL;
	delete[] this->data;
}
ostream& operator<<(ostream &o, const Matrix &p)
{
	cout << "Matrix:" << endl;
	for (int i = 0; i < p.row; i++)
	{
		for (int j = 0; j < p.col; j++)
			o << setw(7) << *(*(p.data + i) + j);
		cout << endl;
	}
	return o;
}
istream& operator>>(istream &i, Matrix &p)
{
	cout << "Nhap gia tri he so cua Matrix" << endl;
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.col; j++)
		{
			cout << "( " << i << " , " << j << " )= ";
			cin >> p(i, j);
		}
	return i;
}
const Matrix operator+(const Matrix &p, const Matrix &q)
{
	if ((p.row == q.row) && (p.col == q.col))
	{
		static Matrix g(p.row, p.col);
		for (int i = 0; i < p.row; i++)
			for (int j = 0; j < p.col; j++)
				g(i, j) = *(*(p.data + i) + j) + *(*(q.data + i) + j);
		return g;
	}
}
const Matrix operator-(const Matrix &p, const Matrix &q)
{
	if ((p.row == q.row) && (p.col == q.col))
	{
		static Matrix g(p.row, p.col);
		for (int i = 0; i < p.row; i++)
			for (int j = 0; j < p.col; j++)
				g(i, j) = *(*(p.data + i) + j) - *(*(q.data + i) + j);
		return g;
	}
}
const Matrix operator*(const Matrix &p, const Matrix &q)
{
	if ((p.row == q.col) && (p.col == q.row))
	{
		static Matrix g(p.row, q.col, 0);
		for (int i = 0; i < p.row; i++)
			for (int j = 0; j < q.col; j++)
				for (int h = 0; h < q.row; h++)
					g(i, j) += (*(*(p.data + i) + h)) * (*(*(q.data + h) + j));
		return g;
	}
}
const Matrix operator*(const Matrix &p, const int &temp)
{
	static Matrix g(p.row,p.col);
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.col; j++)
			g(i, j) = temp * *(*(p.data + i) + j);
	return g;
}
const Matrix operator*(const int &temp, const Matrix &p)
{
	static Matrix g(p.row, p.col);
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.col; j++)
			g(i, j) = temp * *(*(p.data + i) + j);
	return g;
}
const Matrix operator>>(const Matrix &p, const int &temp)
{
	static Matrix g(p.row, p.col);
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.col; j++)
			g(i, j) = *(*(p.data + i) + j) >> temp;
	return g;
}
const Matrix operator<<(const Matrix &p, const int &temp)
{
	static Matrix g(p.row, p.col);
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.col; j++)
			g(i, j) = *(*(p.data + i) + j) << temp;
	return g;
}
Matrix& Matrix::operator=(const Matrix &p)
{
	this->row = p.row;
	this->col = p.col;
	this->data = new int*[p.row];
	for (int i = 0; i < p.row; i++)
		*(this->data + i) = new int[p.col];
	for (int i = 0; i < p.row; i++)
		for (int j = 0; j < p.col; j++)
			(*this)(i, j) = *(*(p.data + i) + j);
	return *this;
}
int& Matrix::operator()(const int &i, const int &j)
{
	static int temp = 0;
	return (i >= 0 && i < this->row && j >= 0 && j < this->col) ? *(*(this->data + i) + j) : temp;
}
const int Matrix::operator^(const int &level)
{
	if ((this->row != level) && (this->col != this->row)) return 0;
	bool check = true;
	int det = 1;
	float temp;
	for (int i = 0; i < this->row - 1; i++)
	{
		if ((*this)(i, i) == 0)
		{
			check = false;
			for (int j = 0; j < this->row; j++)
				if ((*this)(i, j) != 0)
				{
					for (int k = 0; k < this->row; k++)
					{
						(*this)(k, i) += (*this)(k, j);
					}
					check = true;
				}
		}
		if (check == false) return 0;
		for (int j = i + 1; j < this->row; j++)
		{
			if ((*this)(j, i) != 0)
			{
				temp = -(*this)(j, i) / (*this)(i, i);
				for (int k = i + 1; k < this->row; k++)
					(*this)(j, k) += temp * (*this)(i, k);
			}
		}
	}
	for (int i = 0; i < level; i++) det *= (*this)(i, i);
	return det;
}
/*int main()
{
	Matrix p1(3,2);
	cin >> p1;
	Matrix p2 = p1 << 3;
	p1(1, 1) = 7;
	Matrix p3 = 3 * p2;
	Matrix p4 = p3 * p1;
	Matrix p5(3, 3);
	cin >> p5;
	int a = p5 ^ 3;
	cout << p4;
	cout << "det =" << a << endl;
	system("pause");
	return 0;
}*/