#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);
bool ktChinhPhuong(int);
int DemChinhPhuong(int[][500], int, int);
int main() {
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	cout << "Ma tran la: " << endl;
	Xuat(a, m, n);
	cout << "so luong so chinh phuong la: ";
	cout << DemChinhPhuong(a, m, n);
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
bool ktChinhPhuong(int k){
	if (k <= 3)
		return false;
	int t = sqrt(k);
	if (t * t == k)
		return true;
	return false;
}
int DemChinhPhuong(int a[][500], int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktChinhPhuong(a[i][j]))
				dem++;
	return dem;
}