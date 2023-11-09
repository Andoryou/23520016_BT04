#include <iostream>
using namespace std;

void Nhap(float a[][500], int &m, int &n);
void Xuat(float a[][500], int m, int n);
void DuongTang(float a[][500], int m, int n);
void DuongTangKhongMangPhu(float a[][500], int m, int n);
void HoanVi(float &a, float &b);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran ban dau:\n";
	Xuat(a, m, n);
	DuongTangKhongMangPhu(a, m, n);
	cout << "Ma tran sau khi sap xep:\n";
	Xuat(a, m, n);
	return 0;
}

void Nhap(float a[][500], int &m, int &n)
{
	cout << "Nhap so hang m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void DuongTangKhongMangPhu(float a[][500], int m, int n)
{
	int i, j, p, q;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
			{
				for (p = i; p < m; p++)
				{
					for (q = (p == i ? j + 1 : 0); q < n; q++)
					{
						if (a[p][q] > 0 && a[i][j] > a[p][q])
						{
							HoanVi(a[i][j], a[p][q]);
						}
					}
				}
			}
		}
	}
}

void HoanVi(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}
