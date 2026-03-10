#define _CRT_SECURE_NO_WARNINGS
//树的模拟实现

//树的存储
//1.用vector数组实现
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;

int n;
vector<int> edges[N]; 

int main()
{
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	return 0;
}

//2.链式前向星
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2],id;
int n;

void add(int x,int y)
{
	//将y头插到x的链表中
	e[++id] = y;
	ne[id] = h[x];
	h[x] = id;
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		//a和b之间有一条边
		add(a, b);//a后面有个孩子b
		add(b, a);//b后面有个孩子a

	}
	return 0;
}

//树的遍历
//1.DFS(深度优先遍历)
//vector数组存储树

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n;

vector<int> edges[N];
bool st[N];//记录哪些点已经访问过了

void dfs(int u)
{
	cout << u << " ";
	st[u] = true;

	//访问所有孩子
	for (auto e : edges[u])
	{
		if (!st[e])
		{
			dfs(e);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	//深度优先遍历
	dfs(1);

	return 0;
}

//2.链式前向星存储树
#include <iostream>
using namespace std;
const int N = 1e5 + 10;

int h[N], e[N * 2], ne[N * 2], id;
int n;
bool st[N];

void add(int x, int y)
{
	e[++id] = y;
	ne[id] = h[x];
	h[x] = id;
}
void DFS(int r)
{
	cout << r << " ";
	st[r] = true;
	for (int i = h[r]; i; i = ne[i])
	{
		int v = e[i];//当前结点的孩子
		if (!st[v])
		{
			DFS(v);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b; cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	DFS(1);
	return 0;
}