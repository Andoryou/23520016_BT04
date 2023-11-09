#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
float AmDau(float[][500], int, int);
float AmLonNhat(float[][500], int, int);

int main()
{
	int m, n;
	float a[500][500];
	Nhap(a, m, n);
	AmDau(a, m, n);
	cout << AmLonNhat(a, m, n);
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

float AmDau(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < 0)
			{
				return a[i][j];
			}
		}
	}
	return 0;
}

float AmLonNhat(float a[][500], int m, int n)
{
	int flag = AmDau(a, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > flag && a[i][j] < 0)
			{
				flag = a[i][j];
			}
		}
	}
	return flag;
}