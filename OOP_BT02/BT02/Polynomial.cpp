#include "Polynomial.h"
#include<iomanip>
Polynomial::Polynomial(int level, int n)
{
	this->level = level;
	this->data = new int[this->level + 1];
	for (int i = 0; i <= this->level; i++)
		(*this)[i] = n;
}
Polynomial::~Polynomial()
{
	this->data = NULL;
	delete[] this->data;
}
ostream& operator<<(ostream &o, const Polynomial &p)
{
	cout << "Polynomial: ";
	for (int i = p.level; i >= 0; i--)
		if (*(p.data + i) > 0)
			o << setw(5) << " +" << *(p.data + i) << "x^" << i;
		else
			o << setw(5) << *(p.data + i) << "x^" << i;
	o << endl;
	return o;
}
istream& operator>>(istream &i, Polynomial &p)
{
	cout << "Nhap he so vecto bac " << p.level << endl;
	for (int i = 0; i <= p.level; i++)
	{ 
		cout << "a[" << i << "] =";
		cin >> p[i];
	}
	return i;
}
const Polynomial operator+(const Polynomial &p, const Polynomial &q)
{
	static Polynomial g;
	if (q.level >= p.level) g = q; else g = p;
	for (int i = 0; i <= ((q.level >= p.level) ? p.level : q.level); i++)
		g[i] = *(q.data + i) + *(p.data + i);
	return g;
}
const Polynomial operator+(const int &temp, const Polynomial &p)
{
	static Polynomial g = p;
	g[0] += temp;
	return g;
}
const Polynomial operator+(const Polynomial &p, const int &temp)
{
	static Polynomial g = p;
	g[0] += temp;
	return g;
}
const Polynomial operator-(const Polynomial &p, const Polynomial &q)
{
	static Polynomial g;
	if (p.level >= q.level)
	{
		g = p;
		for (int i = 0; i <= q.level; i++)
			g[i] = *(p.data + i) - *(q.data + i);
	}
	else 
	{
		g = q;
		for (int i = 0; i <= p.level; i++)
			g[i] = *(p.data + i) - *(q.data + i);
		for (int i = p.level + 1; i <= q.level; i++)
			g[i] = -*(q.data + i);
	}
	return g;
}
const Polynomial operator-(const Polynomial &p, const int &temp)
{
	static Polynomial g = p;
	g[0] -= temp;
	return g;
}
const Polynomial operator-(const int &temp, const Polynomial &p)
{
	static Polynomial g = p;
	for (int i = 0; i <= g.level; i++)
		g[i] = -g[i];
	g[0] += temp;
	return g;
}
const Polynomial operator*(const Polynomial &p, const Polynomial &q)
{
	static Polynomial g(p.level + q.level,0);
	for (int i = 0; i <= p.level; i++)
		for (int j = 0; j <= q.level; j++)
			g[i + j] += *(p.data + i) * *(q.data + j);
	return g;
}
const Polynomial operator*(const Polynomial &p, const int &temp)
{
	static Polynomial g = p;
	for (int i = 0; i <= g.level; i++)
		g[i] *= temp;
	return g;
}
const Polynomial operator*(const int &temp, const Polynomial &p)
{
	static Polynomial g = p;
	for (int i = 0; i <= g.level; i++)
		g[i] *= temp;
	return g;
}
const Polynomial operator>>(const Polynomial &p, const int &temp)
{
	static Polynomial g(p.level);
	for (int i = 0; i <= p.level; i++)
		g[i] = *(p.data + i) >> temp;
	return g;
}
const Polynomial operator<<(const Polynomial &p, const int &temp)
{
	static Polynomial g(p.level);
	for (int i = 0; i <= p.level; i++)
		g[i] = *(p.data + i) << temp;
	return g;
}
Polynomial& Polynomial::operator=(const Polynomial &p)
{
	this->level = p.level;
	this->data = new int[this->level + 1];
	for (int i = 0; i <= p.level; i++)
		(*this)[i] = *(p.data + i);
	return *this;
}
int& Polynomial::operator[](const int &i)
{
	static int temp = 0;
	return (i >= 0 && i <= this->level) ? *(this->data + i) : temp;
}
double Polynomial::operator()(const int& temp)
{
	double s = 1, p = 0;
	for (int i = this->level; i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
			s *= temp;
		s *= (*this)[i];
		p += s;
		s = 1;
	}
	p += *(this->data);
	return p;
}
/*int main()
{
	Polynomial p1;
	Polynomial p2 = p1 << 3;
	Polynomial p3 = p2 + p1;
	Polynomial p4 = 3 * p1 * p3;
	cout << p3 << p4 << endl;
	cout << p4(5) << endl;
	system("Pause");
	return 0;
}*/