#include<iostream> 
#include<iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
void Thuhoi(int**, int);
void LietKe(int**, int, int);
bool ktNguyenTo(int);
using namespace std;

int main()
{
    int** b;
    int k;
    int l;
    Nhap(b, k, l);
    cout << "Ma tran ban dau:";
    cout << "\n";
    Xuat(b, k, l);
    cout << "Cac so nguyen to: ";
    LietKe(b, k, l);
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

bool ktNguyenTo(int k)
{
    int dem = 0;
    for (int i = 1; i <= k; i++)
        if (k % i == 0)
            dem++;
    return (dem == 2);
}

void LietKe(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktNguyenTo(a[i][j]))
                cout << setw(8) << a[i][j];
}