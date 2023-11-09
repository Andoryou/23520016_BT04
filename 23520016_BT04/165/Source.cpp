#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
void DaoCot(float[][500], int, int, int);
void ChieuGuong(float[][500], int, int);
void Xuat(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	ChieuGuong(a, m, n);
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

void DaoCot(float a[][500], int m, int n, int c)
{
	int dd = 0;
	int cc = m - 1;
	while (dd < cc)
	{
		float temp = a[dd][c];
		a[dd][c] = a[cc][c];
		a[cc][c] = temp;
		dd++;
		cc--;
	}
}

void ChieuGuong(float a[][500], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		DaoCot(a, m, n, j);
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
