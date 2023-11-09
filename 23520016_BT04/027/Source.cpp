#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int &, int &);
int TongNguyenTo(int[][500], int, int);

int main()
{
	int m, n;
	int a[500][500];
	Nhap(a, m, n);
	cout << TongNguyenTo(a, m, n);
	return 0;
}

void Nhap(int a[][500], int &m, int &n)
{
	cout << "Nhap so hang m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

int TongNguyenTo(int a[][500], int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int flag = 0;
			for (int index = 1; index <= a[i][j]; index++)
			{
				if (a[i][j] % index == 0)
					flag++;
			}
			if (flag == 2)
				s = s + a[i][j];
		}
	}
	return s;
}