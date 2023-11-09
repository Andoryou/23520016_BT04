#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][100], int&, int&);
void XuatNguyenToTang(int[][100], int, int);
void Xuat(int[][100], int, int);
void HoanVi(int&, int&);
int ktnt(int);

int main()
{
	int a[100][100];
	int m, n;
	Nhap(a, m, n); 
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);
	XuatNguyenToTang(a, m, n);
}
void Nhap(int a[][100], int& m, int& n)
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
void XuatNguyenToTang(int a[][100], int m, int n)
{
	int b[500];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (ktnt(a[i][j]) == 1)
				b[k++] = a[i][j];
	
	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
		if (b[i] > b[j])
			 HoanVi(b[i], b[j]);

		for (i = 0; i < k; i++)
		cout << setw(8) << b[i];
}
void Xuat(int a[][100], int m, int n)
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
void HoanVi(int& a, int& b)
{

	float temp = a;
	a = b;
	b = temp;
}
int ktnt(int k)
{
	int dem = 0;
	if (k == 1)
		return 0;
	for (int i = 1; i <= k; i++)
		if ( k % i == 0)
			dem++;
	if (dem == 2)
		return 1;
}
