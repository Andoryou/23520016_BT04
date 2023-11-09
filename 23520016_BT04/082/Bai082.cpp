#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktSoChan(int);
int SoChanLonNhat(int[][500], int, int);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "\nMa tran luc dau la: " << endl;
	Xuat(a, m, n);

	cout << "ket qua la: " << SoChanLonNhat(a, m, n);

	return 0;
}
void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}
void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4);
			cout << a[i][j];
		}
		cout << endl;
	}
}
bool ktSoChan(int k)
{
	bool flag = false;
	if (k % 2 == 0)
		flag = true;
	return flag;
}
int SoChanLonNhat(int a[][500], int m, int n)
{
	int t = 0;
	int max = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (ktSoChan(a[i][j]))
				t = a[i][j];
			if (t > max)
				max = t;
		}
	return max;

}