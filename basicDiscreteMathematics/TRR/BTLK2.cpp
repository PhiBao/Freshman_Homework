/*#include<iostream>
#include<iomanip>
using namespace std;
void Try(int n, int k, int *p, int i, bool *check)
{
	int j;
	for (j = 0; j < n; j++)
	{
		if (*(check +j) == true)
		{
			*(p + i) = j + 1;
			*(check + j) = false;
			if (i == (k - 1))
			{
				int temp;
				for (temp = 0; temp < k; temp++)
				{
					cout << setw(3) << *(p + temp);
				}
				cout << endl;
			}

			else
			{
				Try(n, k, p, i + 1, check);
			}

			*(check + j) = true;
		}
	}

}
int main()
{
	int n, k;
	cout << "Liet ke chinh hop khong lap chap k cua n phan tu" << endl;
	cout << "Nhap vao n: "; cin >> n;
	cout << "Nhap vao k: "; cin >> k;
	bool *check = new bool[n + 1];
	int i;
	for (i = 0; i < n; i++)
	{
		*(check + i) = true;
	}
	int *p = new int[k + 1];
	Try(n, k, p, 0, check);
	system("pause");
	return 0;
}*/