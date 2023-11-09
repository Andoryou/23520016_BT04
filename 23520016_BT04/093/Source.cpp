#include <iostream>
using namespace std;

int DemDong(int[][500], int, int, int);
int DemLonNhat(int[][500], int, int);
void LietKe(int[][500], int, int);
void Nhap(int[][500], int &, int &);

int main()
{
	int a[500][500];
	int m, n;
	Nhap(a, m, n);
	LietKe(a, m, n);
	return 0;
}

void Nhap(int a[][500], int &m, int &n)
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

int DemDong(int a[][500], int m, int n, int dong)
{
	int count = 0;
	for (int j = 0; j < n; j++)
	{
		int count_nt = 1;
		for (int index = 2; index < a[dong][j]; index++)
		{
			if (a[dong][j] % index == 0)
				count_nt++;
		}
		if (count_nt == 1)
			count++;
	}
	return count;
}

int DemLonNhat(int a[][500], int m, int n)
{
	int max_count = 0;
	for (int i = 0; i < m; i++)
	{
		int count = DemDong(a, m, n, i);
		if (count > max_count)
		{
			max_count = count;
		}
	}
	return max_count;
}

void LietKe(int a[][500], int m, int n)
{
	int max_count = DemLonNhat(a, m, n);
	for (int i = 0; i < m; i++)
	{
		if (DemDong(a, m, n, i) == max_count)
			cout << i << endl;
	}
}
