#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float TongDong(float[][500], int, int, int);
float TongLonNhat(float[][500], int, int);


int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	cout << "Ket qua la: " << TongLonNhat(a, m, n);

	return 0;
}
void Nhap(float a[][500], int& m, int& n)
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
void Xuat(float a[][500], int m, int n)
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

float TongDong(float a[][500], int m, int n, int d)
{
	float s = 0;
	for (int j = 0; j < n; j++)
		s = s + a[d][j];
	return s;
}
float TongLonNhat(float a[][500], int m, int n)
{
	float lc = TongDong(a, m, n, 0);
	for (int i = 0; i < m; i++)
		if (TongDong(a, m, n, i) > lc)
			lc = TongDong(a, m, n, i);
	return lc;
}
