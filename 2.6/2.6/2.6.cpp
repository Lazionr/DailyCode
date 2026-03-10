#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 110;

vector<int> edges[N];
int fa[N];//记录i的父亲节点 
int dist[N];//记录i到x的距离 
int n;

int dfs(int u)
{
	int ret = 0;
	for (auto e : edges[u])
	{
		ret = max(ret, dfs(e));
	}
	return ret + 1;
}
int bfs()
{
	queue<int> q;
	q.push(1);

	int ret = 0;
	while (q.size())
	{
		int sz = q.size();
		ret = max(ret, sz);;

		//让当前队列所有元素出队的同时下一层元素全部入队 
		while (sz--)
		{
			int u = q.front();
			q.pop();
			for (auto e : edges[u])
			{
				q.push(e);
			}
		}
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		fa[v] = u;
	}
	//求深度即求高度
	//二叉树的高度 = max(左子树+ 右子树) + 1; 
	cout << dfs(1) << endl;
	//求宽度
	cout << bfs() << endl;
	//求距离
	int x, y;
	cin >> x >> y;
	while (x != 1)
	{
		dist[fa[x]] = dist[x] + 1;
		x = fa[x];
	}
	int len = 0;
	while (y != 1 && dist[y] == 0)
	{
		//dist[y] == 0表示没有到达相遇点
		len++;
		y = fa[y];
	}
	cout << dist[y] * 2 + len << endl;
	return 0;
}

