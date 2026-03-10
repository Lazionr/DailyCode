#define _CRT_SECURE_NO_WARNINGS

////链地址法实现哈希表
//#include <iostream>
//
//using namespace std;
//
//const int N = 23;
//int h[N];//哈希表
//int e[N], ne[N], id;
//
////哈希函数
//int f(int x)
//{
//	return (x % N + N) % N;
//}
////查找元素
//bool find(int x)
//{
//	int idx = f(x);
//	for (int i = h[idx]; i; i = ne[i])
//	{
//		if (e[i] == x) return true;
// 	}
//	return false;
//}
////插入元素
//void insert(int x)
//{
//	//如果已存在，直接返回
//	if (find(x)) return;
//	//得到存储位置
//	int idx = f(x);
//	//链表存储
//	e[++id] = x;
//	//将x头插到哈希表中
//	ne[id] = h[idx];//哈希表中存的是第一个元素
//	h[idx] = id;
//}
//
//int main()
//{
//	int n; cin >> n;
//	while (n--)
//	{
//		int op, x;
//		cin >> op >> x;
//		if (op == 1)
//		{
//			//插入
//			insert(x);
//		}
//		else
//		{
//			//查询
//			if (find(x)) cout << "yes" << endl;
//			else cout << "no" << endl;
//		}
//	}
//	return 0;
//}


//STL中的哈希表

//1.unordered_set
#include <iostream>
#include <unordered_set>
using namespace std;

int a[] = { 10,30,70,50,80,90,20,40,60 };

int main()
{
	//unordered_set<int> mp1;
	//unordered_set<string> mp2;

	unordered_set<int> mp;

	//插入
	for (auto e : a)
	{
		mp.insert(e);
	}
	//遍历
	for (auto v : a)
	{
		cout << v << " ";
	}
	cout << endl;

	if (mp.count(1)) cout << "1" << endl;
	if (mp.count(20)) cout << "20" << endl;

	mp.erase(20);
	if (mp.count(20)) cout << "20" << endl;

	return 0;
}