#include <iostream>
#include <iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
bool KtNguyenTo(int);
int NguyenToDau(int**, int, int);
int NguyenToLonNhat(int**, int, int);
void Thuhoi(int**, int);
using namespace std;

int main() 
{
    int m, n;
    int** a;
    Nhap(a, m, n);
    cout << "Ma tran vua nhap la: " << endl;
    Xuat(a, m, n);
    int max = NguyenToLonNhat(a, m, n);
    if (max == 0) 
    {
        cout << "Ma tran khong co so nguyen to." ;
    }
    else 
    {
        cout << "So nguyen to lon nhat trong ma tran la: " << max ;
    }
    Thuhoi(a,m);
    return 0;
}

void Nhap(int**& a, int& m, int& n)
{
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;

    a = new int* [m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
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

void Xuat(int** a, int m, int n)
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

void Thuhoi(int** a, int m)
{
    for (int i = 0; i < m; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

bool KtNguyenTo(int k)
{
    if (k < 2) 
        return false; 
    for (int i = 2; i*i <= k; i++) 
        if (k % i == 0)
           return false;
    return true;
}


int NguyenToDau(int** a, int m, int n)
{
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (KtNguyenTo(a[i][j]))
            {
                return a[i][j];
            }
        }
    }
    return 0; 
}

int NguyenToLonNhat(int** a, int m, int n)
{
    int lc =NguyenToDau(a,m,n);
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (KtNguyenTo(a[i][j]) && a[i][j] >lc) 
            {
                lc = a[i][j];
            }
        }
    }
    return lc;
}

