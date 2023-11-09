#include<iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float Tich(float[][500], int, int);
float TBTich(float, int);
int Dem(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran da nhap la: " << endl;
	Xuat(a, m, n);

	cout << "Ket qua la: " << TBTich(Tich(a, m, n), Dem(a, m, n));

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
float Tich(float a[][500], int m, int n)
{
	float t = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				t = t * a[i][j];
	return t;	
}
int Dem(float a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				dem++;
	return dem;
}
float TBTich(float t, int dem)
{
	cout << setprecision(5);
	return t / dem;
}