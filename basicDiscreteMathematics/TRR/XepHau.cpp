/*#include<iostream>
#include<iomanip>
using namespace std;
int *p, *q, *r, *s;
void Init(int n)
{
	for (int i = 1; i <= n; i++) *(p + i) = 1;
	for (int i = 2; i <= 2 * n; i++) *(q + i) = 1;
	for (int i = 1 - n; i <= n - 1; i++) *(r + i) = 1;
}
void Out(int n)
{
	for (int i = 1; i <= n; i++) cout << setw(4) << *(s + i);
	cout << endl;
}
void Try(int i, int n)
{
	for (int j = 1; j <= n; j++)
	{
		if (*(p + j) && *(q + i + j) && *(r + i - j))
		{
			*(s + i) = j;
			*(p + j) = 0;
			*(q + i + j) = 0;
			*(r + i - j) = 0;
			if (i == n) Out(i);
			else Try(i + 1, n);
			*(p + j) = 1;
			*(q + i + j) = 1;
			*(r + i - j) = 1;
		}
	}
}
int main()
{
	p = new int[50];
	q = new int[50];
	r = new int[50];
	s = new int[50];
	int n;
	cout << "n:= "; cin >> n;
	Init(n);
	Try(1, n);
	system("pause");
	return 0;
}*/
