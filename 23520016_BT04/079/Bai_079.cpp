#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
float NhoNhat(float[][10], int, int);
int DemNhoNhat(float[][10], int, int);

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "So nho nhat la " << NhoNhat(a, n, m) << endl;
	cout << "So luong gia tri nho nhat la " << DemNhoNhat(a, n, m);
	return 0;
}

void Nhap(float a[][10], int& n, int& m)
{
	cout << "Nhap dong: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}

void Xuat(float a[][10], int n, int m)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(8) << setprecision(4) << a[i][j];
		cout << endl;
	}
}

float NhoNhat(float a[][10], int n, int m)
{
	float k;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n - 1;j++)
			if (a[i][j] < a[i][j + 1])
				k = a[i][j];
	return k;
}

int DemNhoNhat(float a[][10], int n, int m)
{
	int dem = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] == NhoNhat(a, n, m))
				dem++;
	return dem;
}