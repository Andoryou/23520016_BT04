#include <iostream>
#include <iomanip>
using namespace std;

void NhapMaTran(int[][100], int&, int&);
void XuatMaTran(int[][100], int, int);
int ktCon(int[][100], int, int, int, int);
void ConDau(int[][100], int, int, int&, int&);
void In(int[][100], int, int, int, int);

int main()
{
    int a[100][100];
    int m, n, vtd, vtc;
    NhapMaTran(a, m, n);
    cout << "Ma tran luc dau: " << endl;
    XuatMaTran(a, m, n);

    ConDau(a, m, n, vtd, vtc);
    cout << "ma tran can tim: " << endl;
    In(a, m, n, vtd, vtc);
    return 0;
}
void NhapMaTran(int a[][100], int& m, int& n) {
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout<< "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void XuatMaTran(int a[][100], int m, int n) 
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int ktCon(int a[][100], int m, int n, int vtd, int vtc)
{
    int flag = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (a[vtd + i][vtc + j] <= 0)
                flag = 0;
    return flag;
}
void ConDau(int a[][100], int m, int n, int& vtd, int& vtc)
 {
    for (vtd = 0; vtd <= m - 3; vtd++)
        for (vtc = 0; vtc <= n - 3; vtc++)
            if (ktCon(a, m, n, vtd, vtc) == 1)
                return;
    vtd = vtc = -1;
}
void In(int a[][100], int m, int n, int vtd, int vtc)
{
    if (vtd != -1 && vtc != -1) 
    {
        for (int i = vtd; i < vtd + 3; i++) 
        {
            for (int j = vtc; j < vtc + 3; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "Khong tim thay ma tran con 3x3 toan duong." << endl;
    }

}

