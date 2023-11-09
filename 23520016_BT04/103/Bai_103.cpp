#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
bool ktHoanThien(int);
void TonTaiHoanThien(int[][10], int, int);

int main()
{
	int a[10][10], n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "Ma tran tren ";
	TonTaiHoanThien(a, n, m);
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

bool ktHoanThien(int k)
{
	k = abs(k);
	int s = 0;
	for (int i = 1;i < k;i++)
		if (k % i == 0)
			s = s + i;
	return (s == k);
}

void TonTaiHoanThien(int a[][10], int n, int m)
{
	int k = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (ktHoanThien(a[i][j]) == true)
			{
				k++;
			}
	if (k == 0)
		cout << "khong ton tai so hoan thien: ";
	else
		cout << "Co ton tai so hoan thien: ";
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (ktHoanThien(a[i][j]) == true)
			{
				cout <<setw(8)<<"\n" << a[i][j];
			}
}