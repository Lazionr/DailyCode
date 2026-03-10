#define _CRT_SECURE_NO_WARNINGS

//排序
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int tmp[N];//辅助归并排序时，合并两个有效数组

void insert_sort()
{
	//插入排序
	//默认第一个元素有序，从第二个元素开始遍历
	for (int i = 2; i <= n; i++)
	{
		int key = a[i];//避免a[i]直接被覆盖掉
		int j = i;
		while (j > 1 && a[j-1] > key)
		{
			//右移
			a[j] = a[j - 1];
			j--;
		}
		//此时j就是合适位置
		a[j] = key;
	}
}
void selection_sort()
{
	//选择排序
	//在待排序的元素中找到最小元素，与未排序元素区间的首位置进行交换
	for (int i = 1; i < n; i++)
	{
		//执行n - 1次即可,最后一个元素即为末尾元素
		//i用来记录待排序区间的首位置
		int pos = i;
		int j = 0;
		for (j = i + 1; j <= n; j++)
		{
			if (a[j] < a[pos])
			{
				pos = j;
			}
		}
		swap(a[pos], a[i]);
	}
}
void bubble_sort()
{
	//冒泡排序
	for (int i = n; i > 1; i--)
	{
		//[1,i]即为待排序元素区间
		bool flag = false;
		for (int j = 1; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (flag == false) return;
	}

	//for (int i = 0; i < n - 1; i++)
	//{
	//	//执行n-1趟
	//	for (int j = 0; j <= n - 1 - i; j++)
	//	{
	//		if (a[j] > a[j + 1])
	//		{
	//			swap(a[j], a[j + 1]);
	//		}
	//	}
	//}
}
void down(int parent,int len)
{
	//向下调整算法
	int child = parent * 2;
	//child <= len即为存在孩子
	while (child <= len)
	{
		//找到最大的孩子
		if (child + 1 <= len && a[child + 1] > a[child]) child++;
		//合法堆，直接返回
		if (a[parent] >= a[child]) return;

		swap(a[parent], a[child]);
		parent = child;
		child = parent * 2;
	}

}

void heap_sort()
{
	//1.先建堆（升序大根堆，降序小根堆）
	//从最后一个非叶节点开始执行向下调整算法
	for (int i = n / 2; i >= 1; i--)
	{
		//每个元素均需要执行
		down(i,n);
	}
	//2.排序
	for (int i = n; i > 1; i--)
	{
		//执行n-1次即可
		swap(a[1], a[i]);
		//交换完执行向下调整算法
		//此时size已经减一了，堆的长度是i - 1 
		down(1, i - 1);
	}
}

int get_random(int left, int right)
{
	return a[rand() % (right - left + 1) + left];
}
void quick_sort(int left ,int right)
{
	//快排
	if (left >= right) return;
	//1.得到基准值
	int p = get_random(left, right);
	//2.数据分三块,荷兰国旗问题
	int l = left - 1,i = left, r = right + 1;
	while(i < r)
	{
		if (a[i] < p) swap(a[++l], a[i++]);//左边是已经判断过的元素，直接i++即可
		else if (a[i] == p) i++;
		else swap(a[--r], a[i]);
	}
	//此时分成三个区间[left,l] [l+1,r-1] [r,right]
	quick_sort(left, l);
	quick_sort(r, right);
}


void merge_sort(int left,int right)
{
	//归并排序
	if (left >= right) return;
	
	//1.先一分为二
	int mid = (left + right) >> 1;
	// [left,mid] [mid + 1,right]
	//2.先让左右区间有序
	merge_sort(left, mid);
	merge_sort(mid+1,right);
	//3.在进行合并
	int cur1 = left, cur2 = mid + 1, i = left;
	while (cur1 <= mid && cur2 <= right)
	{
		//先让一个数组遍历完
		if (a[cur1] < a[cur2]) tmp[i++] = a[cur1++];
		else tmp[i++] = a[cur2++];
	}
	//至少有一个数组遍历完
	while (cur1 <= mid) tmp[i++] = a[cur1++];
	while (cur2 <= right) tmp[i++] = a[cur2++];

	//将tmp数组复制到a数组中
	for (int j = left; j <= right; j++) a[j] = tmp[j];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//1.插排
	//insert_sort();
	//2.选择排序
	//selection_sort();
	//3.冒泡排序
	//bubble_sort();
	//4.堆排序
	//heap_sort();
	//5.快排
	//srand(time(0));
	//quick_sort(1,n);
	//6.归并排序
	merge_sort(1,n);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;

	return 0;
}