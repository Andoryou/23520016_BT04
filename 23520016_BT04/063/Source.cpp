#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &, int &);
int DemAm(float[][500], int, int, int);

int main()
{
	int m, n, c;
	float a[500][500];
	Nhap(a, m, n, c);
	cout << DemAm(a, m, n, c);
	return 0;
}

void Nhap(float a[][500], int &m, int &n, int &c)
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

int DemAm(float a[][500], int m, int n, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i][c] < 0)
		{
			dem++;
		}
	}
	return dem;
}