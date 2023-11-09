#include <iostream>
#include <iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
void Thuhoi(int**, int);
bool KtChinhPhuong(int);
int TongBien(int**, int, int);
using namespace std;

int main()
{
    int** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "Tong gia tri chinh phuong nam tren bien = " << TongBien(a, m, n);
    Thuhoi(a, m);
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

bool KtChinhPhuong(int m)
{
    for (int i = 0; (i * i) <= m; i++)
            if (i * i == m )
               return true;
    return false;
}

int TongBien(int** a , int m, int n)
{
    int s = 0;
    for (int j = 0; j <= n - 2; j++)
        if(KtChinhPhuong(a[0][j]))
             s = s + a[0][j];
    for (int i = 0; i <= m - 2; i++)
        if (KtChinhPhuong(a[i][n-1]))
             s = s + a[i][n - 1];
    for (int j = n - 1; j >= 1; j--)
        if (KtChinhPhuong(a[m-1][j]))
             s = s + a[m - 1][j];
    for (int i = m - 1; i >= 1; i--)
        if (KtChinhPhuong(a[i][0]))
             s = s + a[i][0];
    return s;
 }

