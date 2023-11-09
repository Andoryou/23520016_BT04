#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int ktCucTieu(float[][500], int, int);
int ktCucDai(float[][500], int, int);
float TongCucDai(float[][500], int, int);
float TongCucTieu(float[][500], int, int);
float TongCucTri(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran da nhap la: " << endl;
	Xuat(a, m, n);

	cout << "Ket qua la: " << TongCucTri(a, m, n);

	return 0;
}

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}
void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}
float TongCucTri(float a[][500], int m, int n)
{
	return TongCucDai(a, m, n) + TongCucTieu(a, m, n);
}

int ktCucDai(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > a[i - 1][j - 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i - 1][j + 1] &&
				a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1] &&
				a[i][j] > a[i + 1][j - 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i + 1][j + 1])
				return a[i][j];
		}
}
float TongCucDai(float a[][500], int m, int n)
{
	float s = 0;
	return s + ktCucDai(a, m, n);
}
int ktCucTieu(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < a[i - 1][j - 1] && a[i][j] < a[i - 1][j] && a[i][j] < a[i - 1][j + 1] &&
				a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1] &&
				a[i][j] < a[i + 1][j - 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i + 1][j + 1])
				return a[i][j];
		}
}
float TongCucTieu(float a[][500], int m, int n)
{
	float s = 0;
	return s + ktCucTieu(a, m, n);
}