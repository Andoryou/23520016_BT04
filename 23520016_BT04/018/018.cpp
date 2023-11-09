#include<iostream> 
#include<iomanip>
void Nhap(int**&, int&, int&);
void Xuat(int**, int, int);
void Thuhoi(int**, int);
void LietKeSoChan(int**&,int,int,int);
using namespace std;

int main()
{
    int** a;
    int m, n,c;
    Nhap(a, m, n);
    cout << "Ma tran da nhap :" << endl;
    Xuat(a, m, n);
    cout << "Nhap cot muon liet ke cac so chan : ";
    cin >> c;
    cout << "Cac gia tri chan tren cot :" << endl;
    LietKeSoChan(a, m, n, c);
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

void LietKeSoChan(int**& a, int m, int n, int c)
{
    for (int i = 0; i < m; i++)
    {
            if (a[i][c] % 2 == 0)
                cout << setw(10) << a[i][c];
    }
}
