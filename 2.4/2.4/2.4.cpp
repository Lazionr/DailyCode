#define _CRT_SECURE_NO_WARNINGS

//二叉树DFS--链式前向星

//#include <iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//int l[N], r[N];
//bool st[N];
//int n;
//
//void DFS1(int u)
//{
//	cout << u << " ";
//	if (l[u]) DFS1(l[u]);
//	if (r[u]) DFS1(r[u]);
//}
//void DFS2(int u)
//{
//	if (l[u]) DFS2(l[u]);
//	cout << u << " ";
//	if (r[u]) DFS2(r[u]);
//}
//
//void DFS3(int u)
//{
//	if (l[u]) DFS3(l[u]);
//	if (r[u]) DFS3(r[u]);
//	cout << u << " ";
//}
//
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i < n; i++)
//	{
//		cin >> l[i] >> r[i];
//	}
//	DFS1(1);//先序遍历
//	cout << endl;
//	
//	DFS2(1);//中序遍历
//	cout << endl;
//
//	DFS3(1);//后序遍历
//	cout << endl;
//	return 0;
//}

//BFS
#include <iostream>
#include <queue>
using namespace std;

//存储时仅存储当前结点左右孩子，并不存储当前结点的父亲
//因此不需要bool数组
const int N = 1e5 + 10;
int l[N], r[N];
int n;

void BFS()
{
	queue<int> q;
	q.push(1);

	while (q.size())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";

		if (l[u]) q.push(l[u]);
		if (r[u]) q.push(r[u]);
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> l[i] >> r[i];
	}
	BFS();
	return 0;
}