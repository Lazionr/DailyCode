//#define _CRT_SECURE_NO_WARNINGS
////栈的模拟实现
//#include <iostream>
//using namespace std;
//const int N = 10010;
//
////创建栈
//int stk[N], n;
//
////进栈
//void push(int x)
//{
//	//进栈前判断是否有足够空间
//	stk[++n] = x;
//}
////出栈（顺序表的尾删）
//void pop()
//{
//	//判断是否为空
//	n--;
//}
////查找栈顶元素
//int top()
//{
//	//判断栈是否为空
//	return stk[n];
//}
////判断栈是否为空
//bool  empty()
//{
//	return n == 0;
//}
////查询有效元素个数
//int size()
//{
//	return n;
//}
//int main()
//{
//
//	for (int i = 1; i <= 10; i++)
//	{
//		push(i);
//	}
//	//while (!empty())
//	while(size())
//	{
//		cout << top() << endl;
//		pop();
//	}
//
//	return 0;
//}

#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
int main()
{
	//先将1-10进栈
	for (int i = 1; i <= 10; i++)
	{
		st.push(i);
	}
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}