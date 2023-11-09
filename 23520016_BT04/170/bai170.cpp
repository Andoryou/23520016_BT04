#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;

void NhapA(float a[][500], int& m, int& n)
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
void XuatA(float a[][500], int m, int n)
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
void NhapB(float b[][500], int& k, int& l)
{
	cout << "Nhap k: ";
	cin >> k;
	cout << "Nhap n: ";
	cin >> l;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
		{
			cout << "b[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}
}
void XuatB(float b[][500], int& k, int& l)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << b[i][j];
		}
		cout << "\n";
	}
}
int DemCon(float a[][500], int m, int n, float b[][500], int k, int l)
{
	if (m > k || n > l)
		return 0;
	int dem = 0;
	for (int d = 0; d <= k - m; d++)
		for (int c = 0; c <= l - n; c++)
		{
			int flag = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					if (b[d + i][c + j] != a[i][j])
						flag = 0;
			if (flag == 1)
				dem++;
		}
	return dem;
}
int main()
{
	float a[500][500];
	float b[500][500];
	int m, n, k, l;
	NhapA(a, m, n);
	XuatA(a, m, n);
	NhapB(b, k, l);
	XuatB(b, k, l);
	int KetQua = DemCon(a, m, n, b, k, l);
	cout << KetQua;
	return 0;
}