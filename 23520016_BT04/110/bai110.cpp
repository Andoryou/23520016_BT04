#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

void Nhap(int a[][500], int& m, int& n)
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
void Xuat(int a[][500], int m, int n)
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
bool ktNguyenTo(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (k% i == 0)
			dem++;
	return  (dem == 2);
}
void LietKe(int a[][500], int m, int n) 
{
	cout << "Cac dong chua so nguyen to la:\n";
	for (int i = 0; i < m; i++) 
	{
		bool coSoNguyenTo = false;
		for (int j = 0; j < n; j++) 
		{
			if (ktNguyenTo(a[i][j])) 
			{
				coSoNguyenTo = true;
				break;
			}
		}
		if (coSoNguyenTo) 
		{
			cout << "Dong " << i << ": ";
			for (int j = 0; j < n; j++) 
			{
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	LietKe(a, m, n);
	return 0;
}