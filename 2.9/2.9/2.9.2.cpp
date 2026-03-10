#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n,m,k;

int main()
{
	//小根堆 
	priority_queue <int,vector<int>,greater<int>> q;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		q.push(a[i]);
	}
	int op;
	while(m--)
	{
		cin >> op;
		if(op == 1)
		{
			int x;cin >> x;
			q.push(x);
		}
		else
		{
			//查询第k小的数
			
		}
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

const int N = 2e5 + 10;
int n,m,k;
priority_queue <int> q;
 
int main()
{
	//用大根堆来维护 
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		int x;cin >> x;
		q.push(x);
		if(q.size() > k) q.pop();
 	}
	int op;
	while(m--)
	{
		cin >> op;
		if(op == 1)
		{
			int x;cin >> x;
			q.push(x);
			if(q.size() > k) q.pop();
		}
		else
		{
			//查询第k小的数
			if(q.size() == k) cout << q.top() << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int n, k;
priority_queue<int> heap;
long long sum1, sum2;

int main()
{
	int x;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x % 2)
		{
			//a[i]是奇数
			sum1 += x;
		}
		else
		{
			//a[i]是偶数，进堆
			heap.push(x);
		}
	}
	//当堆不为空时才能进行pop操作,否则程序崩溃 
	while (k-- && !heap.empty())
	{
		int u = heap.top() / 2;
		heap.pop();
		//放回堆之前判断是否为偶数
		if (u % 2)
			sum1 += u;
		else
			heap.push(u);
	}
	//对堆顶元素进行求和
	while (!heap.empty())
	{
		sum2 += heap.top();
		heap.pop();
	}
	cout << sum1 + sum2 << endl;
	return 0;
}


