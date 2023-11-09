#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void DuongBienTang(float**, int, int);
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
    DuongBienTang(a, m, n);
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

void DuongBienTang(float **a,int m, int n)
{
    float b[500];
    int k;
    int i, j;
    
    k = 0;
    for (j = 0; j <= n - 2; j++)
        b[k++] = a[0][j];
    for (i = 0; i <= m - 2; i++)
        b[k++] = a[i][n - 1];
    for (j = n - 1; j >= 1; j--)
        b[k++] = a[m - 1][j];
    for (i = m - 1; i >= 1; i--)
        b[k++] = a[i][0];
   
    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j] && b[i] > 0 && b[j] > 0)
                HoanVi(b[i], b[j]);
   
    k = 0;
    for (j = 0; j <= n - 2; j++)
         a[0][j] = b[k++];
    for (i = 0; i <= m - 2; i++)
         a[i][n - 1] = b[k++];
    for (j = n - 1; j >= 1; j--)
         a[m - 1][j] = b[k++];
    for (i = m - 1; i >= 1; i--)
         a[i][0] = b[k++];
    Xuat(a, m, n);
}
