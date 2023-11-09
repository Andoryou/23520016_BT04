#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(float[][100], int[][100], int&, int&);
void Xuat1(float[][100], int, int);
void Xuat2(int[][100], int, int, int&, int&);
int DemLanCan(float[][100], int, int, int, int);
void XayDung(float[][100], int, int, int[][100], int&, int&);
int main() {
	float a[100][100];
	int b[100][100];
	int m, n;
	int k, l;
	Nhap(a, b, m, n);
	cout << "ma tran A la: " << endl;
	Xuat1(a, m, n);
	XayDung(a, m, n, b, k, l);
	cout << "Ma tran B la: " << endl;
	Xuat2(b, m, n, k, l);
	return 0;
}
void Nhap(float a[][100], int b[][100], int& m, int& n) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}
void Xuat1(float a[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(2) << a[i][j];
		cout << endl;
	}
}
void Xuat2(int b[][100], int m, int n, int& k, int& l) {
	k = m;
	l = n;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++)
			cout << setw(6) << b[i][j];
		cout << endl;
	}
}
int DemLanCan(float a[][100], int m, int n, int d, int c) {
	int dem = 0;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if (d + di >= 0 && d + di < m && c + dj >= 0 && c + dj < n && !(di == 0 && dj == 0) && a[d + di][c + dj]>0)
				dem++;
	return dem;
}
void XayDung(float a[][100], int m, int n, int b[][100], int& k, int& l) {
	k = m;
	l = n;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
			b[i][j] = DemLanCan(a, m, n, i, j);
}