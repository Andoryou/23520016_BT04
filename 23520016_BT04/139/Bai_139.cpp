#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<algorithm>

using namespace std;

void Nhap(int&,int&,int [][100]);
void Xuat(int, int, int[][100]);
void XoanOc(int, int, int[][100]);

int main()
{
	int n, m, a[100][100];
	Nhap(n, m, a);
	Xuat(n, m, a);
	XoanOc(n, m, a);
	cout << "Sau khi xep cac phan tu trong ma tran theo hinh xoan oc: " << endl;
	Xuat(n, m, a);
	return 0;
}

void Nhap(int& n,int& m,int a[][100])
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
void Xuat(int n,int m,int a[][100])
{
	for (int i = 0;i < m;i++) 
	{
		for (int j = 0;j < n;j++)
			cout <<setw(8)<< a[i][j] << " ";
		cout << endl;
	}
}

void XoanOc(int n,int m, int a[][100])
{
	int b[50];
	int k = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			b[k++] = a[i][j];
	sort(b, b + n * m);

	for (int i = 0;i < n * m;i++)
		cout << b[i] << " ";
	cout << endl;
	int tren = 0, duoi = m - 1, trai = 0, phai = n - 1, l = 0;
	while (tren <= duoi && trai <= phai)
	{
		for (int j = trai;j <= phai;j++)
			a[tren][j] = b[l++];
		tren++;
		for (int i = tren;i <= duoi;i++)
			a[i][phai] = b[l++];
		phai--;
		for (int j = phai;j >= trai;j--)
			a[duoi][j] = b[l++];
		duoi--;
		for (int i = duoi;i >= tren;i--)
			a[i][trai] = b[l++];
		trai++;

	}
}