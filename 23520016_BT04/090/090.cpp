#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
float TongDong(float**, int, int, int);
float TongLonNhat(float**, int, int);
void LietKe(float**, int, int);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap :" << endl;
    Xuat(a, m, n);
    LietKe(a, m, n);
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

float TongDong(float** a, int m, int n, int d)
{
    float s = 0;
    for (int j = 0; j < n; j++)
        s = s + a[d][j];
    return s;
}

float TongLonNhat(float** a, int m, int n)
{
    float lc = TongDong(a, m, n, 0);
    for (int i = 0; i < m; i++)
        if (TongDong(a, m, n, i) > lc)
            lc = TongDong(a, m, n, i);
    return lc;
}

void LietKe(float** a, int m, int n)
{
    float ln = TongLonNhat(a, m, n);
    cout << "Cac dong co tong lon nhat bao gom : ";
    for (int i = 0; i < m; i++)
        if (TongDong(a, m, n, i) == ln)
            cout<< setw(10) << setprecision(4) << i;
} 
