#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int &, int &, int &);
void LietKe(int[][500], int, int, int);

int main()
{
	int m, n, d;
	int a[500][500];
	Nhap(a, m, n, d);
	LietKe(a, m, n, d);
	return 0;
}

void Nhap(int a[][500], int &m, int &n, int &d)
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

void LietKe(int a[][500], int m, int n, int d)
{
	cout << "Cac so chan tren dong " << d << " la:";
	for (int j = 0; j < n; j++)
	{
		if (a[d][j] % 2 == 0)
		{
			cout << setw(3) << a[d][j];
		}
	}
	cout << endl;
}