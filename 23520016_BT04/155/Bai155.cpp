#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void DichXuongCot(float[][500], int, int, int);
void DichXuong(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	DichXuong(a, m, n);
	cout << "Ma tran sau khi dich la: ";
	cout << endl;
	Xuat(a, m, n);
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
void DichXuongCot(float a[][500], int m, int n, int c) {
	float temp = a[m - 1][c];
	for (int i = m - 1; i >= 1; i--)
		a[i][c] = a[i - 1][c];
	a[0][c] = temp;
}
void DichXuong(float a[][500], int m, int n) {
	for (int j = 0; j < n; j++)
		DichXuongCot(a, m, n, j);
}