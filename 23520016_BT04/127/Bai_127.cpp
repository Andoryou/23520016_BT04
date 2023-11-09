#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
void SapCotTang(float[][10], int, int, int);
void SapCotGiam(float[][10], int, int, int);
void SapXep(float[][10], int, int);
void HoanVi(float& , float& );

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	SapXep(a, n, m);
	cout << "Sau khi sap xep: " << endl;
	Xuat(a, n, m);
	return 0;
}

void Nhap(float a[][10], int& n, int& m)
{
	cout << "Nhap dong: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}

void Xuat(float a[][10], int n, int m)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(8) << setprecision(4) << a[i][j];
		cout << endl;
	}
}

void HoanVi(float& a, float& b)
{
	float temp = a;
	a = b;
	b = temp;
}

void SapCotTang(float a[][10], int m, int n,int c)
{
	for (int i = 0;i <= m - 2;i++)
		for (int j = i + 1;j <= m - 1;j++)
			if (a[i][c] > a[j][c])
				HoanVi(a[i][c], a[j][c]);
}

void SapCotGiam(float a[][10], int m, int n,int c)
{
	for (int i = 0;i <= m - 2;i++)
		for (int j = i + 1;j <= m - 1;j++)
			if (a[i][c] < a[j][c])
				HoanVi(a[i][c], a[j][c]);
}
void SapXep(float a[][10], int m, int n)
{
	for (int j = 0;j <= n - 1;j++)
		if (j % 2 == 0)
			SapCotGiam(a, m, n, j);
		else
			SapCotTang(a, m, n, j);
}
