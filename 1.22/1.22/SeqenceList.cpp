#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], n;

//¥Ú”°À≥–Ú±Ì
void Print()
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//Œ≤≤Â
void push_back(int x)
{
	a[++n] = x;
}
int main()
{
	//≤‚ ‘Œ≤≤Â
	push_back(1);
	Print();
	push_back(2);
	Print();
	push_back(3);
	Print();
	push_back(4);
	Print();

	return 0;
}