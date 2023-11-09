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
void SapXepDongTangDan(float a[][500], int n, int dong) 
{
	sort(a[dong], a[dong] + n);
}
int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);

	int dongCanSapXep;
	cout << "Nhap dong can sap xep (tu 0 den " << m - 1 << "): ";
	cin >> dongCanSapXep;

	if (dongCanSapXep >= 0 && dongCanSapXep < m)
	{
		SapXepDongTangDan(a, n, dongCanSapXep);
		cout << "Ma tran sau khi sap xep dong " << dongCanSapXep << " tang dan:\n";
		Xuat(a, m, n);
	}
	return 0;
}