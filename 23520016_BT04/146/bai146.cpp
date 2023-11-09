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
void XoaCotToanAm(float a[][500], int& m, int& n, int cot) 
{
	for (int i = 0; i < m; i++)
		for (int j = cot; j < n - 1; j++)
			a[i][j] = a[i][j + 1];
	n--;
}
void XoaCacCotToanAm(float a[][500], int& m, int& n) 
{
	for (int j = 0; j < n; j++) 
	{
		bool toanAm = true; 
		for (int i = 0; i < m; i++) 
		{
			if (a[i][j] >= 0) {
				toanAm = false; 
				break;
			}
		}
		if (toanAm) 
		{
			XoaCotToanAm(a, m, n, j);
			j--; 
		}
	}
}

int main() 
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	XoaCacCotToanAm(a, m, n);
	cout << "Ma tran sau khi xoa cac cot toan am:\n";
	Xuat(a, m, n);
	return 0;
}