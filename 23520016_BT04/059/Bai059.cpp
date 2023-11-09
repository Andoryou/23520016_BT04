#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&, float&);
void Xuat(float[][500], int, int);
int TanSuat(float[][500], int, int, float);
int main() {
	float a[500][500];
	int m, n;
	float x;
	Nhap(a, m, n, x);
	cout << "Ma tran la: ";
	cout << endl;
	Xuat(a, m, n);
	cout << "Tan suat xuat hien gia tri " << x << " trong ma tran la: ";
	cout << TanSuat(a, m, n, x);
	return 0;
}
void Nhap(float a[][500], int& m, int& n, float& x) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap x: ";
	cin >> x;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}
void Xuat(float a[][500], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}
int TanSuat(float a[][500], int m, int n, float x) {
	int dem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (a[i][j] == x)
				dem++;
	}
	return dem;
}