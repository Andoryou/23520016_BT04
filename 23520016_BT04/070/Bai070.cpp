#include <iostream>
#include <iomanip>
using namespace std;

void Nhap(float[][500], int&, int&);
void Xuat(float[][500], int, int);
bool ktCucDai(float[][500], int, int, int, int);
int DemCucDai(float[][500], int, int);

int main()
{
    float a[500][500];
    int m, n;
    Nhap(a, m, n);
    cout << "Ma tran da nhap la: " << endl;
    Xuat(a, m, n);

    cout << "Ket qua la: " << DemCucDai(a, m, n) << endl;

    system("pause");
}
void Nhap(float a[][500], int& m, int& n)
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
void Xuat(float a[][500], int m, int n)
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
bool ktCucDai(float a[][500], int m, int n, int x, int y)
{
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] >= a[x][y])
        {
            return false;
        }
    }
    return true;
}
int DemCucDai(float a[][500], int m, int n)
{
    int dem = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (ktCucDai(a, m, n, i, j))
                dem++;
    return dem;
}