#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Nhap(float[][500], int &, int &);
void XayDung(float[][500], int, int, float[][500], int &, int &);

int main()
{
	float a[500][500];
	float b[500][500];
	int m, n, k, l;
	Nhap(a, m, n);
	XayDung(a, m, n, b, k, l);
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

void XayDung(float a[][500], int m, int n, float b[][500], int &k, int &l)
{
	k = m;
	l = n;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < l; j++)
		{
			b[i][j] = abs(a[i][j]);
			cout << setw(8) << b[i][j];
		}
		cout << endl;
	}
}