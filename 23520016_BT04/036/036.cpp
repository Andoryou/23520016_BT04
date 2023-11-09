#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void Thuhoi(float**, int);
float TongDong(float**, int, int,int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    int d;
    cout << "Nhap dong muon tinh tong : ";
    cin >> d;
    cout << "Tong cac gia tri tren dong = " << fixed << setprecision(2) << TongDong(a, m, n, d);
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
