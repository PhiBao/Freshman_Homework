/*#include<iostream>
#include<iomanip>
using namespace std;
int n, stop;
void Init(int *p, int k)
{
	for (int i = 1; i <= k; i++) *(p + i) = i;
}
void Out(int *p, int k)
{
	for (int i = 1; i <= k; i++) cout << setw(4) << *(p + i);
	cout << endl;
}
int LastConfigure(int *p, int k)
{
	for (int i = k; i >= 1; i--) if (*(p + i) != n - k + i) return 0;
	return 1;
}
void Next_Combination(int *p, int k)
{
	int i = k;
	while (i >= 1 && *(p + i) == n - k + i) i--;
	(*(p + i))++;
	for (int j = i + 1; j <= k; j++) *(p + j) = *(p + i) + j - i;
}
void Genarate(int *p, int k)
{
	Init(p, k);
	Out(p, k);
	stop = LastConfigure(p, k);
	while (stop == 0)
	{
		Next_Combination(p, k);
		Out(p, k);
		stop = LastConfigure(p, k);
	}
}
int main()
{
	int k;
	cout << "Liet ke to hop khong lap chap k cua n phan tu" << endl;
	cout << "n: ="; cin >> n;
	cout << "k: ="; cin >> k;
	int *p = new int[k + 1];
	Genarate(p, k);
	system("pause");
	return 0;
}*/