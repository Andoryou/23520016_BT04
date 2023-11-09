#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&, int &);
void Xuat(int[][500], int, int);
int ktDong(int[][500], int, int, int, int);
bool ktNguyenTo(int);
bool ktChinhPhuong(int);
void XoaDong(int[][500], int&, int, int);
void XoaDong(int[][500], int&, int);
int main() {
	int a[500][500];
	int m, n;
	int d;
	Nhap(a, m, n, d);
	cout << "Ma tran la: ";
	cout << endl;
	Xuat(a, m, n);
	XoaDong(a, m, n);
	cout << "Ma tran sau khi sap xep la: ";
	cout << endl;
	Xuat(a, m, n);
	return 0;
}
void Nhap(int a[][500], int& m, int& n, int &d) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (201) - 100;
}
void Xuat(int a[][500], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(2) << a[i][j];
		cout << endl;
	}
}
bool ktNguyenTo(int k) {
	int t = k;
	int dem = 0;
	for (int i = 1; i <= t; i++)
		if (t % i == 0)
			dem++;
	if (dem == 2)
		return true;
	return false;
}
bool ktChinhPhuong(int k) {
	int t = k;
	int o = sqrt(t);
	if (o * o == t)
		return true;
	return false;
}
int ktDong(int a[][500], int m, int n, int d){
	int flag1 = 0;
	int flag2 = 0;
	for (int j = 0; j < n; j++) {
		if (ktNguyenTo(a[d][j]))
			flag1 = 1;
		if (ktChinhPhuong(a[d][j]))
			flag2 = 1;
	}
	return flag1 * flag2;
}
void XoaDong(int a[][500], int& m, int n, int d) {
	for (int j = 0; j < n; j++) {
		for (int i = d; i < m - 1; i++)
			a[i][j] = a[i + 1][j];
	}
	m--;
}
void XoaDong(int a[][500], int& m, int n) {
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i) == 1)
			XoaDong(a, m, n, i);
}