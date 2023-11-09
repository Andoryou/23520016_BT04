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
bool ktChinhPhuong(int k)
{
	for (int h = 1; (h * h) <= k; h++)
		if (h * h == k)
			return true;
	return false;
}
int TongChinhPhuong(int a[][500], int& m, int& n)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j+=2)
		if(ktChinhPhuong(a[i][j]))
			s += a[i][j];
	return s;
}
int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	int KetQua=TongChinhPhuong(a, m, n);
	cout << KetQua;
	return 0;
} 