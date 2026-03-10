#define _CRT_SECURE_NO_WARNINGS
//复习链式前向星
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int id,h[N], e[N * 2], ne[N * 2];
bool st[N];

void add(int a, int b)
{
	//就是将b头插到a所在的链表中
	e[++id] = b;
	ne[id] = h[a];
	h[a] = id;
}

void dfs(int u)
{
	//深度优先遍历
	cout << u << " ";
	st[u] = true;

	//遍历当前节点的所有子树
	for (int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if (!st[v]) dfs(v);
	}
}
void bfs()
{
	queue<int> q;
	//1.根节点入队
	q.push(1);
	st[1] = true;
	//2.当队列不为空,就拿出队头元素,并将对头元素的所有孩子入队
	while (!q.empty())
	{
		int u = q.front();
		cout << u << " ";
		q.pop();
		for (int i = h[u]; i; i = ne[i])
		{
			int v = e[i];
			if (!st[u])
			{
				q.push(u);
				st[u] = true;
			} 
		}
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	add(a, b);add(b, a);

	dfs(1);
	bfs();
	return 0;
}