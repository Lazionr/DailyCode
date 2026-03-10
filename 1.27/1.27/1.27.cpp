#define _CRT_SECURE_NO_WARNINGS

////队列的模拟实现
//
//#include <iostream>
//using namespace std;
//
//const int N = 10010;
////1.创建队列
//int q[N],h,t;
//
////2.入队操作
//void push(int x)
//{
//	//队列不是满的即t <= N;
//	q[++t] = x;
//}
////3.出队操作（删除队头）
//void pop()
//{
//	//队列非空
//	h++;
//}
////4.查询队头
//int front()
//{
//	//队列非空
//	return q[h + 1];
//}
////5.查询队尾
//int back()
//{
//	//队列非空
//	return q[t];
//}
////6.判空
//bool empty()
//{
//	return h == t;
//}
////7.查询队列有效元素个数
//int size()
//{
//	return t - h;
//}
//int main()
//{
//	//测试
//	for (int i = 1; i <= 10; i++)
//	{
//		push(i);
//	}
//	while (size())
//	{
//		cout << front() << " " << back() << endl;
//		pop();
//	}
//	return 0;
//}


//STL中queue的使用
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> PII;

int main()
{
	//测试queue
	queue<PII> q;
	for (int i = 1; i <= 10; i++)
	{
		q.push({ i,i * 10 });
	}
	while (q.size())
	{
		auto t = q.front();
		cout << t.first << " " << t.second << endl;

		q.pop();
	}
	return 0;
}