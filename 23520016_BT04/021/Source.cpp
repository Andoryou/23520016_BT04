#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int &, int &);
void LietKe(int[][500], int, int);

int main()
{
	int m, n;
	int a[500][500];
	Nhap(a, m, n);
	LietKe(a, m, n);
	return 0;
}

void Nhap(int a[][500], int &m, int &n)
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

void LietKe(int a[][500], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << a[0][j] << setw(5);
	}
	for (int i = 1; i < m - 1; i++)
	{
		cout << a[i][n - 1] << setw(5);
	}
	for (int j = n - 1; j >= 0; j--)
	{
		cout << a[m - 1][j] << setw(5);
	}
	for (int i = m - 2; i > 0; i--)
	{
		cout << a[i][0] << setw(5);
	}
}