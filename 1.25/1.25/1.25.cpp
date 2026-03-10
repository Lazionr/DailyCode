#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int n,h;

int ne[N];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> ne[i];
	}
	cin >> h;
	for(int i = h;i;i = ne[i])
	{
		cout << i << " ";
	}
	return 0;
}


#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int ne[N];
int n,h;
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> ne[i];
	}
	cin >> h;
	for(int i = h;i;i=ne[i])
	{
		cout << i << " ";
	}
	return 0;
}

#include <iostream>
using namespace std;

const int N = 1e5 + 10,M = 1e6 + 10;
int e[N];
int ne[N];
int mp[M];
int h,id,q,op,x,y;

int main()
{
	e[h] = 1;
	mp[1] = h;
	cin >> q;
	while(q--)
	{
		cin >> op >> x;
		if(op == 1)
		{
			cin >> y;
			//将y插入到x后面
			 e[++id] = y;
			 mp[y] = id;
			 //先更改y的后继指针 
			 ne[id] = ne[mp[x]];
			 ne[mp[x]] = id;
		}
		else if(op == 2)
		{
			if(ne[mp[x]])
			  cout << e[ne[mp[x]]] << endl;
			else
			  cout << 0 << endl;
		}
		else
		{
			ne[mp[x]] = ne[ne[mp[x]]];
		}
	}
	return 0;
}

#include <iostream>

using namespace std;

int const N = 1e5 + 10;
int n,m,id,h,op,e[N],ne[N],pre[N];
int mp[N];
int x,y;

int main()
{
	cin >> n;
	//初始化
	 e[++id] = 1;
	 mp[1] = id;
	 pre[id] = 0;
	 ne[id] = 0;
	 h = id;
	 while(n--)
	 {
	 	cin >> x >> op;
	 	int p = mp[x];
	 	if(op == 1)
	 	{
	 		//排在p的后面 
			e[++id] = id;
			mp[id] = id;
			pre[id] = p;
			ne[id] = ne[p];
			pre[ne[p]] = id;
			ne[p] = id;
		}
		else
		{
			//排在p的前面 
			 e[++id] = id;
			 mp[id] = id;
			 pre[id] = pre[p];
			 ne[id] = p;
			 ne[pre[p]] = id;
			 pre[p] = id;
		}
		cin >> m;
		while(m--)
		{
			cin >> y;
			int q = mp[y];
			if(q)
			{
				ne[pre[q]] = ne[q];
			    pre[ne[q]] = pre[q];
			    mp[q] = 0;
			}
		}
		
		for(int i = 1;i;i = ne[i])
		{
			cout << e[i] << " ";
		}
	 }
	return 0;
}

当e数组与下标对应位置匹配时，就只需下标即可 
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int h,pre[N],ne[N];
bool st[N];

int main()
{
	//初始化
	pre[1] = h;
	ne[1] = 0;
	
	int n;
	cin >> n;
	for(int i = 2;i <= n;i++)
	{
		int k,p;
		cin >> k >> p;
		if(p == 0)
		{
			//将i插在k的左边
			pre[i] = pre[k];
			ne[i] = k;
			ne[pre[k]] = i;
			pre[k] = i;
		}
		else
		{
			//将i插在k的右边
			pre[i] = k;
			ne[i] = ne[k];
			pre[ne[k]] = i;
			ne[k] = i;
		}
	} 
	int m,x;
	cin >> m;
	while(m--)
	{
		cin >> x;
		if(st[x] == true)
		  continue;
		//将x删除
		ne[pre[x]] = ne[x];
		pre[ne[x]] = pre[x];
		st[x] = true; 
	}
	for(int i = ne[h];i;i = ne[i])
	{
		cout << i << " ";
	}
	return 0;
}


#include <iostream>
using namespace std;

const int N = 110;
int h, ne[N];
int n, m;
int main()
{
	ne[h] = 0;
	for (int i = 1; i < n; i++)
	{
		ne[i] = i + 2;
	}
	ne[n] = 1;
	int t = n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			t = ne[t];
		}
		cout << ne[t] << " ";
		ne[t] = ne[ne[t]];
	}
	return 0;
}
