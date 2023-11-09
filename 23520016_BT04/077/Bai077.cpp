#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(float[][500], int&, int&, int&);
void Xuat(float[][500], int, int);
float gtln(float[][500], int, int, int);
int main(){
	float a[500][500];
	int m, n;
	int d;
	Nhap(a, m, n, d);
	cout << "Ma tran cac so la: " << endl;
	Xuat(a, m, n);
	cout << "gia tri lon nhat tren dong " << d + 1 << " la :";
	cout << gtln(a, m, n, d);
	return 0;
}
void Nhap(float a[][500], int& m, int& n, int &d) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap dong: ";
	cin >> d;
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
float gtln(float a[][500], int m, int n, int d) {
	float t = a[d][0];
	for (int j = 1; j < n; j++)
		if (t < a[d][j])
			t = a[d][j];
	return t;
}