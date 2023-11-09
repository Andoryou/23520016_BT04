#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(int[][10], int&, int&);
void Xuat(int[][10], int, int);
bool ktToanLe(int);
int TinhLe(int[][10], int, int);

int main()
{
	int a[10][10], n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "Sau khi tinh le:" << endl;
	cout <<setw(20) <<TinhLe(a, n, m);
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

bool ktToanLe(int k)
{
	bool flag = true;
	for (int t = abs(k);t != 0;t = t / 10)
	{
		int dv = t % 10;
		if (dv % 2 == 0)
			flag = false;
	}
	return flag;
}

int TinhLe(int a[][10], int n, int m)
{
	int k = 1;
	for (int i = 0;i < m;i = i + 2)
	{
		for (int j = 0;j < n;j++)
			if (ktToanLe(a[i][j] == true))
				k = k * a[i][j];
	}
	return k;
}