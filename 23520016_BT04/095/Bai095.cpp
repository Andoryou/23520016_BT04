#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int DemChuSo(int);
int DemCot(int[][500], int, int, int);
int DemLonNhat(int[][500], int, int);
void LietKe(int[][500], int, int);
int main() {
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "ma tran la: " << endl;
	Xuat(a, m, n);
	cout << " cac cot nhieu chu so nhat trong ma tran cac so nguyen la: ";
	LietKe(a,m,n);
	return 0;
}
void Nhap(int a[][500], int& m, int& n) {
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
			cout << setw(6) << a[i][j];
		cout << '\n';
	}
}
int DemChuSo(int k) {
	int t = k;
	int dem = 0;
	while (t != 0) {
		dem++;
		t = t / 10;
	}
	return dem;
}
int DemCot(int a[][500], int m, int n, int c) {
	int t = 0;
	for (int i = 0; i < m; i++)
		t = t + DemChuSo(a[i][c]);
	return t;
}
int DemLonNhat(int a[][500], int m, int n) {
	int t = 0;
	for (int i = 0; i < m; i++)
		t = t + DemChuSo(a[i][0]);
	for (int j = 1; j < n; j++) {
			if (DemCot(a,m,n,j) > t)
				t = DemCot(a,m,n,j);
	}
	return t;
}
void LietKe(int a[][500], int m, int n) {
	int s = 0;
	for (int j = 0; j < n; j++) {
			if(DemCot(a,m,n,j) == DemLonNhat(a, m, n))
				cout << setw(5) << j+1;
	}
}