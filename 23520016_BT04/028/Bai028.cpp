#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktToanChan(int);
int TinhTong(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran da nhap la: " << endl;
	Xuat(a, m, n);
	cout << "\nKQ la: " << TinhTong(a, m, n);
	return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}
void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}
bool ktToanChan(int k)
{
	k = abs(k);
	if (k == 0)
		return false;
	bool flag = false;
	for (int t = k = abs(k); t != 0; t = t / 10)
	{
		if (t % 2 == 0)
			flag = true;
	}
	return flag;
}
int TinhTong(int a[][500], int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (ktToanChan(a[i][j]))
				s = s + a[i][j];
		}
	return s;
}