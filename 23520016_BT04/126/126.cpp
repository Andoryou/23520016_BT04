#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void SapDongTang(float**, int, int, int);
void SapDongGiam(float**, int, int, int);
void SapXep(float**, int, int);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    SapXep(a, m, n);
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

void HoanVi(float& a, float& b)
{
    float temp = a;
    a = b;
    b = temp;
}


void SapDongTang(float** a, int m, int n, int d) 
{
    for (int i = 0; i <= n - 2; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (a[d][i] > a[d][j])
               HoanVi(a[d][i], a[d][j]);
}

void SapDongGiam(float** a, int m, int n, int d)
{
    for (int i = 0; i <= n - 2; i++)
         for (int j = i + 1; j <= n - 1; j++)
            if (a[d][i] < a[d][j])
                 HoanVi(a[d][i], a[d][j]);
}

void SapXep(float **a, int m, int n)
{
    for (int i = 0; i <= m - 1; i++)
    {
        if (i % 2 == 0)
            SapDongTang(a, m, n, i);
        else
            SapDongGiam(a, m, n, i);
    }
    cout << "Ma tran sau khi sap xep: " << endl;
    Xuat(a, m, n);
}
