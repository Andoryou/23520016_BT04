#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
bool ktNguyenTo(int);
int TongCot(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n, c;
	Nhap(a, m, n, c);
	cout << "Ma tran da nhap la: " << endl;
	Xuat(a, m, n);

	cout << "Ket qua la: " << TongCot(a, m, c);

	return 0;
}

void Nhap(int a[][500], int& m, int& n, int& c)
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
	cout << "Nhap cot can tinh tong c: ";
	cin >> c;
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
bool ktLe(int k)
{
	int flag = true;
	if (k % 2 == 0)
		flag = false;
	return flag;
}

int TongCot(int a[][500], int m, int c)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		if (ktLe(a[i][c]))
			s = s + a[i][c];
	return s;
}