#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float DuongDau(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	cout << "Gia tri duong nho nhat la: ";
	cout << setprecision(2) << DuongDau(a, m, n);
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
float DuongDau(float a[][500], int m, int n) {
	float d = a[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				if (d < a[i][j])
					d = a[i][j];
	}
	return d;
}