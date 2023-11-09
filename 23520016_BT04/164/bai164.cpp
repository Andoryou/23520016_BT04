#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}
void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << "\n";
	}
}
void DaoDong(float a[][500], int m, int n, int d)
{
	int dd = 0;
	int cc = n - 1;
	while (dd < cc)
	{
		float temp = a[d][dd];
		a[d][dd] = a[d][cc];
		a[d][cc] = temp;
		dd++;
		cc--;
	}
}
void ChieuGuong(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		DaoDong(a, m, n, i);
}
int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	ChieuGuong(a, m, n);
	cout << "Ma tran sau khi chieu guong theo truc doc: ";
	Xuat(a, m, n);
	return 0;
}