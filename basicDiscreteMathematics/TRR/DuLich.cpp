/*#include<iostream>
using namespace std;
int n;
int Pay = 0, sign = 1;
int C[50][50], Check[50], Road[50], Temp[50];
void Init()
{
	cout << "So thanh pho la "; cin >> n;
	cout << "Nhap ma tran chi phi C:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "C(" << i << "," << j << ")="; cin >> C[i][j];
		}
		cout << endl;
	}
	Temp[1] = 1;
	for (int i = 2; i <= n; i++)  Check[i] = 1;
}
void Out()
{
	int j = 1;
	cout << j << "-->";
	for (int i = 2; i <= n; i++) cout << Road[i] << "--> ";
	cout << j << endl;
	cout << "Tong chi phi la: " << Pay << endl;
}
void Try(int i)
{
	for (int j = 2; j <= n; j++) {
		if (Check[j]) 
		{
			Temp[i] = j;
			Check[j] = 0;
			if (i == n)
			{
				int S = 0;
				for (int i = 1; i <= n - 1; i++) 
				{
					S = S + C[Temp[i]][Temp[i + 1]];
				}
				S = S + C[Temp[n]][1];
				if (S < Pay || sign == 1) 
				{
					sign = 0;
					Pay = S;
					for (int i = 1; i <= n; i++) Road[i] = Temp[i];
				}
			}
			else Try(i + 1);
			Check[j] = 1;
		}
	}
		
}
int main()
{
	Init();
	Try(2);
	Out();
	system("Pause");
	return 0;
}*/
