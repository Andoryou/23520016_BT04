#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float TongCot(float[][500], int, int, int);
float TongNhoNhat(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	cout << "Tong cot nho nhat la: ";
	cout << setprecision(2) << fixed <<TongNhoNhat(a,m ,n);
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
float TongCot(float a[][500], int m, int n, int c) {
	int s = 0;
	for (int i = 0; i < m; i++)
		s = s + a[i][c];
	return s;
}
float TongNhoNhat(float a[][500], int m, int n) {
	float t = 0;
	for (int i = 0; i < m; i++)
		t = t + a[i][0];
	for (int j = 1; j < n; j++)
		if (TongCot(a, m, n, j) < t) 
			t = TongCot(a, m, n, j);
	return t;
}