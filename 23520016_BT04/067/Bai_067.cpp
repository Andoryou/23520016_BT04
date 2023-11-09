#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
bool ktChinhPhuong(int);
int Tong5m(int[][10], int, int);

int main()
{
	int a[10][10], n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "So luong chinh phuong la " << Tong5m(a, n, m);
	return 0;
}

void Nhap(int a[][10], int& n, int& m)
{
	cout << "Nhap dong: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = rand() % 200 - 100;
}

void Xuat(int a[][10], int n, int m)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool ktChinhPhuong(int k)
{
	int flag = false;
	for (int i = 1;i < k;i++)
		if (i*i == k)
			flag = true;
	return flag;
}

int Tong5m(int a[][10], int n, int m)
{
	int k = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
				if (ktChinhPhuong(a[i][j]) == true)
					k ++;
	return k;
}