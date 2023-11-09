#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void DuongGiam(float**, int, int);
void AmTang(float**, int, int);
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
    cout << "Ma tran sau sap xep : " << endl;
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

void DuongGiam(float **a, int m, int n)
{
    float b[500];
    int k;
    int i, j;
    
    k = 0;
    for (i = 0; i < m; i++)
         for (j = 0; j < n; j++)
             if (a[i][j] > 0)
                 b[k++] = a[i][j];
    
     for (i = 0; i <= k - 2; i++)
         for (j = i + 1; j <= k - 1; j++)
             HoanVi(b[i], b[j]);
    
    k = 0;
    for (i = 0; i < m; i++)
         for (j = 0; j < n; j++)
             if (a[i][j] > 0)
                a[i][j] = b[k++];
}

void AmTang(float** a, int m, int n)
{
    float b[500];
    int k;
    int i, j;
    
    k = 0;
    for (i = 0; i < m; i++)
       for (j = 0; j < n; j++)
           if (a[i][j] < 0)
              b[k++] = a[i][j];
     
    for (i = 0; i <= k - 2; i++)
       for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j])
                 HoanVi(b[i], b[j]);
     
    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] < 0)
               a[i][j] = b[k++];
}

void SapXep(float** a, int m, int n)
{
     AmTang(a, m, n);
     DuongGiam(a, m, n);
}
