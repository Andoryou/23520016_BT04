#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
float LonNhatCot(float[][500], int, int, int);
void ThemDong(float[][500], int&, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	ThemDong(a, m, n);
	cout << "Ma tran sau khi them dong la: "; 
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
float LonNhatCot(float a[][500], int m, int n, int c) {
	float t = a[0][c];
	for (int i = 1; i < m; i++)
		if (t < a[i][c])
			t = a[i][c];
	return t;
}
void ThemDong(float a[][500], int& m, int n) {
	int d = m;
	for (int j = 0; j < n; j++) {
		for (int i = m; i >= d + 1; i--)
			a[i][j] = a[i - 1][j];
		a[d][j] = LonNhatCot(a, m, n, j);
	}
	m++;
}