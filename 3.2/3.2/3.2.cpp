#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 110;
vector<int> edges[N];
int n;

int fa[N],dist[N];

int dfs(int u)
{
	if(u == 0) return 0;
	int ret = 0;
	for(auto e : edges[u])
	{
		ret = max(ret,dfs(e));
	}
	return ret + 1;
}

int bfs()
{
	queue<int> q;
	q.push(1);
	
	//借助队列
    int ret = 0;
	while(q.size())
	{
		int sz = q.size();
		ret = max(ret,sz);
		while(sz--)
		{
			int u = q.front();
			q.pop();
			for(auto v : edges[u])
			{
				q.push(v);
			}
		}

	}
	return ret;
}

int dis(int x,int y)
{
	//记录当前节点到x的距离 
	while(x != 1)
	{
		dist[fa[x]] = dist[x] + 1;
		x = fa[x];
	}
	//此时y开始向上爬
	int cnt = 0;
	while(y != 1 && dist[y] == 0)
	{
		y = fa[y];
		cnt++;//记录y向上爬的次数 
	} 
	//计算总路程
	return 2 * dist[y] + cnt; 
}
int main()
{
	cin >> n;
	for(int i = 2;i <= n;i++)
	{
		int u,v;cin >> u >> v;
		edges[u].push_back(v);
		fa[v] = u;	//在fa数组中存储父节点
	}
	int x,y;cin >> x >> y;
	
	cout << dfs(1) << endl;
	
	cout << bfs() << endl;
	
	cout << dis(x,y) << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int n,id,h[N];

void up(int child)
{
	int parent = child / 2;
	while(parent >= 1 && h[parent] > h[child])
	{
		swap(h[parent],h[child]);
		child = parent;
	    parent = child / 2;
	}
}
void down(int parent)
{
	int child = parent * 2;
	while(child <= id)
	{
		if(child + 1 <= id && h[child+1] < h[child]) child++;
		if(h[child] > h[parent]) return;
		swap(h[child],h[parent]);
		parent = child;
		child = parent * 2;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while(n--)
	{
		int op;cin >> op;
		if(op == 1)
		{
			int x;cin >> x;
			//1.将元素加入到末尾 
			h[++id] = x;
			//2.执行向上调整算法 
			up(id); 
		}
		else if(op == 2)
		{
			cout << h[1] << endl;
		}
		else
		{
			//1.交换堆顶元素与末尾元素,id--
			swap(h[1],h[id--]);
			//2.然后在根节点执行向下调整算法
			down(1); 
		}
	}
	
	return 0;
}


#include <iostream>
#include <queue>
using namespace std;

int n,m,k;

//创建大根堆 
priority_queue<int> h;

int main()
{
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		int x;cin >> x;
		h.push(x);
		if(h.size() > k) h.pop();
	}
	while(m--)
	{
		int op;cin >> op;
		if(op == 1)
		{
			//加入元素
			int num;cin >> num;
			h.push(num);
			if(h.size() > k) h.pop();
		}
		else
		{
			//查询第k小
			if(h.size() < k) cout << -1 << endl;
			else cout << h.top() << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> h;
int n,k;
long long sum1,sum2;

int main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		int x;cin >> x;
		if(x % 2) sum1 += x;
		else h.push(x);
	}
	while(k-- && !h.empty())
	{
		int key = h.top() / 2;h.pop();
		if(key % 2) sum2 += key;
		else h.push(key);
		
	}
	while(!h.empty())
	{
		sum2 += h.top();
		h.pop();
	}
	cout << sum1 + sum2 << endl;
	return 0;
}


#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
int a[N],b[N],c[N];
int n,m;

struct node
{
	int f;//函数值 
	int num;//函数编号 
	int x;//代入值 
	
	bool operator <(const node & s) const
	{
		//小根堆 
		return f > s.f; 
	}
};

priority_queue<node> h;

int calc(int i,int x)
{
	return a[i] * x * x + b[i] * x + c[i];
}
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	//让x=1进堆
	for(int i = 1;i <= n;i++)
	{
		h.push({calc(i,1),i,1});
	}
	//2.依次拿出m个值
	while(m--)
	{
		auto t = h.top();h.pop();
		int f = t.f,num = t.num,x = t.x;
		cout << f << " ";
		h.push({calc(num,x+1),num,x+1});
	}
	return 0;
}


#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
	cin >> n;
	for(int i = n;i >= 0;i--)
	{
		int a;cin >> a;
		if(a == 0) continue;
		//1.符号
		if(a < 0) cout << '-';
		else
		{
			if(i != n) cout << '+';
		} 
		//2.数字
		a = abs(a);
		if(a != 1 || (a == 1 && i == 0)) cout << a;
		//3.次数 
		if(i == 0) continue;
		else if(i == 1) cout << "x";
		else cout << "x^" << i;
	}
	return 0;
}



