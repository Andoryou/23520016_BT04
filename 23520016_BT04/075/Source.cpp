#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
float DuongDau(float[][500], int, int);

int main()
{
	int m, n;
	float a[500][500];
	Nhap(a, m, n);
	cout << DuongDau(a, m, n);
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

float DuongDau(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
			{
				return a[i][j];
			}
		}
	}
	return -1;
}