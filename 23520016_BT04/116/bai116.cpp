#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}
void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << "\n";
	}
}
bool ktCotTangDan(float a[][500], int m, int n, int cot)
{
	for (int i = 0; i < m - 1; i++) {
		if (a[i][cot] > a[i + 1][cot]) {
			return false;
		}
	}
	return true;
}
void LietKe(float a[][500], int m, int n)
{
	for (int j = 0; j < n; j++) {
		if (ktCotTangDan(a, m, n, j))
		{
			cout << "Cot " << j << ": ";
			for (int i = 0; i < m; i++)
			{
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
int main() 
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	LietKe(a, m, n);
	return 0;
}