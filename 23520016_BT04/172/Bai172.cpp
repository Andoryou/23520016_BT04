#include <iostream>
using namespace std;

void NhapMaTran(float[][100], int&, int&);
void XuatMaTran(float[][100], int, int);
void TimMaTranConCoTongLonNhat(float[][100], int, int);

int main() {
    float a[100][100];
    int m, n;

    NhapMaTran(a, m, n);
    XuatMaTran(a, m, n);

    TimMaTranConCoTongLonNhat(a, m, n);

    return 0;
}

void NhapMaTran(float a[][100], int& m, int& n) 
{
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(float a[][100], int m, int n) 
{
    cout << "Ma tran " << m << "x" << n << ":" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void TimMaTranConCoTongLonNhat(float a[][100], int m, int n) 
{
    float maxTong = 0;
    int maxHangDau = 0;
    int maxCotDau = 0;
    int maxHangCuoi = 0;
    int maxCotCuoi = 0;

    for (int hangDau = 0; hangDau < m; hangDau++) 
    {
        for (int cotDau = 0; cotDau < n; cotDau++) 
        {
            for (int hangCuoi = hangDau; hangCuoi < m; hangCuoi++)
            {
                for (int cotCuoi = cotDau; cotCuoi < n; cotCuoi++) 
                {
                    float tong = 0;
                    for (int i = hangDau; i <= hangCuoi; i++) 
                    {
                        for (int j = cotDau; j <= cotCuoi; j++)
                        {
                            tong += a[i][j];
                        }
                    }

                    if (tong > maxTong) {
                        maxTong = tong;
                        maxHangDau = hangDau;
                        maxCotDau = cotDau;
                        maxHangCuoi = hangCuoi;
                        maxCotCuoi = cotCuoi;
                    }
                }
            }
        }
    }

    cout << "Ma tran con co tong lon nhat: " << endl;
    for (int i = maxHangDau; i <= maxHangCuoi; i++) 
    {
        for (int j = maxCotDau; j <= maxCotCuoi; j++) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Tong cua ma tran con nay: " << maxTong << endl;
}
