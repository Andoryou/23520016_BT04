#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(int a[][500], int& m, int& n);
void Xuat(int a[][500], int m, int n);
bool ktHoanThien(int x);
int DemDong(int a[], int n);
void LietKe(int a[][500], int m, int n);

int main()
{
    int a[500][500];
    int m, n;
    Nhap(a, m, n);
    cout << "\nMa tran luc dau la: " << endl;
    Xuat(a, m, n);

    cout << "Dong co nhieu so hoan thien nhat: ";
    LietKe(a, m, n);
    return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
}

void Xuat(int a[][500], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4);
            cout << a[i][j];
        }
        cout << endl;
    }
}

bool ktHoanThien(int x)
{
    int sum = 0;
    for (int i = 1; i <= x / 2; i++) 
        if (x % i == 0) 
            sum += i;
    return sum == x && x != 0;
}

int DemDong(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) 
        if (ktHoanThien(a[i])) 
            count++;
    return count;
}

void LietKe(int a[][500], int m, int n)
{
    int maxCount = -1;
    for (int i = 0; i < m; i++) 
    {
        int count = DemDong(a[i], n);
        if (count > maxCount) 
            maxCount = count;
        
    }

    for (int i = 0; i < m; i++) 
    {
        int count = DemDong(a[i], n);
        if (count == maxCount) 
            cout << i << " ";
    }
}
