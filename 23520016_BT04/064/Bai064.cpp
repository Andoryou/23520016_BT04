#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
bool ktNguyenTo(int k);
int Dem(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n, c;
	Nhap(a, m, n, c);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	int kq = Dem(a, m, c);
	cout << "ket qua la: " << kq;

	return 0;
}
void Nhap(int a[][500], int& m, int& n, int& c)
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
	cout << "Nhap cot c muon xet: ";
	cin >> c;
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
bool ktNguyenTo(int k)
{
	int dem = 0;
	for (int i = 1; i < k; i++)
		if (k % i == 0)
			dem++;
	if (dem == 2)
		return true;
	return false;
}
int Dem(int a[][500], int m, int c)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (ktNguyenTo(a[i][c]))
			dem++;
	return dem;
}
