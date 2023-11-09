#include <iostream>
using namespace std;

void Nhap(float a[][500], int &m, int &n);
int ktDong(float a[][500], int m, int n, int dong);
void LietKe(float a[][500], int m, int n);

int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	LietKe(a, m, n);
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

int ktDong(float a[][500], int m, int n, int dong)
{
	bool coAm = false;
	bool coDuong = false;
	bool coKhong = false;
	for (int j = 0; j < n; j++)
	{
		if (a[dong][j] > 0)
			coDuong = true;
		else if (a[dong][j] < 0)
			coAm = true;
		else
			coKhong = true;
	}
	return coAm && coDuong && coKhong;
}

void LietKe(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		if (ktDong(a, m, n, i))
		{
			cout << "Dong " << i << " thoa man cac dieu kien.\n";
		}
	}
}