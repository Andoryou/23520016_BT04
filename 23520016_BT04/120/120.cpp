#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void HoanVi(float&, float&);
void HoanViDong(float**, int, int, int,int);
void Thuhoi(float**, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    int d1, d2;
    cout << "Nhap hai dong muon hoan vi : " << endl;
    cout << "d1 : "; 
    cin >> d1 ;
    cout << "d2 : ";
    cin >> d2;
    HoanViDong(a, m, n, d1, d2);
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

void HoanViDong(float** a, int m, int n, int d1, int d2)
{
    for (int j = 0; j < n; j++)
        HoanVi(a[d1][j], a[d2][j]);
    cout << "Ma tran sau hoan vi dong " << d1 << " va " << d2 << " :" << endl;
    Xuat(a, m, n);
}