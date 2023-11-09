#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
void XoaDong(int[][10], int&, int, int);
void XoaDong(int[][10], int&, int);
bool ktToanChan(int[][10],int,int,int);

int main()
{
	int a[10][10], n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	XoaDong(a, m, n);
	cout << "Sau khi xoa dong toan chan: " << endl;
	Xuat(a, n, m);
	return 0;
}

void Nhap(int a[][10], int& n, int& m)
{
	cout << "Nhap dong: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = rand() % 200 - 100;
}

void Xuat(int a[][10], int n, int m)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool ktToanChan(int a[][10],int n,int m,int c)
{
	bool flag = true;
	for (int i = 0;i < n;i++)
		if (a[c][i] % 2 != 0)
			flag = false;
	return flag;
}

void XoaDong(int a[][10], int& m, int n, int d)
{
	for (int j = 0;j < n;j++)
	{
		for (int i = d;i <= m - 2;i++)
			a[i][j] = a[i + 1][j];
	}
	m--;
}

void XoaDong(int a[][10], int& m, int n)
{
	for (int i = m - 1;i >= 0;i--)
		if (ktToanChan(a, m, n, i)==true)
			XoaDong(a, m, n, i);
}