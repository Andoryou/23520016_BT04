#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
void XuatAmGiam(float[][500], int, int);
void HoanVi(float &, float &);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	XuatAmGiam(a, m, n);
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
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void HoanVi(float &a, float &b)
{
	float temp = a;
	a = b;
	b = temp;
}

void XuatAmGiam(float a[][500], int m, int n)
{
	float b[500];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] < 0)
			{
				b[k++] = a[i][j];
			}
		}
	}

	for (i = 0; i <= k - 2; i++)
	{
		for (j = i + 1; j <= k - 1; j++)
		{
			if (b[i] < b[j])
			{
				HoanVi(b[i], b[j]);
			}
		}
	}

	for (i = 0; i < k; i++)
	{
		cout << fixed << setw(10) << setprecision(5);
		cout << b[i];
	}
}