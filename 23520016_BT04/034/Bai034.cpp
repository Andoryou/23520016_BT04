#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
bool ktNguyenTo(int);
int TongDong(int[][500], int, int);


int main()
{
	int a[500][500];
	int m, n, d;
	Nhap(a, m, n, d);
	cout << "Ma tran da nhap la: " << endl;
	Xuat(a, m, n);

	cout << "Ket qua la: " << TongDong(a, d, n);

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
	cout << "Nhap dong can tinh tong d: ";
	cin >> d;
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
bool ktNguyenTo(int k)
{
	int dem = 0;
	for (int i = 1; i <= k; i++)
		if (k % i == 0)
			dem++;
	if (dem == 2)
		return true;
	else
		return false;
}
int TongDong(int a[][500], int d, int n)
{
	int s = 0;
	for (int j = 0; j < n; j++)
		if (ktNguyenTo(a[d][j]))
			s = s + a[d][j];
	return s;
}