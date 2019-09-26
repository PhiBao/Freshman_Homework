#include<iostream>
#include<string>
#include"CTKH.h"
#include"List.h"
using namespace std;
bool ascending(const int& left, const int& right);
bool descending(const int& left, const int& right);
void Menu()
{
	cout << "_________________MENU_______________" << endl;
	cout << "1.Input objective list:" << endl;
	cout << "2.Add:" << endl;
	cout << "3.Update:" << endl;
	cout << "4.Delete:" << endl;
	cout << "5.Sort:" << endl;
	cout << "6.Search:" << endl;
	cout << "7.Show list:" << endl;
	cout << "8.Exit." << endl;
	cout << "_____________________________________" << endl;
}
int main()
{
	List Array(3);
	int number;
	int i;
	bool start = true;
	while (start)
	{
		Menu();
		cout << "Pick it:" << endl;
		cin >> number;
		switch (number)
		{
		case 1:
		{
			cout << "Input data:" << endl;
			cin >> Array;
			break;
		}
		case 2:
		{
			cout << "The location of element add:" << endl;
			cout << " (0)-->Fisrt." << " (-1)-->Last." << " (Other Number)--> location k." << endl;
			cin >> i;
			(i == (-1)) ? Array.Add(Array.size) : Array.Add(i);
			break;
		}
		case 3:
		{
			cout << "The location of element update:" << endl;
			cout << "________" << 0 << "-->" << Array.size - 1 << "________" << endl;
			cin >> i;
			Array.Update(i);
			break;
		}
		case 4:
		{
			cout << "The location of element delete:" << endl;
			cout << " (0)-->Fisrt." << " (-1)-->Last." << " (Other Number)--> location k." << endl;
			cin >> i;
			(i == (-1)) ? Array.Delete(Array.size - 1) : Array.Delete(i);
			break;
		}
		case 5:
		{
			bool Cond;
			cout << "Choosen type of sort:" << endl;
			cout << " (0)-->Ascending." << " (1)-->Descending." << endl;
			cin >> Cond;
			(Cond == false) ? Array.ShellSort(ascending) : Array.ShellSort(descending);
			break;
		}
		case 6:
		{
			cout << "Search by year:" << endl;
			cout << "Year = "; do (cin >> i); while (i < 1900);
			cout << "\n" << "Result search:" << endl;
			if (Array.InterpolationSearch(i) == NULL) cout << (Array.InterpolationSearch(i)) << endl;
			else cout << *(Array.InterpolationSearch(i)) << endl;
			break;
		}
		case 7:
		{
			Array.Show();
			break;
		}
		case 8:
		{
			exit(0);
		}
		default:
			start = false;
			break;
		}
	}
	system("pause");
	return 0;
}