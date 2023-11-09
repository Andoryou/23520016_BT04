#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
void ChanGiam(int[][500], int, int);
void HoanVi(int[][500], int&, int&);
int main() {
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran cac so la: ";
	cout << endl;
	Xuat(a, m, n);
	ChanGiam(a, m, n);
	cout << "Ma trang sau khi sap xep la : ";
	cout << endl;
	Xuat(a, m, n);
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
			cout << setw(8) << setprecision(2) << a[i][j];
		cout << endl;
	}
}
void HoanVi(int& q, int& w) {
	int temp = q;
	q = w;
	w = temp;
}
void ChanGiam(int a[][500], int m, int n) {
	int b[500];
	int k;
	int i, j;
	k = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				b[k++] = a[i][j];
	for (i = 0; i <= k - 2; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (b[i] < b[j])
				HoanVi(b[i], b[j]);
	k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] % 2 == 0)
				a[i][j] = b[k++];
}