#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
float TongCot(float[][10], int, int, int);
void ThemDong(float[][10], int, int&);

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	ThemDong(a, n, m);
	cout << "Sau khi them dong: " << endl;
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

float TongCot(float a[][10], int n, int m, int c)
{
	float k = 0;
	for (int i = 0;i < m;i++)
		k = k + a[i][c];
	return k;
}

void ThemDong(float a[][10], int n, int& m)
{
	for (int j = 0;j < n;j++)
	{
		a[m][j] = TongCot(a, n, m, j);
	}
	m++;
}