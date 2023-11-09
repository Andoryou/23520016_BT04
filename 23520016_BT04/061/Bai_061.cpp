#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
bool ktHoanThien(int);
int DemHoanThien(int[][10], int, int, int);

int main()
{
	int a[10][10], n, m, c;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "Nhap dong ";
	cin >> c;
	cout << "So luong so hoan thien la  " << DemHoanThien(a, n, m, c);
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
	int s = 0;
	for (int i = 1;i < k;i++)
		if (k % i == 0)
			s = s + i;
	return(s == k);
}

int DemHoanThien(int a[][10], int n, int m, int c)
{
	int dem = 0;
	for (int j = 0;j < m;j++)
		if (ktHoanThien(a[c][j]) == true)
			dem++;
	return dem;
}
