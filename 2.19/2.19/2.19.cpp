#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>

////eg:记录字符串acbccacb各个字符串出现次数
//
//
//
//using namespace std;
//
//void solve(string s)
//{
//	int cnt[26] = { 0 };
//	for (auto ch : s)
//	{
//		cnt[ch - 'a']++;
//	}
//	for (int i = 0; i < 3; i++) cout << cnt[i] << endl;
//}

//int main()
//{
//	string s = "acbccacb";
//	solve(s);
//	return 0;
//}

//模拟实现哈希表

//1.线性探测法

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 23, INF = 0x3f3f3f3f;
//
//int h[N];//哈希表
//
//void init()
//{
//	memset(h, 0x3f, sizeof(h));
//	//memset():第一个参数为起始地址，第二个为大小，第三个为数量
//
//}
//
////哈希函数 - 计算出x的存储位置
//int f(int x)
//{
//	int id = (x % N + N) % N;
//
//	//处理哈希冲突 - 线性探测法
//	//循环条件：h[id]对应的值已经被存储过 && 存储的不是两个相同的值
//	while (h[id] != INF && h[id] != x)
//	{
//		id++;
//		if (id == N) id = 0;
//		//如果走到尾部，就从头开始
//	}
//
//	return id;
//}
//
////添加元素
//void insert(int x)
//{
//	int id = f(x);
//	h[id] = x;
//}
//
////查找元素
//bool find(int x)
//{
//	int id = f(x);
//	return h[id] == x;
//}
//
//int main()
//{
//	init();
//
//	int n; cin >> n;
//	while (n--)
//	{
//		int op,x; cin >> op >> x;
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

//2.链地址法
//等同于链式前向星

#include <iostream>

using namespace std;

const int N = 23;

int h[N];//哈希表
int e[N], ne[N], id;


//哈希函数
int f(int x)
{
	//除留余数法
	return (x % N + N) % N;
}

//插入元素 - 处理哈希冲突
void insert(int x)
{
	//计算出哈希值
	int idx = f(x);
	//将x头插到哈希表中
	e[++id] = x;
	ne[id] = h[idx];
	h[idx] = id;
}

//查找元素
bool find(int x)
{
	int idx = f(x);
	for (int i = h[idx]; i; i = ne[i])
	{
		if (e[i] == x) return true;
	}
	return false;
}
int main()
{
	int n; cin >> n;
	while (n--)
	{
		int op, x;
		cin >> op >> x;
		if (op == 1)
		{
			insert(x);
		}
		else
		{
			if (find(x)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}