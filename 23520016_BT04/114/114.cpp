#include <iostream>
#include <iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
bool KtChinhPhuong(int );
int ktCot(int**, int, int, int);
void LietKe(int**, int, int);
void Thuhoi(int**, int);
using namespace std;

int main()
{
    int m, n;
    int** a;
    Nhap(a, m, n);
    cout << "Ma tran vua nhap la: " << endl;
    Xuat(a, m, n);
    LietKe(a, m, n);
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

bool KtChinhPhuong(int k)
{
    bool flag = false;
    for (int i = 0; i <= k; i++)
        if (i * i == k)
            flag = true;
    return flag;
}

int ktCot(int** a, int m, int n, int c)
{
    int flag = 0;
    for (int i = 0; i < m;i++)
    {
        if (KtChinhPhuong(a[i][c]))
            flag = 1;
    }
    return flag;
}

void LietKe(int** a, int m, int n)
{
    cout << "Cac cot co so chinh phuong gom : ";
    for (int j = 0; j < n; j++)
        if (ktCot(a, m, n, j) == 1)
            cout << setw(10) << setprecision(4) << j;
}