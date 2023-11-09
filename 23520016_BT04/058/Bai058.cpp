#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktDang(int);
int Dem(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran da nhap la: " << endl;
	Xuat(a, m, n);

	cout << "ket qua la: " << Dem(a, m, n);

	return 0;
}

void Nhap(int a[][500], int& m, int& n)
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
bool ktDang(int k)
{
	if (k <= 0)
	{
		return false;
	}
	for (int i = 0; i < k; i++)
		if (pow(2, i) == k)
			return true;
	return false;
}
int Dem(int a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktDang(a[i][j]) == true)
				dem = dem + 1;
	return dem;

}