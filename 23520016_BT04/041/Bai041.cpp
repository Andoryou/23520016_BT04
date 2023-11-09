#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
int Tong(int[][500], int, int, int);
int main() {
	int a[500][500];
	int m, n;
	int d;
	Nhap(a, m, n, d);
	cout << "Ma tran cac so la: " << endl;
	Xuat(a, m, n);
	cout << endl;
	cout << "tong cac so doi xung o dong " << d+1 << " la: ";
	cout << Tong(a, m, n, d);
	return 0;
}
void Nhap(int a[][500], int& m, int& n, int &d) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap dong: ";
	cin >> d;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (201) - 100;
}
void Xuat(int a[][500], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(6) << a[i][j];
		cout << endl;
	}
}
int Tong(int a[][500], int m, int n, int d) {
	int tong = 0;
	if (d >= m)
		cout << "Khong ton tai dong " << d+1;
	else
	for (int j = 0; j < n; j++) {
		if (a[d][j] > 3) {
			int t = sqrt(a[d][j]);
			if (t * t == a[d][j])
				tong = tong + a[d][j];
		}
	}
	return tong;
}