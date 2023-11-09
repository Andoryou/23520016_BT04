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
float TongGiaTriTrongKhoang(int a[][500], int& m, int& n)
{
	int s = 0;
	int x, y;
	cout << "Nhap x:";
	cin >> x;
	cout << "Nhap y:";
	cin >> y;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] >= x && a[i][j] <= y)
				s += a[i][j];
	return s;
}
int main()
{
	int a[500][500];
	int m, n, x, y;
	Nhap(a, m, n);
	Xuat(a, m, n);
	int KetQua = TongGiaTriTrongKhoang(a, m, n);
	cout << "Tong cac gia tri nam trong khoang (x,y):" << KetQua;
	return 0;
}