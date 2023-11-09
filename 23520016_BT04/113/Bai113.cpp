#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
int ktDong(int[][500], int, int, int);
void LietKe(int[][500], int, int);
int main() {
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la";
	cout << endl;
	Xuat(a, m, n);
	cout << "Chi so cac dong chua toan gia tri chan trong ma tran la: ";
	LietKe(a, m, n);
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
			a[i][j] = rand() % (201) - 100;
}
void Xuat(int a[][500], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << setw(6) << a[i][j];
		cout << endl;
	}
}
int ktDong(int a[][500], int m, int n, int d) {
	int flag = 1;
	for (int j = 0; j < n; j++)
		if (a[d][j] % 2 != 0)
			flag = 0;
	return flag;
}
void LietKe(int a[][500], int m, int n) {
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i) == 1)
			cout << setw(4) << i;
}