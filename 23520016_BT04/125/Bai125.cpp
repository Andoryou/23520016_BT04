#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&, int &);
void Xuat(float[][500], int, int);
void HoanVi(float &, float &);
void SapCotGiam(float[][500], int, int, int);
int main() {
	float a[500][500];
	int m, n;
	int c;
	Nhap(a, m, n, c);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	SapCotGiam(a, m, n, c);
	cout << "Ma tran sau khi sap xep la: ";
	cout << endl;
	Xuat(a, m, n);
	return 0;
}
void Nhap(float a[][500], int& m, int& n, int& c) {
	cout << "Nhap m: ";
	cin >> m; 
	cout << "Nhap n: ";
	cin >> n;
	cout << "nhap chi so cot : ";
	cin >> c;
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
void HoanVi(float &b, float &c) {
	int t = b;
	b = c;
	c = t;
}
void SapCotGiam(float a[][500], int m, int n, int c) {
	for (int i = 0; i < m - 1; i++)
		for (int j = i + 1; j < m; j++)
			if (a[i][c] < a[j][c])
				HoanVi(a[i][c], a[j][c]);
}
