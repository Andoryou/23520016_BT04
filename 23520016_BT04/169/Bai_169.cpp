#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;

void Nhap(float[][10], int&, int&);
void Xuat(float[][10], int, int);
int ktCon(float[][10], int, int,float[][10], int, int);

int main()
{
	float a[10][10], b[10][10];
	int n, m, k, l;
	cout << "Nhap ma tran" << endl;
	Nhap(b, k, l);
	Xuat(b, k, l);
	cout << "Nhap ma tran con" << endl;
	Nhap(a, n, m);
	Xuat(a, n, m);
	
	ktCon(a, m, n, b, k, l);
	if (ktCon(a, m, n, b, k, l) == 1)
		cout << "La ma tran con";
	else
		cout << "Khong phai ma tran con";
	return 0;
}

void Nhap(float a[][10], int& n, int& m)
{
	cout << "Nhap dong: ";
	cin >> m;
	cout << "Nhap cot: ";
	cin >> n;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
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

int ktCon(float a[][10], int m, int n,float b[][10], int k, int l)
{
	if (m > k || n > l)
		return 0;
	int flag = 0;
	for (int d = 0;d <= k - m;d++)
		for (int c = 0;c <= l - n;c++)
		{
			int co = 1;
			for (int i = 0;i < m;i++)
				for (int j = 0;j < n;j++)
					if (a[i][j] != b[d + i][c + j])
						co = 0;
			if (co == 1)
				flag = 1;
		}
	return flag;
}