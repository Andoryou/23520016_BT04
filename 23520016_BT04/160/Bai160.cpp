#include <iostream>
using namespace std;

void NhapMaTran(int[][100], int&, int&);
void XuatMaTran(int[][100], int, int);
void DichTraiXoayVong(int[][100], int, int);

int main() {
    int a[100][100];
    int m, n;

    NhapMaTran(a, m, n);
    XuatMaTran(a, m, n);

    DichTraiXoayVong(a, m, n);

    cout << "Ma tran sau khi dich trai xoay vong:" << endl;
    XuatMaTran(a, m, n);

    return 0;
}
void NhapMaTran(int a[][100], int& m, int& n) {
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    cout << "Nhap ma tran " << m << "x" << n << ":" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][100], int m, int n) {
    cout << "Ma tran " << m << "x" << n << ":" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void DichTraiXoayVong(int a[][100], int m, int n) {
    if (m < 2 || n < 2)
    {
        return;
    }

    int temp = a[0][0];
    int i, j;

    // Dịch biên trên cùng từ trái qua phải
    for (j = 0; j < n - 1; j++) {
        a[0][j] = a[0][j + 1];
    }

    // Dịch biên bên phải từ trên xuống dưới
    for (i = 0; i < m - 1; i++) {
        a[i][n - 1] = a[i + 1][n - 1];
    }

    // Dịch biên dưới cùng từ phải qua trái
    for (j = n - 1; j > 0; j--) {
        a[m - 1][j] = a[m - 1][j - 1];
    }

    // Dịch biên bên trái từ dưới lên trên
    for (i = m - 1; i > 1; i--) {
        a[i][0] = a[i - 1][0];
    }

    a[1][0] = temp; // Gán giá trị gốc trái trên vào biên phải trên
}