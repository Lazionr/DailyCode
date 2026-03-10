#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int sum;
	int i,j;
		
	bool operator< (const node & s) const
	{
		return sum > s.sum; 
	}
};

priority_queue<node> heap;//小根堆 
const int N = 1e5 + 10;
int a[N],b[N];
int n;

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	
	for(int i = 1;i <= n;i++)
	{
		//计算a[i]与b[1]的和 
		heap.push({a[i] + b[1],i,1});
	}
	
	for(int k = 1;k <= n;k++)
	{
		auto e = heap.top(); heap.pop();
		
		int sum = e.sum,i = e.i,j = e.j;
		cout << sum <<  " ";
		if(j+1 <= n) heap.push({a[i]+b[j+1],i,j+1});
	}
	return 0;
}


#include <iostream>
#include <queue>
using namespace std;

const int N = 2e5 + 10;
char gen[N];
int a[N],n;

struct node
{
	int key;
	int p,q;
	//男女编号 
	
	bool operator< (const node & s) const
	{
		return key > s.key;
	}
};

priority_queue<node> heap;

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> gen[i];
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	//先进行配对
	int k = 0;
	int i = 1,j = 2;
	while(j <= n)
	{
		if((gen[i] == 'B' && gen[j] == 'G') || (gen[i] == 'G' && gen[j] == 'B'))
		{
			int ret = a[i] - a[j];
		    if(ret < 0) ret *= -1;
		    heap.push({ret,i,j});	
			k++;
		}
	} 
	cout << k << endl;
	if(k)
	{
		while(k--)
        {
	 	    auto e = heap.top(); heap.pop();
		    cout << e.p << " " << e.q << endl;
	    }
	}
	return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;
int n;
int e[N],ne[N],pre[N];
int s[N];
bool st[N];

struct node
{
	int key;
	//key的左右编号 
	int l,r;
	
	bool operator< (const node & s) const
	{
		if(key != s.key) return key > s.key;
		else if(l != s.l) return l > s.l;
		else return r > s.r;
	}
};

priority_queue<node> heap;

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		char ch;
		cin >> ch;
		//男孩记为1 
		if(ch == 'B') s[i] = 1;         
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> e[i];
		pre[i] = i - 1;
		ne[i] = i + 1;
	}
	pre[1] = ne[n] = 0;
	
	//让所有异性的key进堆 
	for(int i = 2;i <= n;i++)
	{
		if(s[i] != s[i-1])
		{
			heap.push({abs(e[i] - e[i-1]),i-1,i});
		}
		
	}
	vector<node> ret;//暂存结果
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int key = t.key,l = t.l,r = t.r;
		
		if(st[l] || st[r]) continue;
		
		ret.push_back(t);
		st[l] = st[r] = true;
		
		//修改指针，还原新的队列 
		ne[pre[l]] = ne[r];
		pre[ne[r]] = pre[l];
		
		//判断新的左右是否会成为一对
		int left = pre[l],right = ne[r];
		
		if(left && right && s[left] != s[right])
		{
			heap.push({abs(e[left] - e[right]),left,right});
		} 
		
		cout << ret.size() << endl;
		for(auto& x : ret)
		{
			cout << x.l << " " << x.r << endl;
		}
	}
	return 0;
}








#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
int n;
int s[N]; // 标记男女  - 0/1 
// 双向链表存数据
 
int e[N];
int pre[N], ne[N];
struct node
{
int d; // 技术差
 
int l, r; //左右编号
 

 
bool operator < (const node& x) const
{
if(d != x.d) return d > x.d;
else if(l != x.l) return l > x.l;
else return r > x.r;
}
};
priority_queue<node> heap;
bool st[N]; // 标记已经出队的?
 
int main()
{
cin >> n;
for(int i = 1; i <= n; i++)
{
char ch; cin >> ch;
if(ch == 'B') s[i] = 1;
}
for(int i = 1; i <= n; i++)
{
cin >> e[i];
// 创建双向链表
 
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    pre[1] = ne[n] = 0; 
 
    // 1. 先把所有的异性差放进堆中
 
    for(int i = 2; i <= n; i++)
    {
        if(s[i] != s[i - 1])
        {
            heap.push({abs(e[i] - e[i - 1]), i - 1, i});
        }
    }
    // 2. 提取结果
 
    vector<node> ret; // 暂存结果
 
    while(heap.size())
    {
        node t = heap.top(); heap.pop();
        int d = t.d, l = t.l, r = t.r;
        if(st[l] || st[r]) continue;
        ret.push_back(t);
        st[l] = st[r] = true; // 标记 l 和 r 已经出列
 
        // 修改指针，还原新的队列
 
        ne[pre[l]] = ne[r];
        pre[ne[r]] = pre[l];
        // 判断新的左右是否会成为?对
 
        int left = pre[l], right = ne[r];
        if(left && right && s[left] != s[right])
        {
            heap.push({abs(e[left] - e[right]), left, right});
        }
    }
    cout << ret.size() << endl;
    for(auto& x : ret)
    {
        cout << x.l << " " << x.r << endl;
    }
    return 0;
}

