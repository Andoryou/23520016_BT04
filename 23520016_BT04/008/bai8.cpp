#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	if (freopen(" floatdata06", "r", stdin) != NULL)
	{
		while (!cin.eof());
		{
			string s;
			cin >> s;
			cout << s;
		}
	}
	else
		cout << "Khong co";
	return 0;
}