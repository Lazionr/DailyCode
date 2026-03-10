#define _CRT_SECURE_NO_WARNINGS	
//堆的存储

//堆的模拟实现
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, heap[N];

//向上调整算法
//时间复杂度:O(log N),最差需要一个树高
void up(int child)
{
	int parent = child / 2;
	//当父节点存在并且大于父节点的权值时，进行交换
	while (parent >= 1 && heap[child] > heap[parent])
	{
		swap(heap[child], heap[parent]);
		//更新到下一个父亲节点
		child = parent;
		parent = child / 2;
	}
}
//向下调整算法
//时间复杂度:O(log N)
void down(int parent)
{
	int child = parent * 2;
	//如果存在孩子
	while (child <= n)
	{
		//找出最大的孩子
		if (child + 1 <= n && heap[child + 1] > heap[child]) child++;
		if (heap[parent] > heap[child]) return;

		swap(heap[parent], heap[child]);
		parent = child;
		child = parent * 2;
	}
}

//void up(int child)
//{
//	int parent = child / 2;
//	while (parent >= 1 && heap[child] > heap[parent])
//	{
//		swap(heap[parent], heap[child]);
//		child = parent;
//		parent = child / 2;
//	}
//}
//
//void down(int parent)
//{
//	int child = parent * 2;
//	while (child <= n)
//	{
//		if (child + 1 <= n && heap[child + 1] > heap[child]) child++;
//		if (heap[parent] > heap[child]) return;
//		swap(heap[child], heap[child + 1]);
//		parent = child;
//		child = parent * 2;
//	}
//}

//插入元素
void push(int x)
{
	heap[++n] = x;
	up(n);
}
//删除元素（一般是堆顶元素）
void pop()
{
	swap(heap[1], heap[n--]);
	down(1); 
}
//查询堆顶元素
int top()
{
	return heap[1];
}
//堆的大小
int size()
{
	return n;
}
int main()
{
	//测试堆
	int a[10] = { 1,41,23,10,11,2,-1,99,14,0 };
	//将这十个数放进堆中
	for (int i = 0; i < 10; i++)
	{
		push(a[i]);
	}
	while (size())
	{
		cout << top() << " ";
		pop();
	}

	return 0;
}


