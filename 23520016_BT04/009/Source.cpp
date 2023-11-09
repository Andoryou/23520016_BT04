#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int &, int &);
void LietKe(int[][500], int, int);

int main()
{
	int m, n;
	int a[500][500];
	Nhap(a, m, n);
	cout << "Cac so chan trong mang: ";
	LietKe(a, m, n);
	return 0;
}

void LietKe(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				cout << setw(8) << a[i][j];
			}
		}
	}
	cout << endl;
}

void Nhap(int a[][500], int &m, int &n)
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
