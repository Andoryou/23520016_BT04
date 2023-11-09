#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int ktCucTieu(float[][500], int, int, int, int);
int ktCucDai(float[][500], int, int, int, int);
int DemCucTieu(float[][500], int, int);
int DemCucDai(float[][500], int, int);
int DemCucTri(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	cout << " So cuc tri la: ";
	cout << DemCucTri(a, m, n);
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
int ktCucTieu(float a[][500], int m, int n, int i, int j) {
	int flag = 1;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if (i + di >= 0 && i + di < m && j + dj >= 0 && j + dj < n && !(di == 0 && dj == 0) && a[i + di][j + dj] < a[i][j])
				flag = 0;
	return flag;
}
int ktCucDai(float a[][500], int m, int n, int i, int j) {
	int flag = 1;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
			if (i + di >= 0 && i + di < m && j + dj >= 0 && j + dj < n && !(di == 0 && dj == 0) && a[i + di][j + dj] > a[i][j])
				flag = 0;
	return flag;
}
int DemCucTieu(float a[][500], int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a, m, n, i, j) == 1)
				dem++;
	return dem;
}
int DemCucDai(float a[][500], int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j) == 1)
				dem++;
	return dem;
}
int DemCucTri(float a[][500], int m, int n) {
	int dem = DemCucTieu(a,m,n) + DemCucDai(a, m, n);
	return dem;
}