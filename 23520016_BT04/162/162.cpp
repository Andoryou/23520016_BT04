#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void Xoay90(float**, int&, int&);
void Xoay180(float**, int&, int&);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "Ma tran sau khi xoay 180 do : " << endl;
    Xoay180(a, m, n);
    Xuat(a, m, n);
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

void Xoay90(float **a, int& m, int& n)
{
    float b[500][500];
    int k, l;
    k = n;
    l = m;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < l; j++)
             b[i][j] = a[j][n - 1 - i];
    
    m = k;
    n = l;
    for (int i = 0; i < m; i++)
         for (int j = 0; j < n; j++)
             a[i][j] = b[i][j];

 }


void Xoay180(float **a, int& m, int& n)
{
   Xoay90(a, m, n);
   Xoay90(a, m, n);   
}