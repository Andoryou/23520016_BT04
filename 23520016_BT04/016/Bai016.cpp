#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&, int&);
void Lietke(int[][500], int, int);
void Xuat(int[][500], int, int);
bool ktDang(int);

int main()
{
	int a[500][500];
	int m, n, d;
	Nhap(a, m, n, d);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);
	Lietke(a, d, n);
	return 0;
}

void Nhap(int a[][500], int& m, int& n, int& d)
{
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	cout << "Nhap hang d muon xet: ";
	cin >> d;
}
void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}
void Lietke(int a[][500], int d, int n)
{
	for (int j = 0; j < n; j++)
	{
		if (ktDang(a[d][j]))
			cout << setw(4) << a[d][j];
	}
		
}
bool ktDang(int k)
{
	if (k < 1)
		return false;
	int flag = false;
	for (int i = 1; i < k; i++)
		if (pow(3, i) == k)
			flag = true;
	return flag;
}