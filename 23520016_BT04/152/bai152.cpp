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
void LonNhatCot(float a[][500], int& m, int& n)
{
	float maxValues[500];
	for (int j = 0; j < n; j++)
	{
		float maxVal = a[0][j];
		for (int i = 1; i < m; i++)
		{
			if (a[i][j] > maxVal)
			{
				maxVal = a[i][j];
			}
		}
		maxValues[j] = maxVal;
	}
	for (int j = 0; j < n; j++)
	{
		a[m][j] = maxValues[j];
	}
	m++;
}

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);

	LonNhatCot(a, m, n);

	cout << "Ma tran sau khi them dong phan tu lon nhat:\n";
	Xuat(a, m, n);

	return 0;
}