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
bool SoLe(int l)
{
	while (l > 0)
	{
		int k = l % 10;
		if (k % 2 == 0)
		{
			return false;
		}
		l /= 10;
	}
	return true;
}
int DemSoLe(float a[][500], int& m, int& n)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		bool Le = true;
		for (int j = 0; j < n; j++)
		{
			if (!SoLe(a[i][j]))
				Le = false;
		}
		if (Le)
			count++;
	}
	return count;
}
int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	int KetQua = DemSoLe(a, m, n);
	cout << "So luong so le tren dong:" << KetQua;
	return 0;
}