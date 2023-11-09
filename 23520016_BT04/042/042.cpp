#include <iostream>
#include <iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
void Thuhoi(int**, int);
bool KtLuyThuaCua2(int);
int TongCot2m(int**, int, int, int);
using namespace std;

int main()
{
    int** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    int c;
    cout << "Nhap cot muon tinh : ";
    cin >> c;
    cout << "Tong cac gia tri co dang 2^m tren cot " << c << ": " << TongCot2m(a, m, n, c);
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

bool KtLuyThuaCua2(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n /= 2;
    }

    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int TongCot2m(int** a, int m, int n, int c)
{
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        if (KtLuyThuaCua2(a[i][c]))
        {
            s = s + a[i][c];
        }
    }
    return s;
}
