#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][100], int&, int&, int&);
void Xuat(float[][100], int, int);
void HoanVi(float&, float&);
void SapCotTang(float[][100], int, int, int);


int main()
{
	float a[100][100];
	int m, n, c;
	Nhap(a, m, n, c);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	SapCotTang(a, m, n, c);
	cout << "Ma tran luc sau la: " << endl;
	Xuat(a, m, n);

	return 0;
}
void Nhap(float a[][100], int& m, int& n, int& c)
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
	cout << "Nhap cot can sap xep: ";
	cin >> c;
}
void Xuat(float a[][100], int m, int n)
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
void HoanVi(float& a, float& b)
{

	float temp = a;
	a = b;
	b = temp;
}
void SapCotTang(float a[][100], int m, int n, int c)
{
	for (int i = 0; i <= m - 2; i++)
		for (int j = i + 1; j <= m - 1; j++)
			if (a[i][c] > a[j][c])
				HoanVi(a[i][c], a[j][c]);
}