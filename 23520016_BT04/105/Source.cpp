#include <iostream>
using namespace std;

void Nhap(float[][500], int &, int &, int &);
int ktDongTang(float[][500], int, int, int);

int main()
{
	float a[500][500];
	int m, n, d;
	Nhap(a, m, n, d);
	if (ktDongTang(a, m, n, d) == 1)
		cout << "Tang dan";
	else
		cout << "Khong tang dan";
	return 0;
}

void Nhap(float a[][500], int &m, int &n, int &d)
{
	cout << "Nhap so hang m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	cout << "Nhap dong d: ";
	cin >> d;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

int ktDongTang(float a[][500], int m, int n, int d)
{
	for (int j = 0; j < n - 1; j++)
	{
		if (a[d][j] > a[d][j + 1])
			return -1;
	}
	return 1;
}
