#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void Thuhoi(float**, int);
int DemDuongBien(float**, int, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "So chu so duong o bien ma tran la : " << DemDuongBien(a, m, n);
    Thuhoi(a, m);
    return 0;
}

void Nhap(float**& a, int& m, int& n)
{
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    a = new float* [m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new float[n];
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

void Xuat(float** a, int m, int n)
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

void Thuhoi(float** a, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

int DemDuongBien(float** a, int m, int n)
{
    int dem = 0;
    for (int j = 0; j < n - 2; j++)
        if (a[0][j] > 0)
            dem++;
    for (int i = 0; i <= m - 2; i++)
        if (a[i][n - 1] > 0)
            dem++;
    for (int j = n - 1; j >= 1; j--)
        if (a[m - 1][j] > 0)
            dem++;
    for (int i = m - 1; i >= 1; i--)
        if (a[i][0] > 0)
            dem++;
    return dem;
}
