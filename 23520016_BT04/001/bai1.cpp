#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

void TaoMaTran(int a[][500], int &m, int &n);
void Xuat(int a[][500], int m, int n);
void Xuat(string filename, int a[][500], int m, int n);

void TaoMaTran(int a[][500], int &m, int &n)
{
	srand(time(0));
	cout << "Nhap so hang m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}

void Xuat(int a[][500], int m, int n)
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

void Xuat(string filename, int a[][500], int m, int n)
{
	ofstream outfile(filename);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			outfile << a[i][j] << "\t";
		}
		outfile << endl;
	}
	outfile.close();
}

int main()
{
	int a[500][500];
	int m, n;
	TaoMaTran(a, m, n);
	cout << "Ma tran vua tao:\n";
	Xuat(a, m, n);
	Xuat("data01.inp", a, m, n);
	cout << "Ma tran da duoc xuat ra tap tin data01.inp.\n";
	return 0;
}