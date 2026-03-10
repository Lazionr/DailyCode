#define _CRT_SECURE_NO_WARNINGS
//封装静态顺序表
#include <iostream>
using namespace std;
const int N = 50;
class Sqlist
{
private:
	int a[N];
	int n;

public:
	//构造函数
	Sqlist()
	{
		n = 0;
	}
	//尾插
	void push_back(int x)
	{
		a[++n] = x;
	}
	//打印
	void print()
	{
		for (int i = 1; i <= n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	Sqlist s1,s2;
	for (int i = 1; i <= 5; i++)
	{
		s1.push_back(i);
		s2.push_back(i * 2);
	}
	s1.print();
	s2.print();
	return 0;
}