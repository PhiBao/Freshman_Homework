#include"QLNV.h"
void Menu()
{
	cout << "_________________MENU_______________" << endl;
	cout << "1.Add:" << endl;
	cout << "2.Update:" << endl;
	cout << "3.Delete:" << endl;
	cout << "4.Sort:" << endl;
	cout << "5.Search:" << endl;
	cout << "6.Show list:" << endl;
	cout << "7.Exit." << endl;
	cout << "_____________________________________" << endl;
}
int main()
{
	NhanVien p;
	NVBC q;
	NVHD r;
	QLNV Array("John");
	Array.AddTail(p);
	Array.AddTail(q);
	Array.AddTail(r);
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
			cout << "The location of element add:" << endl;
			cout << " (0)-->Fisrt." << " (-1)-->Last." << " (Other Number)--> location k." << endl;
			cin >> i;
			if (i == 0) Array.AddFirst();
			else if (i == -1) Array.AddLast();
			else Array.Add(i);
			break;
		}
		case 2:
		{
			cout << "The location of element update:" << endl;
			cout << "________" << 0 << "-->" << Array.StaffAmount - 1 << "________" << endl;
			cin >> i;
			if (i<0 || i>Array.StaffAmount - 1) cout << "---illegal---" << endl;
			else Array.Update(i);
			break;
		}
		case 3:
		{
			cout << "The location of element delete:" << endl;
			cout << " (0)-->Fisrt." << " (-1)-->Last." << " (Other Number)--> location k." << endl;
			cin >> i;
			if (i == 0) Array.DeleteFirst();
			else if (i == -1) Array.DeleteLast();
			else Array.Delete(i);
			break;
		}
		case 4:
		{
			
			Array.Sort();
			break;
		}
		case 5:
		{
			cout << "Search by salary:" << endl;
			cout << "Salary = "; cin >> i;
			cout << "\n" << "Result search:" << endl;
			if (Array.Search(i) == nullptr) cout << (Array.Search(i)) << endl;
			else Array.Search(i)->print();
			break;
		}
		case 6:
		{
			Array.Print();
			break;
		}
		case 7:
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