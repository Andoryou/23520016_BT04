#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
void SapTang(float[][500], int, int);
void Xuat(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	SapTang(a, m, n);
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
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

void SapTang(float a[][500], int m, int n)
{
	float b[500];
	int k;
	int i, j;

	k = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[k++] = a[i][j];
		}
	}

	for (i = 0; i <= k - 2; i++)
	{
		for (j = i + 1; j <= k - 1; j++)
		{
			if (b[i] > b[j])
			{
				float temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}

	k = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = b[k++];
		}
	}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8) << a[i][j];
		}
		cout << endl;
	}
}