#define _CRT_SECURE_NO_WARNINGS
//DFS--两种实现方式

////1.顺序表存储树
//#include <iostream>
//#include <vector>
//
//using namespace std;
//const int N = 1e5 + 10;
//vector<int> edges[N];
//int n;
//bool st[N];
//
//
//void DFS(int u)
//{
//	cout << u << " ";
//	st[u] = true;
//
//	//访问其他未被访问过的节点
//	for (auto e : edges[u])
//	{
//		if (!st[e])
//		{
//			DFS(e);
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i < n; i++)
//	{
//		int a, b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);
//	}
//	DFS(1);
//	return 0;
//}

////2.链表存储树
//#include <iostream>
//using namespace std;
//const int N = 1e5 + 10;
//int id, h[N], e[N * 2], ne[N * 2];
//bool st[N];
//int n;
//
//void add(int x, int y)
//{
//	//将y头插到x的链表中
//	e[++id] = y;
//	ne[id] = h[x];
//	h[x] = id;
//}
//void DFS(int u)
//{
//	cout << u << " ";
//	st[u] = true;
//
//	for (int i = h[u]; i; i = ne[i])
//	{
//		if (!st[e[i]])
//		{
//			DFS(e[i]);
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i < n; i++)
//	{
//		int a, b; cin >> a >> b;
//		add(a, b);
//		add(b, a);
//	}
//	DFS(1);
//	return 0;
//}

//BFS--两种实现方式

////1.vector存储树
//#include <iostream>
//#include <queue>
//using namespace std;
//const int N = 1e5 + 10;
//vector<int> edges[N];
//bool st[N];
//int n;
//
//void BFS()
//{
//	queue<int> q;
//	q.push(1);
//	st[1] = true;
//
//	while (q.size())
//	{
//		int u = q.front();
//		q.pop();
//		cout << u << " ";
//
//		for (auto e : edges[u])
//		{
//			if (!st[e])
//			{
//				q.push(e);
//				st[e] = true;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i < n; i++)
//	{
//		int a, b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);
//	}
//	BFS();
//	return 0;
//}

////2.链式前向星存储树
//#include <iostream>
//#include <queue>
//using namespace std;
//
//const int N = 1e5 + 10;
//int id, h[N], e[N * 2], ne[N * 2];
//int n;
//bool st[N];
//
//
//void add(int x, int y)
//{
//	//将y头插到x的链表中
//	e[++id] = y;
//	ne[id] = h[x];
//	h[x] = id;
//}
//
//void BFS()
//{
//	queue<int> q;
//    q.push(1);
//	st[1] = true;
//
//	while (q.size())
//	{
//		auto u = q.front();
//		q.pop();
//		cout << u << " ";
//		for (int i = h[u]; i; i = ne[i])
//		{
//			auto v = e[i];
//			if (!st[v])
//			{
//				q.push(v);
//				st[v] = true;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i < n; i++)
//	{
//		int a, b; cin >> a >> b;
//		add(a, b);
//		add(b, a);
//
//	}
//	BFS();
//	return 0;
//}

//二叉树的存储

//链式存储
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int l[N], r[N];
bool st[N];

void DFS1(int u)
{
	//先序遍历
	cout << u << " ";
	if (l[u]) DFS1(l[u]);
	if (r[u]) DFS1(r[u]);
}

void DFS2(int u)
{
	//中序遍历
	if (l[u]) DFS2(l[u]);
	cout << u << " ";
	if (r[u]) DFS2(r[u]);
}
void DFS3(int u)
{
	//中序遍历
	if (l[u]) DFS3(l[u]);
	if (r[u]) DFS3(r[u]);
	cout << u << " ";
}
int main()
{
	cin >> n;
	//存二叉树
	for (int i = 1; i < n; i++)
	{
		cin >> l[i] >> r[i];
	}
	DFS1(1);//先序遍历
	cout << endl;

	DFS2(1);//中序遍历
	cout << endl;

	DFS3(1);//后序遍历
	cout << endl;

	return 0;
}


