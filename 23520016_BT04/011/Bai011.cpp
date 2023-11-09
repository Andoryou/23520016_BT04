#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
void Lietke(int[][500], int, int);
int main() {
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran cac so la: " << endl;
	Xuat(a, m, n);
	cout << endl;
	cout << "cac so chinh phuong la: ";
	Lietke(a, m, n);
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
			a[i][j] = rand()%(201) - 100;
}
void Xuat(int a[][500], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(6) << a[i][j];
		cout << endl;
	}
}
void Lietke(int a[][500], int m, int n) {
	for(int i=0; i< m; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j] > 3) {
				int t = sqrt(a[i][j]);
				if (t * t == a[i][j])
					cout << setw(6) << a[i][j];
			}
		}
}