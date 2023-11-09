#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][500], int &, int &);
void BienDoi(float[][500], int, int);
void Xuat(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n, d;
	Nhap(a, m, n);
	BienDoi(a, m, n);
	Xuat(a, m, n);
	return 0;
}

void Nhap(float a[][500], int &m, int &n)
{
	cout << "Nhap so hang m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void BienDoi(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = abs(a[i][j]);
		}
	}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8) << a[i][j];
		}
		cout << endl;
	}
}