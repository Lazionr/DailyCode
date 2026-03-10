#define _CRT_SECURE_NO_WARNINGS

//堆的模拟实现

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, heap[N];

//传参传的是编号
void up(int child)
{
	//向上调整算法
	int parent = child / 2;
	//有父结点并且孩子节点大于父节点
	while (parent >= 1 && heap[child] > heap[parent])
	{
		swap(heap[child], heap[parent]);
		child = parent;
		parent = child / 2;
	}
}

void down(int parent)
{
	int child = parent * 2;

	//确保有孩子
	while (child <= n)
	{
		//找出最大孩子
		if (child + 1 <= n && heap[child + 1] > heap[child]) child++;
		//判断是否合法堆
		if (heap[child] <= heap[parent]) return;
		swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2;
	}
}
int main()
{
	int x; 
	//插入堆顶元素
	//1.将元素放到末尾
	//2.进行向上调整算法
	for (int i = 1; i <= 10; i++)
	{
		cin >> x;
		heap[++n] = x;
	    up(n);
	}

	
	//删除堆顶元素
	//1.将末尾元素与堆顶元素进行交换，然后n--
	//2.进行向下调整算法
	for (int i = 1; i <= 10; i++)
	{
		cout << heap[1] << " ";
		swap(heap[1], heap[n--]);
		down(1);
	}
	return 0;
}