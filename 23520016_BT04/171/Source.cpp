#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

void Nhap(float[][500], int &, int &);
void TimConToanDuong(float[][500], int, int, int &, int &, int &, int &);
void Xuat(float[][500], int, int, int, int);

int main()
{
	float a[500][500];
	int m, n;
	int x, y, w, h;
	Nhap(a, m, n);
	TimConToanDuong(a, m, n, x, y, w, h);
	Xuat(a, x, y, w, h);
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

void TimConToanDuong(float a[][500], int m, int n, int &x, int &y, int &w, int &h)
{
	int S[500][500] = {0};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0)
			{
				S[i][j] = (i == 0 || j == 0) ? 1 : min({S[i][j - 1], S[i - 1][j], S[i - 1][j - 1]}) + 1;
			}
		}
	}

	int max_of_s = S[0][0];
	x = 0;
	y = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max_of_s < S[i][j])
			{
				max_of_s = S[i][j];
				x = i;
				y = j;
			}
		}
	}

	w = max_of_s;
	h = max_of_s;
}

void Xuat(float a[][500], int x, int y, int w, int h)
{
	for (int i = x; i < x + h; i++)
	{
		for (int j = y; j < y + w; j++)
		{
			cout << setw(8) << a[i][j];
		}
		cout << endl;
	}
}