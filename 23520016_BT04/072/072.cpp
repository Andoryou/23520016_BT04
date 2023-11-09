#include <iostream>
#include <iomanip>
void Nhap(float**&, int&, int&);
void Xuat(float**, int, int);
void Thuhoi(float**, int);
int DemPhanBiet(float**, int, int);
using namespace std;

int main()
{
    float** a;
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap : " << endl;
    Xuat(a, m, n);
    cout << "So gia tri phan biet trong ma tran: " << DemPhanBiet(a,m,n);
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

int DemPhanBiet(float** a, int m, int n) 
{
    int dem = 0;
    bool phanbiet;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            phanbiet = true;
            for (int k = 0; k < i; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (a[i][j] == a[k][l])
                    {
                        phanbiet = false;
                        break;
                    }
                }
                if (!phanbiet)
                    break;
            }
            if (phanbiet)
                dem++;
        }
    }
    return dem;
}