#include <iostream>
#include <cmath>
using namespace std;

bool kiemtracacchusodeule(int n) {
    bool kiemtra = false;
    n = abs(n);
    while (n > 0) {
        int du = n % 10;
        if (du % 2 == 0) {
            return false;
            break;
        }
        else {
            kiemtra = true;
        }
        n = n / 10;
    }
    return kiemtra;
}

void Nhap(int a[][500], int& m, int& n) {
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

int main() {


    int mang[500][500];
    int m, n;
    Nhap(mang, m, n);
    int x, y, z;
    for (x = 0; x < n; x++) {
        if (abs(mang[0][x]) % 2 == 1 && kiemtracacchusodeule(mang[0][x]) == 1) {
            cout << mang[0][x] << endl;
        }
    }
    for (y = 1; y < m - 1; y++) {
        if (abs(mang[y][0] % 2 == 1) && kiemtracacchusodeule(mang[y][0]) == true) {
            cout << mang[y][0] << endl;
        }
        if (abs(mang[y][n - 1] % 2 == 1) && kiemtracacchusodeule(mang[y][n - 1]) == true) {
            cout << mang[y][n - 1] << endl;
        }
    }
    for (z = 0; z < n; z++) {
        if (abs(mang[m - 1][z]) % 2 == 1 && kiemtracacchusodeule(mang[m - 1][z]) == true) {
            cout << mang[m - 1][z] << endl;
        }
    }
    return 0;
}