#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int &, int &, int &);
int TichCot(int[][500], int, int, int);

int main()
{
	int m, n, c;
	int a[500][500];
	Nhap(a, m, n, c);
	cout << TichCot(a, m, n, c);
	return 0;
}

void Nhap(int a[][500], int &m, int &n, int &c)
{
	cout << "Nhap so hang m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	cout << "Nhap cot c: ";
	cin >> c;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

int TichCot(int a[][500], int m, int n, int c)
{
	int t = 1;
	cout << "Tich cac so chan tren cot " << c << " la: ";
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] % 2 == 0)
		{
			t = t * a[i][c];
		}
	}
	return t;
}