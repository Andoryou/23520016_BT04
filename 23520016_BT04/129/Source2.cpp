#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int &, int &);
void SapTangKhongSuDungMangPhu(float[][500], int, int);
void Xuat(float[][500], int, int);

int main()
{
    float a[500][500];
    int m, n;
    Nhap(a, m, n);
    SapTangKhongSuDungMangPhu(a, m, n);
    Xuat(a, m, n);
    return 0;
}

void Nhap(float a[][500], int &m, int &n)
{
    cout << "Nhap so hang m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void SapTangKhongSuDungMangPhu(float a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                for (int l = (k == i) ? 0 : j + 1; l < n; l++)
                {
                    if (a[i][j] < a[k][l])
                    {
                        float temp = a[i][j];
                        a[i][j] = a[k][l];
                        a[k][l] = temp;
                    }
                }
            }
        }
    }
}

void Xuat(float a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << endl;
    }
}