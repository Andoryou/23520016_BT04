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
float Tong(float a[][500], int m, int n) {
	float Tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			float s = a[i][j];
			bool Max = true;
			for (int dx = -1; dx <= 1; dx++) {
				for (int dy = -1; dy <= 1; dy++) {
					int I = i + dx;
					int J = j + dy;
					if (I >= 0 && I < m && J >= 0 && J < n) {
						if (a[I][J] >= s && !(dx == 0 && dy == 0)) {
							Max = false;
						}
					}
				}
			}
			if (Max) {
				Tong += s;
			}
		}
	}
	return Tong;
}
int main()
{
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	float KetQua = Tong(a, m, n);
	cout << "Tong cac cuc dai trong ma tran:" << KetQua;
	return 0;
}