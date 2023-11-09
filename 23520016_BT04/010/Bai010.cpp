#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Lietke(int[][500], int, int);
void Xuat(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran luc dau la: " << endl;
	Xuat(a, m, n);
	cout << endl;
	cout << "kq la: ";
	Lietke(a, m, n);
	return 0;

}

void Nhap(int a[][500], int& m, int& n)
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
void Lietke(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i = i + 2)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 != 0)
				cout << setw(2) << a[i][j];
}
