#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
int ktCot(float**, int, int, int);
void XoaCot(float**, int, int&, int);
void XoaCot(float**, int, int&);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "Ma tran sau khi xoa : " << endl;
    XoaCot(a, m, n);
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

int ktCot(float** a, int m, int n, int c)
{
    int flag = 0;
    bool ktDuong = false;
    bool ktAm = false;
    for (int i = 0; i < m; i++)
    {
        if (a[i][c] > 0)
            ktDuong = true;
        else
        {
            if (a[i][c] < 0)
                ktAm = true;
        }
    }
    if (ktDuong && ktAm)
        flag = 1;
    return flag;
}

void XoaCot(float** a, int m, int& n, int c)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = c; j < n - 1; j++)
            a[i][j] = a[i][j + 1];
    }
    n--;
}

void XoaCot(float** a, int m, int& n)
{
    for (int j = 0; j < n; j++)
    {
        if (ktCot(a, m, n, j) == 1)
        {
            XoaCot(a, m, n, j);
            j--;
        }
    }
    Xuat(a, m, n);
}