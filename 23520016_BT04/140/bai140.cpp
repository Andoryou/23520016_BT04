#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;

void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}
void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << "\n";
	}
}
void SapXep(int a[][500], int m, int n)
{
	int* tempArray = new int[m * n];
	int index = 0;
	for (int i = 0; i < m; i++) 
	{
		if (i % 2 == 0) 
		{
			for (int j = 0; j < n; j++)
				tempArray[index++] = a[i][j];
		}
		else {
			for (int j = n - 1; j >= 0; j--)
				tempArray[index++] = a[i][j];
		}
	}
	sort(tempArray, tempArray + m * n);
	index = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = tempArray[index++];

	delete[] tempArray;
}
int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	cout << "\n";
	SapXep(a, m, n);
	return 0;
}