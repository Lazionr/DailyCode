#define _CRT_SECURE_NO_WARNINGS

//堆的模拟实现
#include <iostream>
#include <queue>

using namespace std;

int a[10] = { 1, 41, 23, 10, 11, 2, -1, 99, 14, 0 };

struct node
{
	int a, b, c;

	//重载<运算符
	////以b为基准，创建大根堆
	//bool operator < (const node& x) const
	//{
	//	//大根堆用小于
	//	return b < x.b;
	//}
	//以b为基准，创建小根堆
	bool operator < (const node& x) const
	{
		//大根堆用小于
		return b > x.b;
	}
};
//结构体类型
void test2()
{
	priority_queue<node> heap;

	for (int i = 1; i <= 5; i++)
	{
		heap.push({ i,i + 1,i + 2 });
	}

	while (heap.size())
	{
		auto e = heap.top();
		cout << e.a << " " << e.b << " " << e.c << endl;
		heap.pop();
	}
}
//内置类型
void test1()
{
	//大根堆
	priority_queue<int> heap1;//默认就是大根堆

	//priority_queue<数据类型，存储结构（一般为vector），比较方式>
	//less 和 greater 
	priority_queue<int, vector<int>, less<int>> heap2;   //大根堆
	priority_queue<int, vector<int>, greater<int>> heap3;//小根堆
	
	for (int i = 1; i < 10; i++)
	{
		heap2.push(a[i]);
		heap3.push(a[i]);
	}
	
	cout << "大根堆：";
	while (heap2.size())
	{
		cout << heap2.top() << " ";
		heap2.pop();
	}
	cout << endl;
	cout << "小根堆：";
	while (heap3.size())
	{
		cout << heap3.top() << " ";
		heap3.pop();
	}
	cout << endl;
}
int main()
{
	//priority_queue<int> heap;
	////默认大根堆
	//for (int i = 1; i < 10; i++)
	//{
	//	heap.push(a[i]);
	//}
	//while (heap.size())
	//{
	//	cout << heap.top() << " ";
	//	heap.pop();
	//}
	//cout << endl;
	//test1();
	test2();
	return 0;
}