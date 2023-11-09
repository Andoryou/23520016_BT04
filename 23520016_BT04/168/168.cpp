#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
int ktCon(float**, int, int, int, int);
int DemCon(float**, int, int);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "Soluong ma tra con co kich thuoc 3x3 toan duong la : " << DemCon(a, m, n);
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

int ktCon(float **a, int m, int n,int vtd, int vtc)
{
   int flag = 1;
   for (int i = 0; i < 3; i++)
         for (int j = 0; j < 3; j++)
             if (a[vtd + i][vtc + j] <= 0)
                 flag = 0;
    return flag;
}

int DemCon(float**a, int m, int n)
{
    int dem = 0;
    for (int vtd = 0; vtd <= m - 3; vtd++)
        for (int vtc = 0; vtc <= n - 3; vtc++)
           if (ktCon(a, m, n, vtd, vtc) == 1)
        dem++;
    return dem;
}