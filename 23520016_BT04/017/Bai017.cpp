#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
bool ktHoanThien(int);
void LietKe(int[][500], int, int, int);
int main() {
	int a[500][500];
	int m, n;
	int d;
	Nhap(a, m, n, d);
	cout << "ma tran cac so la: " << endl;
	Xuat(a, m, n);
	cout << "Cac so hoan thien o dong " << d << " la: ";
	LietKe(a, m, n, d);
	return 0;
}
void Nhap(int a[][500], int& m, int& n, int& d) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap d: ";
	cin >> d;
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
bool ktHoanThien(int k) {
	int s = 0;
	for (int i = 1; i < k; i++)
		if (k % i == 0)
			s = s + i;
	if (s == k)
		return true;
	return false; 
}
void LietKe(int a[][500], int m, int n, int d) {
	if (d >= m)
		cout << "Khong ton tai dong " << d;
	else
		for (int j = 0; j < n; j++) {
			if (ktHoanThien(a[d][j]))
				cout << setw(6) << a[d][j];
		}
}