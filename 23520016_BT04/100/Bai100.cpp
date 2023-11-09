#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int ViTriDuongDau(int[], int);
int ViTriDuongNhoNhat(int[], int);
int TimChuSo(int[][500], int, int);



int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	cout << "Ket qua la: " << TimChuSo(a, m, n);	
	return 0;
}
void Nhap(int a[][500], int& m, int& n)
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
void Xuat(int a[][500], int m, int n)
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
int ViTriDuongDau(int a[], int n)
{
	for (int i = 0; i <= n - 1; i++)
		if (a[i] > 0)
			return i; 
	return -1;
}
int ViTriDuongNhoNhat(int a[], int n)
{
	int lc = ViTriDuongDau(a, n);
	if (lc == -1)
		return -1;
	for (int i = 0; i <= n - 1; i++)
		if (a[i] > 0 && a[i] < a[lc])
			lc = i;
	return lc;
}
int TimChuSo(int a[][500], int m, int n)
{
	int dem[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
		if (a[i][j] == 0)
			dem[0]++;
		int t = abs(a[i][j]);
		while (t != 0)
			{
			int dv = t % 10;
			dem[dv]++;
			t = t / 10;
			}
		}
	return ViTriDuongNhoNhat(dem, 10);
}
