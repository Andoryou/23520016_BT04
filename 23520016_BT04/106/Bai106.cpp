#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&, int& c);
void Xuat(int[][500], int, int);
bool ktCotGiam(int[][500], int, int, int c);
void KL(int[][500], int, int, int c);

int main()
{
	int a[500][500];
	int m, n, c;
	Nhap(a, m, n, c);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	KL(a, m, n, c);
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
	cout << "Nhap cot c can xet: ";
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
bool ktCotGiam(int a[][500], int m, int n, int c)
{
	bool flag = true;
	int x = a[0][c];
	for (int i = 1; i < m; i++)
		if (a[i][c] > x)
		{
			flag = false;
			x = a[i][c];
		}
	return flag;
}
void KL(int a[][500], int m, int n, int c)
{
	if (ktCotGiam(a, m, n, c))
		cout << "Cot giam";
	else
		cout << "Cot khong giam";
}