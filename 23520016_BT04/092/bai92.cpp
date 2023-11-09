#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

void Nhap(int a[][500], int& m, int& n)
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
void Xuat(int a[][500], int m, int n)
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
int DemDong(int a[][500], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 == 0)
			dem++;
	return dem;
}
int DemLonNhat(int a[][500], int m, int n)
{
	int lc = DemDong(a, m, n, 0);
	for (int i = 0; i < m; i++)
		if (DemDong(a, m, n, i) > lc)
			lc = DemDong(a, m, n, i);
	return lc;
}
void LietKe(int a[][500], int m, int n)
{
	float sln = DemLonNhat(a, m, n);
	for (int i = 0; i < m; i++)
		if (DemDong(a, m, n, i) == sln)
			cout << setw(8) << i;
}
int main() 
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	cout << "\n";
	cout << "Dong co nhieu so chan nhat la:";
	LietKe(a, m, n);
	return 0;
}