#define _CRT_SECURE_NO_WARNINGS

//排序
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
void insert_sort()
{
	//1.默认第一个元素为有序
	for (int i = 2; i <= n; i++)
	{
		//避免a[i]直接被右移覆盖掉
		int key = a[i];
		int j = i - 1;
		//找到合适位置
		while (j >= 1 && a[j] > key)
		{
			//进行右移
			a[j + 1] = a[j];
			j--;
		}
		//此时a[j] <= key,j+1即为合法位置
		a[j + 1] = key;
	}
}

void selection_sort()
{
	//1.找到未排序中最小元素
	//2.交换最小元素到已排序的队列中
	for (int i = 1; i < n; i++)
	{
		//i表示待排序区间的首位置
		int pos = i;//找到最小值的位置
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[pos])
			{
				pos = j;
			}
		}
		//此时pos位置的值就是最小值
		swap(a[i], a[pos]);
	}
}
int main()
{
	//5
	//4 2 4 5 1
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//1.插排
	//insert_sort();
	//2.选择排序
	selection_sort(); v 
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}