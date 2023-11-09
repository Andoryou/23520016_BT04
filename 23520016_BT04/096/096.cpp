#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
float LonNhat(float**, int, int);
float NhoNhat(float**, int, int);
float LonNhi(float**, int, int);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "Gia tri lon thu hai trong ma tran la : " << LonNhi(a, m, n);
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

float LonNhat(float** a, int m, int n)
{
    float lc = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] > lc)
                lc = a[i][j];
        }
    }
    return lc;
}

float NhoNhat(float** a, int m, int n)
{
    float lc = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < lc)
                lc = a[i][j];
        }
    }
    return lc;
}

float LonNhi(float** a, int m, int n)
{
    float lonnhi = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j]<LonNhat(a, m, n) && a[i][j]>lonnhi)
                lonnhi = a[i][j];
        }
    }
    return lonnhi;
}
