#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
float LonNhatDong(float[][100], int, int, int);
float LonNhatCot(float[][100], int, int, int);
void XayDung(float[][100], int, int, float[][100], int&, int&);

int main()
{
	float a[100][100];
	float b[100][100];
	int m, n, k, l;
	Nhap(a, m, n);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	XayDung(a, m, n, b, k, l);
	cout << "Ma tran B duoc xay dung la: " << endl;
	Xuat(b, k, l);

	return 0;
}
void Nhap(float a[][100], int& m, int& n)
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
void Xuat(float a[][100], int m, int n)
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
float LonNhatDong(float a[][100], int m, int n, int d)
{
	float lc = a[d][0];
	for (int j = 0; j < n; j++)
		if (a[d][j] > lc)
			lc = a[d][j];
	return lc;
}
float LonNhatCot(float a[][100], int m, int n, int c)
{
	float lc = a[0][c];
	for (int i = 0; i < m; i++)
		if (a[i][c] > lc)
		lc = a[i][c];
	return lc;
}
void XayDung(float a[][100], int m, int n, float b[][100], int& k, int& l)
{
	k = m;
	l = n;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
		{
			float lnd = LonNhatDong(a, m, n, i);
			float lnc = LonNhatCot(a, m, n, j);
			if (lnd < lnc)
				b[i][j] = lnc;
			else
				b[i][j] = lnd;
		}
}
