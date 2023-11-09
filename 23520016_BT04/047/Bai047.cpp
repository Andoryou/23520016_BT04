#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float TongBien(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << " Ma tran la: ";
	cout << endl;
	Xuat(a, m, n);
	cout << "Tong bien la: ";
	cout << setprecision(2) << fixed << TongBien(a, m, n);
	return 0;
}
void Nhap(float a[][500], int& m, int& n) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}
void Xuat(float a[][500], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(2) << a[i][j];
		cout << endl;
	}
}
float TongBien(float a[][500], int m, int n) {
	float s = 0;
	for (int j = 0; j <= n - 2; j++)
		s = s + a[0][j];
	for (int i = 0; i <= m - 2; i++)
		s = s + a[i][n - 1];
	for (int j = n - 1; j >= 1; j--)
		s = s + a[m - 1][j];
	for (int i = m - 1; i >= 1; i--)
		s = s + a[i][0];
	return s;
}