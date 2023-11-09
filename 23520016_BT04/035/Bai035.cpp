#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void Nhap(int[][500], int&, int&, int&);
void Xuat(int[][500], int, int);
bool ktDoiXung(int);
int tongdoixung(int[][500], int, int, int);
int main() {
	int a[500][500];
	int m, n;
	int d;
	Nhap(a, m, n, d);
	cout << "ma tran cac so la: " << endl;
	Xuat(a, m, n);
	cout << "tong cac so doi xung o dong " << d << " la: ";
	cout << tongdoixung(a, m, n, d);
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
bool ktDoiXung(int n) {
	int s = 0;
	for (int t = abs(n); t != 0; t / 10) {
		s = s * 10 + t % 10;
	}
		
	if (s == n)
		return true;
	return false;
}
int tongdoixung(int a[][500], int m, int n, int d) {
	int tong = 0;
	if (d >= m)
		cout << "Khong ton tai dong " << d;
	else
		for (int j = 0; j < n; j++) {
			if (ktDoiXung(a[d][j]))
				tong = tong + a[d][j];
		}
	return tong;
}