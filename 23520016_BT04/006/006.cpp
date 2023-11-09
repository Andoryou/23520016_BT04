#include <iostream>
#include <iomanip>
void Nhap(double**&, int&, int&);
void Xuat(double**, int, int);
void Thuhoi(double**, int);
using namespace std;

int main()
{
    double** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap :" << endl;
    Xuat(a, m, n);
    Thuhoi(a, m);
    return 0;
}

void Nhap(double**& a, int& m, int& n)
{
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    a = new double* [m];
    for (int i = 0; i < m; i++) 
    {
        a[i] = new double[n];
    }

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << "Nhap a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void Xuat(double** a, int m, int n) 
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << setw(10) << setprecision(3) << a[i][j];
        }
        cout << endl;
    }
}

void Thuhoi(double** a, int m) 
{
    for (int i = 0; i < m; i++) 
    {
        delete[] a[i];
    }
    delete[] a;
}