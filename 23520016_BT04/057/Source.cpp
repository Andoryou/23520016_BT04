#include <iostream>
using namespace std;

void Nhap(int[][500], int &, int &);
int DemToanChan(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << DemToanChan(a, m, n);
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

int DemToanChan(int a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int flag = 1;
			for (int t = a[i][j]; t > 0; t /= 10)
			{
				int dv = t % 10;
				if (dv % 2 != 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				dem++;
		}
	}
	return dem;
}