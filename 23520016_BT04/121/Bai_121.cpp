#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
void HoanVi(float&, float&);
void HoanViCot(float[][10], int, int, int,int);
int main()
{
	float a[10][10];
	int n, m, c1, c2;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cin >> c1 >> c2;
	cout << "Sau khi hoan vi la: " << endl;
	HoanViCot(a, m, n, c1, c2);
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

void HoanViCot(float a[][10], int m, int n, int c1, int c2)
{
	for (int i = 0;i < m;i++)
		HoanVi(a[i][c1], a[i][c2]);
}