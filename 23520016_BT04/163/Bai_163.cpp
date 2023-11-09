#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
void Xoay90(float[][10], int&, int&);
void Xoay270(float[][10], int&, int&);

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	Xoay270(a, n, m);
	cout << "Sau khi xoay 270 do: " << endl;
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

void Xoay90(float a[][10], int& n, int& m)
{
	float b[500][500];
	int k, l;
	
	k = n;
	l = m;
	for (int i = 0;i < k;i++)
		for (int j = 0;j < l;j++)
			b[i][j] = a[j][n - 1 - i];

	m = k;
	n = l;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = b[i][j];
}

void Xoay270(float a[][10], int& n, int& m)
{
	Xoay90(a, n, m);
	Xoay90(a, n, m);
	Xoay90(a, n, m);
}
