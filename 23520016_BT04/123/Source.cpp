#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &, int &);
void SapDongGiam(float[][500], int, int, int);
void HoanVi(float &, float &);
void Xuat(float[][500], int, int);

int main()
{
	float a[500][500];
	int m, n, d;
	Nhap(a, m, n, d);
	SapDongGiam(a, m, n, d);
	Xuat(a, m, n);
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

void SapDongGiam(float a[][500], int m, int n, int d)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[d][i] < a[d][j])
				HoanVi(a[d][i], a[d][j]);
		}
	}
}

void HoanVi(float &number1, float &number2)
{
	float temp = number1;
	number1 = number2;
	number2 = temp;
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