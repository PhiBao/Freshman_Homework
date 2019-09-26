/*#include<iostream>
#include<iomanip>
using namespace std;
int n, start, finish;
int L[50];
int P[50];
int E[50][50];
int V[50];
void Init()
{
	cout << "Nhap so dinh: "; cin >> n;
	cout << "Ma tran khoang cach: " << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> *(*(E + i) + j);
		cout << endl;
	}
}
void Out()
{
	cout << "Duong di ngan nhat tu " << start << " den " << finish << " la:" << endl;
	cout << finish << " <=";
	int i = L[finish];
	while (i != start)
	{
		cout << i << " <= ";
		i = L[i];
	}
	cout << start;
	cout << endl << "Do dai duong di la: " << P[finish] << endl;
}
void Dijkstra()
{
	int u, v, min;
	cout << "Dinh khoi dau la: "; cin >> start;
	cout << "Dinh ket thuc la:"; cin >> finish;
	for (u = 1; u <= n; u++)
	{
		P[u] = E[start][u];
		L[u] = start;
		V[u] = 0;
	}
	L[start] = 0;
	P[start] = 0;
	V[start] = 1;
	while (!V[finish])
	{
		min = 999;
		for (u = 1; u <= n; u++)
		{
			if ((!V[u]) && (min > P[u]))
			{
				v = u;
				min = P[u];
			}
		}
		V[v] = 1;
		if (!V[finish])
			for (u = 1; u <= n; u++)
			{
				if ((!V[u]) && (P[v] + E[v][u] < P[u]))
				{
					P[u] = P[v] + E[v][u];
					L[u] = v;
				}
			}
	}
}
void Bellman_Ford()
{
	cout << "Dinh khoi dau la: "; cin >> start;
	cout << "Dinh ket thuc la:"; cin >> finish;
	for (int i = 1; i <= n; i++)
	{
		P[i] = E[start][i];
		L[i] = start;
	}
	P[start] = 0;
	for (int i = 1; i <= n - 2; i++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				if (P[u] > P[v] + E[v][u])
				{
					P[u] = P[v] + E[v][u];
					L[u] = v;
				}
}
void Floyd_Warshall()
{
	int D[50][50], P[50][50];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (E[i][j])
			{
				D[i][j] = E[i][j];
				P[i][j] = j;
			}
			else
			{
				D[i][j] = 999;
				P[i][j] = NULL;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				if (D[u][v] > D[u][i] + D[i][v])
				{
					D[u][v] = D[u][i] + D[i][v];
					P[u][v] = P[u][i];
				}
	cout << "Ma tran D do dai duong di ngan nhat:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << setw(4) << D[i][j];
		cout << endl;
	}
	cout << "Ma tran P duong di ngan nhat:" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << setw(4) << P[i][j];
		cout << endl;
	}
}
int main()
{
	Init();
	//Dijkstra();
	//Out();
	//Bellman_Ford();
	//Out();
	Floyd_Warshall();
	system("pause");
	return 0;
}*/