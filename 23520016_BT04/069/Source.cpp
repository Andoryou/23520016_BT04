#include <iostream>
using namespace std;

int DemCucTieu(float a[][500], int m, int n);
int ktCucTieu(float a[][500], int m, int n, int i, int j);

int main()
{
    int m, n;
    float a[500][500];

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

    int count = DemCucTieu(a, m, n);
    cout << "So luong phan tu cuc tieu trong ma tran la: " << count << endl;

    return 0;
}

int ktCucTieu(float a[][500], int m, int n, int i, int j)
{
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++)
    {
        int u = i + dx[k];
        int v = j + dy[k];

        if (u >= 0 && u < m && v >= 0 && v < n && a[u][v] <= a[i][j])
            return 0;
    }

    return 1;
}

int DemCucTieu(float a[][500], int m, int n)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ktCucTieu(a, m, n, i, j))
                count++;
        }
    }
    return count;
}
