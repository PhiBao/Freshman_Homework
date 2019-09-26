#include"Vecto.h"
#include<iomanip>
#include<math.h>
Vecto::Vecto(int size, int n)
{
	this->size = size;
	this->data = new int[this->size];
	for (int i = 0; i < this->size; i++)
		(*this)[i] = n;
}
Vecto::~Vecto()
{
	this->data = NULL;
	delete[] this->data;
}
ostream& operator<<(ostream &o, const Vecto &p)
{
	cout << "Value vecto: ";
	for (int i = 0; i < p.size; i++)
		o << setw(5) << *(p.data + i);
	return o;
}
istream& operator>>(istream &i, Vecto &p)
{
	cout << "Nhap toa do vecto co " << p.size << " chieu" << endl;
	for (int i = 0; i < p.size; i++)
		cin >> p[i];
	return i;
}
const Vecto operator+(const Vecto &p, const Vecto &q)
{
	if (p.size == q.size)
	{
		static Vecto g(p.size);
		for (int i = 0; i < p.size; i++)
			g[i] = *(p.data + i) + *(q.data + i);
		return g;
	}
}
const Vecto operator-(const Vecto &p, const Vecto &q)
{
	if (p.size == q.size)
	{
		static Vecto g(p.size);
		for (int i = 0; i < p.size; i++)
			g[i] = *(p.data + i) - *(q.data + i);
		return g;
	}
}
const Vecto operator*(const Vecto &p, const Vecto &q)
{
	if (p.size == q.size)
	{
		static Vecto g(p.size);
		for (int i = 0; i < p.size; i++)
			g[i] = *(p.data + i) * *(q.data + i);
		return g;
	}
}
const Vecto operator*(const int &temp, const Vecto &p)
{
	static Vecto g(p.size);
	for (int i = 0; i < p.size; i++)
		g[i] = *(p.data + i) * temp;
	return g;
}
const Vecto operator*(const Vecto &p, const int &temp)
{
	static Vecto g(p.size);
	for (int i = 0; i < p.size; i++)
		g[i] = *(p.data + i) * temp;
	return g;
}
const Vecto operator>>(const Vecto &p, const int &temp)
{
	static Vecto g(p.size);
	for (int i = 0; i < p.size; i++)
		g[i] = *(p.data + i) >> temp;
	return g;
}
const Vecto operator<<(const Vecto &p, const int &temp)
{
	static Vecto g(p.size);
	for (int i = 0; i < p.size; i++)
		g[i] = *(p.data + i) << temp;
	return g;
}
Vecto& Vecto::operator=(const Vecto &p)
{
	this->size = p.size;
	this->data = new int[this->size];
	for (int i = 0; i < p.size; i++)
		(*this)[i] = *(p.data + i);
	return *this;
}
int& Vecto::operator[](const int &i)
{
	static int temp = 0;
	return (i >= 0 && i < this->size) ? *(this->data + i) : temp;
}
const float Vecto::operator^(const int &size)
{
	if (this->size = size)
	{
		float s = 0;
		for (int i = 0; i < this->size; i++)
			s += (*(this->data + i) * *(this->data + i));
		return sqrt(s);
	}
}
int main()
{
	Vecto p1(3);
	cin >> p1;
	Vecto p2 = p1 << 3;
	Vecto p3 = p1 * 3 - p2;
	p3[2] = 5;
	float a = p3 ^ 3;
	cout << p3 << endl;
	cout << "legth = " << a << endl;
	system("pause");
	return 0;
}