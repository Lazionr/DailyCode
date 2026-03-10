#define _CRT_SECURE_NO_WARNINGS

//复现顺序表

#include <iostream>
using namespace std;

const int N = 10010;
int a[N];
int n;//n表示当前有效元素个数

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
//头插
void push_front(int x)
{
	//1.利用memmove
	//memmove(a + 2, a + 1, n * sizeof(int));
	//a[1] = x;
	//n++;
	//2.所有元素从后向前均向后移动一位
	for (int i = n + 1; i >= 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[1] = x;
	n++;
}
//任意位置插入
void insert(int p ,int x)
{
	//先将该位置及其后均向后移动一位
	for (int i = n+1; i > p; i--)
	{
		a[i] = a[i-1];
	}
	a[p] = x;
	n++;
}
//尾删
void pop_back()
{
	n--;
}
//头删
void pop_front()
{
	//所有元素从前向后前进一位
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
//任意位置删除
void erase(int p)
{
	//将p+1及其以后的位置从前向后移动一位
	for (int i = p + 1;i <= n; i++)
	{
		a[i - 1] = a[i];
	}
	n--;
}


int main()
{
	//尾插
	push_back(1);
	push_back(2);
	push_back(3);
	push_back(4);

	//打印
	print();//1 2 3 4 

	//头插
	push_front(0);
	push_front(-1);
	push_front(-2);
	print();

	//任意位置插入
	insert(2,10);
	print();

	////尾删
	//pop_back();
	//print();

	////头删
	//pop_front();
	//print();

	//任意位置删除
	erase(2);
	print();

	return 0;
}