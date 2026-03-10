#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int N = 10010;
int a[N], n;

//打印顺序表
void print()
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//尾插
void push_back(int x)
{
	a[++n] = x;
}

//头插
void push_front(int x)
{
	for (int i = n; i >= 1; i--)
	{
		a[i + 1] = a[i];
	}
	a[1] = x;
	n++;
}

//任意位置插入
void insert(int p,int x)
{
	//先将p - n之间元素均向后移一位
	for (int i = n; i >= p; i--)
	{
		a[i + 1] = a[i];
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
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

//任意位置删除
void erase(int p)
{
	//将p+1 - n位置元素统一向左移动一位
	for (int i = p; i <= n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

//按值查找
int find(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == x)
			return i;
	}
	//没找到就退出
	return 0;
}

//按位（下标）查找
int at(int p)
{
	return a[p];
}

//按位修改
void change(int p, int x)
{
	a[p] = x;
}

//清空顺序表
void clear()
{
	n = 0;
}

int main()
{
	//测试尾插
	push_back(1);
	print();
	push_back(2);
	print();
	push_back(3);
	print();
	push_back(4);
	print();

	//测试头插
	push_front(0);
	print();

	//测试任意位置插入
	insert(2, 10);
	print();

	////尾删
	//cout << "尾删" << endl;
	//pop_back();
	//print();
	//pop_back();
	//print();

	////头删
	//cout << "头删" << endl;
	//pop_front();
	//print();

	////任意位置删除
	//cout << "任意位置删除" << endl;
	//erase(2);
	//print();

	//任意位置查找
	for (int i = 1; i <= 10; i++)
	{
		cout << "查找" << i << "：";
		cout << find(i) << endl;
	}
    
	//清空顺序表
	clear();
	return 0;
}