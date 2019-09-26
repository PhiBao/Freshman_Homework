/*#include <iostream>
#include <iomanip>
using namespace std;
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int Check(int x, int y, int A[8][8])
{
	if (x >= 0 && y >= 0 && x < 8 && y < 8 && A[x][y] == -1) return 1;
	else return 0;
}
void Out(int A[8][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << setw(3) << A[i][j];
		cout << endl;
	}
}
int Solve(int x, int y, int count, int A[8][8])
{
	int k, next_row, next_col;
	if (count == 8 * 8)
		return true;
	for (k = 0; k < 8; k++)
	{
		next_row = x + row[k];
		next_col = y + col[k];
		if (Check(next_row, next_col, A))
		{
			A[next_row][next_col] = count;
			if (Solve(next_row, next_col, count + 1, A) == true)
				return true;
			else
				A[next_row][next_col] = -1;
		}
	}
	return false;
}
bool Try()
{
	int A[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			A[i][j] = -1;
	A[0][0] = 0;
	if (Solve(0, 0, 1, A) == false)
	{
		cout << "No Solution" << endl;
		return false;
	}
	else
		Out(A);
	return true;
}

int main()
{
	Try();
	system("pause");
	return 0;
}*/