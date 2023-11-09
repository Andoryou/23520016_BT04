#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
int ktDong(int[][500], int, int, int);
void LietKe(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n, d;
	Nhap(a, m, n, d);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);
	cout << endl;
	LietKe(a, m, n);
	return 0;
}
void Nhap(int a[][500], int& m, int& n, int& d)
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
void Xuat(int a[][500], int m, int n)
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
int ktDong(int a[][500], int m, int n, int d)
{
	int flag = 1;
	for (int j = 0; j < n; j++)
		if (a[d][j] > 0)
			flag = 0;
	return flag;
}
void LietKe(int a[][500], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ktDong(a, m, n, i) == 1)
				cout << a[i][j] << setw(4);
		}
		
	}
}
