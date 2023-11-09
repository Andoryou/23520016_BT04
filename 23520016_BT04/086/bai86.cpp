#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

void Nhap(float a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}
void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(5);
			cout << a[i][j];
		}
		cout << "\n";
	}
}
int TimGiaTriLonNhat(float a[][500], int m, int n) 
{
	float max_value = a[0][0];
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j] > max_value) 
			{
				max_value = a[i][j];
			}
		}
	}
	return max_value;
}
void LietKe(float a[][500], int m, int n) 
{
	float max_value = TimGiaTriLonNhat(a, m, n);

	cout << "Cac dong chua gia tri lon nhat la:\n";
	for (int i = 0; i < m; i++) {
		bool coMax = false;
		for (int j = 0; j < n; j++) 
		{
			if (a[i][j] == max_value) 
			{
				coMax = true;
				break;
			}
		}
		if (coMax) {
			cout << "Dong " << i << ": ";
			for (int j = 0; j < n; j++) 
			{
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	LietKe(a, m, n);
	return 0;
}