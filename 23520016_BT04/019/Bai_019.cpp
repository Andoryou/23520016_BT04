#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
bool ktDoiXung(int);
void LietKe(int [][10], int, int, int);

int main()
{
	int a[10][10], n, m, c;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "Liet ke cac so doi xung tren cot ";
	cin >> c;
	LietKe(a, n, m, c);
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

bool ktDoiXung(int k)
{
	k = abs(k);
	int dn = 0;

	for (int t = k;t != 0;t = t / 10)
	{
		int dv = t % 10;
		dn = dn * 10 + dv;
	}
	if (dn == k)
		return true;
	return false;
}

void LietKe(int a[][10], int n, int m, int c)
{
	for (int i = 0;i < m;i++)
		if (ktDoiXung(a[i][c]) == true)
			cout << a[i][c] << " ";

}