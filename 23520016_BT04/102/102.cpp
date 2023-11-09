#include <iostream>
#include <iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
int TonTaiLe(int**, int, int);
void Thuhoi(int**, int);
using namespace std;

int main()
{
    int m, n;
    int** a;
    Nhap(a, m, n);
    cout << "Ma tran vua nhap la: " << endl;
    Xuat(a, m, n);
    int flag = TonTaiLe(a, m, n);
    if (flag == 1)
        cout << "Ma tran ton tai chu so le.";
    else
        cout << "Ma tran khong ton tai chu so le";
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

int TonTaiLe(int** a, int m, int n)
{
    int flag = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2 != 0)
                flag = 1;
    return flag;
}
