#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
void Xuat2(float[][500], int&, int&);
int ktCon(float[][500], int, int, int, int);
void ConCuoi(float[][500], int, int, int&, int&);
int main() {
	float a[500][500];
	int m, n;
	int vtd, vtc;
	Nhap(a, m, n);
	cout << "Ma tran la: ";
	cout << endl;
	Xuat(a, m, n);
	cout << "Ma tran con la: ";
	cout << endl;
	ConCuoi(a, m, n, vtd, vtc);
	Xuat2(a, vtd, vtc);
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
void Xuat2(float a[][500], int &vtd, int& vtc) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << setw(8) << setprecision(2) << a[vtd + i][vtc + j];
		cout << endl;
	}
}
int ktCon(float a[][500], int m, int n, int vtd, int vtc) {
	int flag = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (a[vtd + i][vtc + j] >= 0)
				flag = 0;
	return flag;
}
void ConCuoi(float a[][500], int m, int n, int& vtd, int& vtc) {
	for (vtd = m - 3; vtd >= 0; vtd--)
		for (vtc = n - 3; vtc >= 0; vtc--)
			if (ktCon(a, m, n, vtd, vtc) == 1)
				return;
	vtd = vtc = -1;
}

