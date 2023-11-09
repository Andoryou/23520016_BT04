#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void Nhap(string, int[][500], int&, int&);
void Xuat(int[][500], int, int);

int main()
{
	int a[500][500], m, n;
	Nhap("intdata02.inp", a, m, n);
	Xuat(a, m, n);
	return 0;
}

void Nhap(string filename, int a[][500], int& m, int& n)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			fi >> a[i][j];
	}
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}