#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
float Tong_Am(float[][10], int, int);

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "Tong am la " << Tong_Am(a, n, m);
	
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
			a[i][j] = rand()/(RAND_MAX/200.0) - 100.0;
}

void Xuat(float a[][10], int n, int m)
{
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
			cout << setw(8) <<setprecision(4)<< a[i][j];
		cout << endl;
	}
}

float Tong_Am(float a[][10], int n, int m)
{
	float k = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (a[i][j] < 0)
				k = k + a[i][j];
	return k;
}