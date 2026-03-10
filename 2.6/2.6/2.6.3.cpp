#define _CRT_SECURE_NO_WARNINGS
//priority_queue的使用

#include <iostream>
#include <queue>
using namespace std;

int a[10] = { 1,41,23,10,11,2,-1,99,14,0 };

int main()
{
	priority_queue<int> heap;//默认是一个大根堆
	for (int i = 0; i < 10; i++)
	{
		heap.push(a[i]);
	}
	while (heap.size())
	{
		cout << heap.top() << " ";
		heap.pop();
	}
	return 0;
}