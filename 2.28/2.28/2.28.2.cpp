#define _CRT_SECURE_NO_WARNINGS

//二叉树的存储与遍历
#include<iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, l[N], r[N];

void dfs1(int u)
{
	//根左右
	cout << u << " ";
	if (l[u]) dfs1(l[u]);
	if (r[u]) dfs1(r[u]);
}
void dfs2(int u)
{
	if (l[u]) dfs2(l[u]);
	cout << u << " ";
	if (r[u]) dfs2(r[u]);
}
void dfs3(int u)
{
	if (l[u]) dfs3(l[u]);
	if (r[u]) dfs3(r[u]);
	cout << u << " ";
}

void bfs()
{
	queue<int> q;
	q.push(1);

	while (q.size())
	{
		auto u = q.front(); q.pop();
		cout << u << " ";

		//左右孩子入队
		if (l[u]) q.push(l[u]);
		if (r[u]) q.push(r[u]);

	}
	cout << endl;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}
	//先序遍历
	dfs1(1);
	//中序遍历
	dfs2(1);
	//后序遍历
	dfs3(1);

	bfs();
	return 0;
}