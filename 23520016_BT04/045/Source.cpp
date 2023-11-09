#include <iostream>
using namespace std;

void Nhap(float[][500], int &, int &);
float TongDuong(float[][500], int, int);
int DemDuong(float[][500], int, int);
float TbcDuong(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "\nTrung binh cong cac gia tri duong: " << TbcDuong(a, m, n);
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

float TongDuong(float a[][500], int m, int n)
{
	float s = 0;
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			if (a[i][j] > 0)
				s += a[i][j];
		}
	}
	return s;
}

int DemDuong(float a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i <= m - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			if (a[i][j] > 0)
				dem++;
		}
	}
	if (dem == 0)
		return 0;
	return dem;
}

float TbcDuong(float a[][500], int m, int n)
{
	return TongDuong(a, m, n) / DemDuong(a, m, n);
}