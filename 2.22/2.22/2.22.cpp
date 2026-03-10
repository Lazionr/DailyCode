#define _CRT_SECURE_NO_WARNINGS
//排序算法
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, a[N];

void insert_sort()
{
	//插排
	for (int i = 2; i <= n; i++)//默认第一个元素是有序的
	{
		int key = a[i];//避免右移直接被覆盖
		int j = i - 1;
		for (j = i - 1; j >= 1; j--)
		{
			if (a[j] > key)
			{
				//此时才需要j--
				//右移
				a[j + 1] = a[j];
			}
			else
			{
				//此时已经找到合适位置了，直接退出即可
				break;
			}
		}
		//while (j >= 1 && a[j] > key)
		//{
		//	a[j + 1] = a[j];
		//	j--;
		//}
		//a[j] <= key && a[j+1]是空的
		a[j + 1] = key;
	}
}

void selection_sort()
{
	//选择排序:在未排序元素中依次拿出最小元素,然后和未排序数据的首位置元素进行交换
	for (int i = 1; i < n; i++)
	{
		//i用来记录未排序数据的首位置
		int pos = i;
		for (int j = i; j <= n; j++)
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
	//枚举待排序元素
	for (int i = n; i > 1; i--)
	{
		//[1,i]即为待排序区间
		//每一趟将这一趟的最大值放到最后

		//优化：当某一趟冒泡操作没有元素进行交换时，说明元素已经排序完毕，此时直接退出即可
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
	//	//执行n-1躺
	//	for (int j = 1; j <= n - 1 - i; j++)
	//	{
	//		//j的判定条件：限定内层循环的比较范围，避免数组越界，同时跳过已排好序的末尾元素
	//		if (a[j] > a[j + 1])
	//		{
	//			swap(a[j], a[j + 1]);
	//		}
	//	}
	//}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//1.插入排序
	//insert_sort();
	//2.选择排序
	//selection_sort();
	//3.冒泡排序
	bubble_sort();
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}