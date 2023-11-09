#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
int ktCucTieu(float[][500], int, int, int, int);
void LietKe(float[][500], int, int);
int main() {
	float a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: ";
	cout << endl;
	Xuat(a, m, n);
	cout << " cac phan tu cuc tieu la : ";
	LietKe(a, m, n);
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
void LietKe(float a[][500], int m, int n) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucTieu(a,m,n,i,j) == 1)
				cout << setw(8) << setprecision(2) << a[i][j];
}