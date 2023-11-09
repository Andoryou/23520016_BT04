#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
float TongCot(float[][10], int, int, int);
float TongNhoNhat(float[][10], int, int);
void LietKe(float[][10], int, int);

int main()
{
	float a[10][10];
	int n, m;
	Nhap(a, n, m);
	Xuat(a, n, m);
	cout << "Liet ke cot co tong nho nhat " << endl;
	LietKe(a, n, m);
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

float TongCot(float a[][10], int n, int m, int c)
{
	float k = 0;
	for (int i = 0;i < m;i++)
		k = k + a[i][c];
	return k;
}

float TongNhoNhat(float a[][10], int n, int m)
{
	float k = 0;
	for(int j=0;j<n-1;j++)
		if(TongCot(a,n,m,j)<TongCot(a,n,m,j+1))
			k=TongCot(a,n,m,j);
	return k;
}

void LietKe(float a[][10], int n, int m)
{
	int c = 0;
	for (int i = 0;i < m;i++)
		if (TongCot(a, n, m, i) == TongNhoNhat(a, n, m))
			c = i;
	for (int j = 0;j < m;j++)
		cout << setw(8) << a[j][c] << endl;
}