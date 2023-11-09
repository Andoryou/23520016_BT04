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
bool ktDang5m(int k)
{
	if (k < 1)
		return false;
	bool flag = true;
	for (int t = k; t > 1; t = t / 5)
		if (t % 5 != 0)
			flag = false;
	return flag;
}
int Tong5m(int a[][500], int& m, int& n)
{
	int s{};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if ((ktDang5m(a[i][j])) % 5 != 0)
				s += a[i][j];
	return s;
}
int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	int KetQua=Tong5m(a,m,n);
	cout  << KetQua;
	return 0;
}