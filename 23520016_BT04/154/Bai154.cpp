#include <iostream>
#include<iomanip>
using namespace std;

void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int, int);
void NguyenHoa(float[][100], int, int);

int main()
{
	float a[100][100];
	int m, n, c;
	Nhap(a, m, n);
	cout << "Ma tran luc dau la: " << endl;
	Xuat(a, m, n);
	NguyenHoa(a, m, n);
	cout << "Ma tran luc sau la: " << endl;
	Xuat(a, m, n);

	return 0;
}
void Nhap(float a[][100], int& m, int& n)
{
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}
void Xuat(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8) << a[i][j];
		}
		cout << endl;
	}
}
void NguyenHoa(float a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		if (a[i][j] > 0)
		a[i][j] = int(a[i][j] + 0.5);
	else
		a[i][j] = int(a[i][j] - 0.5);
}