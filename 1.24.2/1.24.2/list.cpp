#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 100010;

////创建单链表
//int e[N], ne[N], h, id;
//int mp[N];//mp[i]存储的就是i的位置
//
////头插
//void push_front(int x)
//{
//	//1.修改数据域，为新节点分配空间，同时存入新元素
//	//id++;
//	e[++id] = x;
//	mp[x] = id;//记录x的存储位置
//	//2.修改指针域
//	//a.将当前节点指向哨兵位的下一个位置
//	ne[id] = ne[h];
//	//b.将哨兵位指向当前位置
//	ne[h] = id;
//}
////打印
//void print()
//{
//	for (int i = ne[h]; i;i = ne[i]) 
//	{
//		cout << e[i] << " ";
//	}
//	cout << endl;
//}
////按值查找
//int find(int x)
//{
//	////法一：遍历链表
//	//for (int i = ne[h]; i; i = ne[i])
//	//{
//	//	if (e[i] == x)
//	//		return i;
//	//}
//	//return 0;
//
//	//法二:用mp数组优化
//	return mp[x];
//}
////任意位置之后插入元素
//void insert(int p, int x)
//{
//	e[++id] = x;
//	ne[id] = ne[p];
//	ne[p] = id;
//}
////删除任意位置之后的元素
//void erase(int p)
//{
//	if (ne[p])
//	{
//		mp[e[ne[p]]] = 0;
//		//将p指向下一个元素的下一个元素
//		ne[p] = ne[ne[p]];
//	}
//}
//
//int main()
//{
//	//头插
//	for (int i = 1; i <= 5; i++)
//	{
//		push_front(i);
//	}
//	print();
//
//	//查找
//	cout << find(4) << endl;
//	cout << find(6) << endl;
//	cout << find(1) << endl;
//
//	//任意位置之后插入元素
//	insert(1,10);
//	insert(1,9);
//	print();
//
//	//删除任意位置之后的元素
//	erase(1);
//	erase(1);
//	print();
//	return 0;
//}


//创建双向链表
int e[N],ne[N],pre[N],h,id;
int mp[N];
//打印
void print()
{
	//与pre数组无关
	for (int i = ne[h]; i; i = ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
}
//头插
void push_front(int x)
{
	//1.修改数据域,先存储新节点
	e[++id] = x;
	//2.修改新节点的前驱和后继指针
	pre[id] = h;
	ne[id] = ne[h];
	//3.修改头指针的下一个元素的前驱指针
	pre[ne[h]] = id;
	//4.修改头指针的后继指针
	ne[h] = id;

	//利用mp数组记录节点下标
	mp[x] = id;
}
//查找
int find(int x)
{
	////法一:遍历链表
	//for (int i = ne[h]; i; i = ne[i])
	//{
	//	if (e[i] == x)
	//		return i;
	//}
	//return 0;
	//法二:利用mp数组优化
	return mp[x];
}
//任意位置之后进行插入
void insert_back(int p, int x)
{
	//与头插同理
	//1.修改数据域,存储新节点
	e[++id] = x;
	//2.修改新节点的指针域
	pre[id] = p;
	ne[id] = ne[p];
	//3.修改当前p节点的下一个节点的前驱指针 
	pre[ne[p]] = id;
	//4.修改p节点的后继指针
	ne[p] = id;

	//利用mp数组记录节点下标
	mp[x] = id;
}
//在任意位置之前进行插入
void insert_front(int p, int x)
{
	e[++id] = x;
	pre[id] = pre[p];
	ne[id] = p;
	ne[pre[p]] = id;
	pre[p] = id;
	//利用mp数组记录节点下标
	mp[x] = id;
}
//任意位置删除元素
void erase(int p)
{
	//1.让p的前驱的后继节点改为p的后继节点
	ne[pre[p]] = ne[p];
	//2.让p的后继的前驱节点改为p的前驱节点
	pre[ne[p]] = pre[p];
	//3.删除mp数组的记录
	mp[p] = 0;
}
int main()
{
	//头插
	for (int i = 1; i <= 5; i++)
	{
		push_front(i);
	}
	print();
	////按值查找
	//cout << find(1) << endl;
	//cout << find(2) << endl;
	//cout << find(3) << endl;
	//cout << find(10) << endl;
	////任意位置之后进行插入
	//insert_back(1,100);
	//insert_back(1,99);
	//print();//5 4 3 2 1 99 100
	//在任意位置之前进行插入
	insert_front(1,8);
	insert_front(1,7);
	insert_front(1,6);
	print();//5 4 3 2 8 7 6 1 
	//任意位置删除元素
	erase(1);
	erase(7);
	print();
	return 0;
}