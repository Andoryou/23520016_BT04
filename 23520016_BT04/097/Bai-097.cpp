#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
float LonNhatDong(float[][10], int, int, int);
float NhoNhatDong(float[][10], int, int, int);
float LonNhatCot(float[][10], int, int, int);
float NhoNhatCot(float[][10], int, int, int);
int ktYenNgua(float[][10], int, int, int, int);
int DemYenNgua(float[][10], int, int);

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "So yen ngua la " << DemYenNgua(a, n, m);
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

float LonNhatDong(float a[][10], int m, int n,int d)
{
	float lc = a[d][0];
	for (int j = 0;j < n;j++)
		if (a[d][j] > lc)
			lc = a[d][j];
	return lc;
}
float NhoNhatDong(float a[][10], int m, int n,int d)
{
	float lc = a[d][0];
	for (int j = 0;j < n;j++)
		if (a[d][j] < lc)
			lc = a[d][j];
	return lc;
}
float LonNhatCot(float a[][10], int m, int n,int c)
{
	float lc = a[0][c];
	for (int i = 0;i < m;i++)
		if (a[i][c] > lc)
			lc = a[i][c];
	return lc;
}
float NhoNhatCot(float a[][10], int m, int n,int c)
{
	float lc = a[0][c];
	for (int i = 0;i < m;i++)
		if (a[i][c] < lc)
			lc = a[i][c];
	return lc;
}
int ktYenNgua(float a[][10], int m, int n,int d, int c)
{
	float lnd = LonNhatDong(a, m, n, d);
	float nnc = NhoNhatCot(a, m, n, c);
	float lnc = LonNhatCot(a, m, n, c);
	float nnd = NhoNhatDong(a, m, n, d);
	if ((a[d][c] == lnd && a[d][c] == nnc) ||(a[d][c] == lnc && a[d][c] == nnd))
		return 1;
	return 0;
}
int DemYenNgua(float a[][10], int m, int n)
{
	int dem = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (ktYenNgua(a, m, n, i, j) == 1)
				dem++;
	return dem;
}