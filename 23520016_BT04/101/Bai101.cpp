#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int TonTaiDuong(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran cac so la: ";
	cout << endl;
	Xuat(a, m, n);
	if (TonTaiDuong(a, m, n) == 1)
		cout << "Ton tai so duong";
	else
		cout << "khong ton tai so duong";
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
int TonTaiDuong(float a[][500], int m, int n) {
	int flag = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] > 0)
				flag = 1;
	return flag;
}