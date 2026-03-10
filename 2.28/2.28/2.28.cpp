#define _CRT_SECURE_NO_WARNINGS

//复习链式前向星-bfs-dfs
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int id, h[N], e[N * 2], ne[N * 2];
bool st[N];

void add(int x, int y)
{
	//将y头插到x中
	e[++id] = y;
	ne[id] = h[x];
	h[x] = id;
}
void dfs(int u)
{
	//深度优先遍历
	cout << u << " ";
	st[u] = true;
	for (int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if (!st[v]) dfs(v);
	}
}

void bfs()
{
	//广度优先遍历-借助队列
	//1.初始化
	queue<int> q;
	q.push(1);
	st[1] = true;
	//2.执行逻辑
	while (q.size())
	{
		//当队列有元素时，就输出队头元素，并让队头元素的所有孩子入队
		int u = q.front(); q.pop();
		cout << u << " ";
		for (int i = h[u]; i; i = ne[i])
		{
			int v = e[i];
			if (!st[v])
			{
				q.push(v);
				st[v] = true;
			}
		}
	}
}

int main()
{
	int a, b; cin >> a >> b;
	add(a, b);
	add(b, a);

	dfs(1);
	bfs();
	return 0;
}