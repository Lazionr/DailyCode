#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int n, heap[N];
int cnt;

void up(int child)
{
	int parent = child / 2;

	while (parent >= 1 && heap[child] < heap[parent])
	{
		swap(heap[child], heap[parent]);
		child = parent;
		parent = child / 2;
	}
}

void down(int parent)
{
	int child = parent * 2;
	//如果还有孩子 
	while (child <= cnt)
	{
		//找出最小的孩子 
		if (child + 1 <= cnt && heap[child + 1] < heap[child]) child++;
		//如果最小的孩子比我大，说明是合法堆 
		if (heap[child] > heap[parent]) return;
		swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2;
	}
}
int main()
{
	int x, op;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x;
			//小根堆向上调整算法
			//先将x放到最后
			heap[++cnt] = x;
			//执行一次向上调整算法 
			up(cnt);
		}
		else if (op == 2)
		{
			//输出堆顶元素
			cout << heap[1] << endl;
		}
		else
		{
			//删除堆顶元素 
			//先交换堆顶元素，然后删除末尾元素 
			swap(heap[1], heap[cnt--]);
			//执行一次向下调整算法 
			down(1);
		}
	}
	return 0;
}