#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void Nhap(float[][100], int&, int&);
void Xuat(float[][100], int&, int&);
void Xoay90(float[][100], int&, int&);
int main() {
	float a[100][100];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	Xoay90(a, m, n);
	cout << "Ma tran sau khi xoay la: ";
	cout << endl;
	Xuat(a, m, n);
	return 0;
}
void Nhap(float a[][100], int& m, int& n) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() / (RAND_MAX / 200.0) - 100.0;
}
void Xuat(float a[][100], int &m, int &n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(8) << setprecision(2) << a[i][j];
		cout << endl;
	}
}
void Xoay90(float a[][100], int& m, int& n) {
	float b[100][100];
	int k, l;
	k = n;
	l = m;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < l; j++)
			b[i][j] = a[j][n - 1 - i];
	m = k;
	n = l;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b[i][j];
}