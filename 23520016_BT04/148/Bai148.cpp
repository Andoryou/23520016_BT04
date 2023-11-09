#include <iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&, int&);
void Xuat(float[][100], int, int);
void ThemCot(float[][100], int, int, int);

int main()
{
	float a[100][100];
	int m, n, c;
	Nhap(a, m, n, c);
	cout << "Ma tran luc dau la: " << endl;
	Xuat(a, m, n);
	cout << "Ma tran luc sau la: " << endl;
	ThemCot(a, m, n, c);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n+1; j++)
		{
			cout << setw(2) << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
void Nhap(float a[][100], int& m, int& n, int& c)
{
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
	cout << "Nhap chi so muon them cot: ";
	cin >> c;
}
void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(2) << a[i][j];
		}
		cout << endl;
	}
}
void ThemCot(float a[][100], int m, int n, int c)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = n; j >= c + 1; j--)
			a[i][j] = a[i][j - 1];
		a[i][c] = 0;
	}
	n++;
}
