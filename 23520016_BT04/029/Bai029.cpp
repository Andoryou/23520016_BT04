#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktDang3m(int);
int Tong3m(int[][500], int, int);
int main() {
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "ma tran la: ";
	cout << endl;
	Xuat(a, m, n);
	cout << " Tong cac so co dang 3m la: ";
	cout << Tong3m(a, m, n);
	return 0;
}
void Nhap(int a[][500], int& m, int& n) {
	cout << "Nhap m : ";
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
			cout << setw(6) << a[i][j];
		cout << endl;
	}
}
bool ktDang3m(int n) {
	if (n < 1)
		return false;
	bool flag = true;
	int t = n;
	while (t > 1) {
		int du = t % 3;
		if (du != 0)
			flag = false;
		t /= 3;
	}
	return flag;
}
int Tong3m(int a[][500], int m, int n) {
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktDang3m(a[i][j]))
				s = s + a[i][j];
	return s;
}