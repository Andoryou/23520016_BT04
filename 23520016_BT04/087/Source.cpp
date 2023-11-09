#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
int TanSuat(float[][500], int, int, float);
float TimGiaTri(float[][500], int, int);

int main()
{
	int m, n;
	float a[500][500];
	Nhap(a, m, n);
	cout << TimGiaTri(a, m, n);
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

int TanSuat(float a[][500], int m, int n, float value)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == value)
				count++;
		}
	}
	return count;
}

float TimGiaTri(float a[][500], int m, int n)
{
	int max_count = 0;
	int max_value = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int count = TanSuat(a, m, n, a[i][j]);
			if (count > max_count)
			{
				max_count = count;
				max_value = a[i][j];
			}
		}
	}
	return max_value;
}