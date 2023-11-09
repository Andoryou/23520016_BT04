#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
bool ktrachan(int);
int DemGiaTri(int[][500], int, int, int);
int main() {
	int a[500][500];
	int m, n;
	int c;
	Nhap(a, m, n, c);
	cout << "ma tran la : "<< endl;
	Xuat(a, m, n);
	cout << "so luong so nguyen co chu so dau tien la chu so chan tren cot " << c + 1 << " la: ";
	cout << DemGiaTri(a, m, n, c);
	return 0;
}
void Nhap(int a[][500], int& m, int& n, int& c) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap cot: ";
	cin >> c;
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
bool ktrachan(int k) {
	int t = abs(k);
	while (t/10 >0) {
		t = t / 10;
	}
	if (t % 2 == 0)
		return true;
	return false;
}
int DemGiaTri(int a[][500], int m, int n, int c) {
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (ktrachan(a[i][c]))
			dem=dem+1;
	return dem;
}