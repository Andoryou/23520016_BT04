#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
float NhoNhatDong(float**, int, int, int);
void ThemCot(float**, int, int&);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "Ma tran sau khi them : " << endl;
    ThemCot(a, m, n);
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

float NhoNhatDong(float** a, int m, int n, int d)
{
    float lc = a[d][0];
    for (int j = 0; j < n; j++)
        if (a[d][j] < lc)
            lc = a[d][j];
    return lc;
}

void ThemCot(float** a, int m, int& n)
{
    float** b = new float* [m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new float[n + 1];
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
        b[i][n] = NhoNhatDong(a, m, n, i);
    }

    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    a = b;
    n++;
    Xuat(a, m, n);
}

