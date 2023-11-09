#include <iostream>
using namespace std;

void Nhap(float a[][500], int &m, int &n);
void Xuat(float a[][500], int m, int n);
void DuongTang(float a[][500], int m, int n);
void HoanVi(float &a, float &b);

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
            cout << "Nhap a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}

void Xuat(float a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void DuongTang(float a[][500], int m, int n)
{
    float b[500];
    int k;
    int i, j;

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                b[k++] = a[i][j];

    for (i = 0; i <= k - 2; i++)
        for (j = i + 1; j <= k - 1; j++)
            if (b[i] > b[j])
                HoanVi(b[i], b[j]);

    k = 0;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] > 0)
                a[i][j] = b[k++];
}

void HoanVi(float &a, float &b)
{
    float temp = a;
    a = b;
    b = temp;
}

int main()
{
    float a[500][500];
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran ban dau:\n";
    Xuat(a, m, n);
    DuongTang(a, m, n);
    cout << "Ma tran sau khi sap xep:\n";
    Xuat(a, m, n);
    return 0;
}
