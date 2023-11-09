#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;
void Nhap(long[][500], long&, long&);
void Xuat(long[][500], long, long);
int main() {
	long m;
	long n;
	long a[500][500];
	Nhap(a, m, n);
	cout << "Mang 2 chieu day cac so la: ";
	cout << endl;
	Xuat(a, m, n);
	return 0;
}
void Nhap(long a[][500], long& m, long& n) {
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
}
void Xuat(long a[][500], long m, long n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(6) << a[i][j];
		cout << "\n";
	}
}