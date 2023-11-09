#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
void ChanTang(int[][10], int, int);
void LeGiam(int[][10], int, int);
void ChanTangLeGiam(int[][10], int, int);
void HoanVi(int&, int&);

int main()
{
	int a[10][10], n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	ChanTangLeGiam(a, n, m);
	cout << "Sau khi doi: " << endl;
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

void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ChanTang(int a[][10], int m, int n)
{
	int b[10];
	int k;
	int i, j;
	k = 0;
	for (i = 0;i < m;i++)
		for (j = 0;j < n;j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];

	for (i = 0;i <= k - 2;i++)
		for (j = i + 1;j <= k - 1;j++)
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);
	
	k = 0;
	for (i = 0;i < m;i++)
		for (j = 0;j < n;j++)
			if (a[i][j] % 2 == 0)
				a[i][j] = b[k++];
}

void LeGiam(int a[][10], int m, int n)
{
	int b[10];
	int k;
	int i, j;
	k = 0;
	for (i = 0;i < m;i++)
		for (j = 0;j < n;j++)
			if (a[i][j] % 2 != 0)
				b[k++] = a[i][j];

	for (i = 0;i <= k - 2;i++)
		for (j = i + 1;j <= k - 1;j++)
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);

	k = 0;
	for (i = 0;i < m;i++)
		for (j = 0;j < n;j++)
			if (a[i][j] % 2 != 0)
				a[i][j] = b[k++];
}

void ChanTangLeGiam(int a[][10], int m,int n)
{
	ChanTang(a, m, n);
	LeGiam(a, m, n);
}