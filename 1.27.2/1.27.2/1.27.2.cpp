#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string str = "0123456789ABCDEF";
void n_to_m(int x,int m)
{
	//十进制转任意进制
	if(x >= m)
	    n_to_m(x/m,m);
	cout << str[x % m];
} 
int main()
{
	int n,m;
	string s;
	cin >> n >> s >> m;
	//1.先转换为十进制
	int x = stoi(s,NULL,n);
	//2.再转换为其他进制
	n_to_m(x,m); 
	return 0;
}


#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int h,t,q[N];

int main()
{
	int n,op;
	cin >> n;
	while(n--)
	{
		cin >> op;
		if(op == 1)
		{
			int x;
			cin >> x;
			q[++t] = x;
		}
		else if(op == 2)
		{
			if(t - h)
			h++;
			else
			cout << "ERR_CANNOT_POP" << endl;
		}
		else if(op == 3)
		{
			if(t - h)
			cout << q[h+1] << endl;
			else
			cout << "ERR_CANNOT_QUERY"<< endl;  
		} 
		else 
		{
			cout << t - h << endl;
		}
	}
	return 0;
} 


#include <iostream>
#include <queue>

using namespace std;
const int N = 1010;

queue<int> q;
int a[N];
bool st[N];
int main()
{
	int m,n,x;
	cin >> m >> n;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		if(st[x])  continue;
		
		cnt++;
		//直接将x入队 
		q.push(x);
		st[x] = true;
		
		if(q.size() > m)
		{
			st[q.front()] = false;
			q.pop();
		} 
	}
	
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <queue>

using namespace std;
typedef unsigned long long ULL;
const ULL N = 1e9 + 10;
queue<ULL> q;
bool st[N];
int main()
{
	int n,p,g;
	ULL t;
	int cnt = 0;
	cin >> n;
	while(n--)
	{
		cin >> t >> p;
		while(p--)
		{
			cin >> g;
			if(st[g])  continue;
			
			st[g] = true;
			q.push(g);
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}


#include <iostream>
#include <queue>

using namespace std;
typedef unsigned long long ULL;
const ULL N = 1e9 + 10;
queue<ULL> q;
queue<ULL> time; 
bool st[N];
int main()
{
	int n,p,g;
	ULL t;
	int cnt = 0;
	cin >> n;
	while(n--)
	{
		cin >> t >> p;
		//让时间入队
		 time.push(t);
		 while(t - time.front() >= 86400)
		 {
		 	time.pop();
		 }
		 while(p--)
		{
			cin >> g;
			if(st[g])  continue;
			
			st[g] = true;
			q.push(g);
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}




#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> PII;

const int N = 1e5 + 10;
int cnt[N],kinds;
queue<PII> q;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int t,k,x;
		cin >> t >> k;
		for(int i = 1;i <= k;i++)
		{
			cin >> x;
			q.push({t,x});
			if(cnt[x]++ == 0)  kinds++;
		}
		//保证时间合法
		while(q.size() && q.back().first - q.front().first >= 86400)
		{
			PII tmp = q.front();
			q.pop();
			int x = tmp.second;
			if(cnt[x]-- == 1)  kinds--;
		}
		cout << kinds << endl; 
	}
	
	return 0;
}




//STL中的deque
#include <iostream>
#include <deque>

using namespace std;

struct Node
{
	int x, y, z;
};
deque<Node> q;
int main()
{
	//头插
	for (int i = 1; i <= 10; i++)
	{
		q.push_front({ i,i * 2,i * 3 });
	}
	//头删
	while (q.size())
	{
		auto e = q.front();
		q.pop_front();
		cout << e.x << " " << e.y << " " << e.z << endl;
	}
	//尾插
	for (int i = 1; i <= 5; i++)
	{
		q.push_back({ i,i * 2,i * 3 });
	}
	//尾删
	while (q.size())
	{
		auto e = q.back();
		q.pop_back();
		cout << e.x << " " << e.y << " " << e.z << endl;
	}
	return 0;
}

