#define _CRT_SECURE_NO_WARNINGS

//排序
#include <iostream>
#include <ctime>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int tmp[N];//归并排序辅助数组

void insert_sort()
{
	//插入排序
	for (int i = 2; i <= n; i++)
	{
		int key = a[i];//避免直接被覆盖掉
		int j = i;
		while (j >= 1 && a[j - 1] > key)
		{
			//右移
			a[j] = a[j - 1];
			j--;
		}
		a[j] = key;
	}
}

void selection_sort()
{
	//在待排序区间中选择最小的元素放入到已排序的区间
	for (int i = 1; i < n; i++)
	{
		//i记录待排序区间的首位置
		int pos = i;//pos标记最小元素的位置
		int j = 0;
		for (int j = i + 1; j <= n; j++)
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
	for (int i = n; i > 1; i--)
	{
		//[1,i]即为待排序元素区间
		for (int j = 1; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void down(int parent,int len)
{
	int child = parent * 2;
	while (child <= len)
	{
		//1.找到最大孩子
		if (child + 1 <= len && a[child + 1] > a[child]) child++;
		//2.合法堆直接返回
		if (a[child] <= a[parent]) return;
		//非合法堆，需要交换
		swap(a[child], a[parent]);
		parent = child;
		child = parent * 2;
	}
}
void heap_sort()
{
	//1.在原数组基础上直接建堆
	//从最后一个非叶节点开始
	for (int i = n / 2; i >= 1; i--)
	{
		down(i,n);
	}
	//2.排序
	//堆顶元素与末尾元素进行交换，接着执行down
	for (int i = n; i > 1; i--)
	{
		swap(a[1], a[i]);
		//交换后只需对i-1个元素进行down
		down(1, i - 1);
	}
}
int get_random(int left,int right)
{
	return a[rand() % (right - left + 1) + left];
}
void quick_sort(int left,int right)
{
	if (left >= right) return;

	//1.获取基准值
	int p = get_random(left,right);
	//2.荷兰国旗
	int l = left - 1, i = left, r = right + 1;
	while (i < r)
	{
		if (a[i] < p) swap(a[i++], a[++l]);
		else if (a[i] == p) i++;
		else swap(a[i], a[--r]);
	}
	//3.递归处理左右区间
	quick_sort(left,l);
	quick_sort(r, right);
}
void merge_sort(int left,int right)
{
	if (left >= right) return;
	//1.划分左右区间
	int mid = (left + right) >> 1;
	//[left,mid] [mid + 1,right]
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	//2.合并区间
	int cur1 = left, i = left, cur2 = mid + 1;
	while (cur1 <= mid && cur2 <= right)
	{
		//先遍历完一个数组
		if (a[cur1] <= a[cur2]) tmp[i++] = a[cur1++];
		else tmp[i++] = a[cur2++];
	}
	while (cur1 <= mid) tmp[i++] = a[cur1++];
	while (cur2 <= right) tmp[i++] = a[cur2++];
	//将tmp数组转移到a数组
	for (int j = left; j <= right; j++) a[j] = tmp[j];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//insert_sort();
	//selection_sort();
	//bubble_sort();
	//heap_sort();
	//srand(time(0));
	//quick_sort(1,n);
	//merge_sort(1,n);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;

	return 0;
}