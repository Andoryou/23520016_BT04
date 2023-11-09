#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
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
int DemChuSo(int k)
{
	if (k == 0)
		return 1;
	int dem = 0;
	for (int t = k; t != 0; t = t / 10)
		dem++;
	return dem;
}
int DemSoMaTran(float a[][500], int m, int n)
{
	int Dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Dem += DemChuSo(a[i][j]);
		}
	}
	return Dem;
}
int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	int KetQua = DemSoMaTran(a, m, n);
	cout << "So luong chu so trong ma tran: " << KetQua;
	return 0;
}