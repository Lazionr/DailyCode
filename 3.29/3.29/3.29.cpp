#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n;
string path;

void dfs(int pos)
{
	if(pos > n)
	{
		cout << path << endl;
		return;
	}
	
	//ฒปัก
	path += 'N';
	dfs(pos+1);
	path.pop_back();
	
	//ัก 
	path += 'Y';
	dfs(pos + 1);
	path.pop_back();
}
int main()
{
	cin >> n;
	dfs(1);
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> path; 

void dfs(int begin)
{
	if(path.size() == m)
	{
		for(auto x : path) cout << x << " ";
		cout << endl;
		return;
	}
	
	for(int i = begin;i <= n;i++)
	{
		path.push_back(i);
		dfs(i+1);
		path.pop_back();
	}
}
int main()
{
	cin >> n >> m;
	
	dfs(1);
	return 0;
}



#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n,k;
vector<int> path;
bool st[N];

void dfs()
{
	if(path.size() == k)
	{
		for(auto x : path) cout << x << " ";
		cout << endl;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!st[i])
		{
			path.push_back(i);
			st[i] = true;
		    dfs();
		    path.pop_back();
		    st[i] = false;
		}
	}
}

int main()
{
	cin >> n >> k;
	
	dfs();
	return 0;
}


#include <iostream>
#include <vector>

const int N = 15;

using namespace std;

int n;
vector<int> path;
bool st[N];

void dfs()
{
	if(path.size() == n)
	{
		for(auto x : path) 	printf("%5d",x);
		cout << endl;
		return;
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(!st[i])
		{
			path.push_back(i);
			st[i] = true;
			dfs();
			path.pop_back();
			st[i] = false;
		} 
	}
}
int main()
{
	cin >> n;
	
	dfs();
	return 0;
 } 


#include <iostream>
#include <vector>
using namespace std;

const int N = 25;

int n,k;
int a[N];
vector<int> path;
int cnt;

bool is_prime(int x)
{
	if(x <= 1) return false;
	if(x == 2) return true;
	if(x % 2 == 0) return false;
	for(int i = 3;i <= x / i;i += 2)
	{
		if(x % i == 0) return false;
	}
	return true;
}

int dfs(int begin)
{
	int sum = 0;
	if(path.size() == k)
	{
		for(auto x : path) sum += x;
		if(is_prime(sum)) cnt++;
		return cnt;
	}
	
	for(int i = begin;i <= n;i++)
	{
		path.push_back(a[i]);
		dfs(i+1);
		path.pop_back();
	}
}

int main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i]; 
	cout << dfs(1) << endl;
	return 0;
}


#include <iostream>
#include <cstring> 
using namespace std;

const int N = 15;

int n;
int t[N],d[N],l[N];
bool st[N];

bool dfs(int pos,int end)
{
	if(pos > n)
	{
		return true;
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(st[i]) continue;
		if(end > t[i] + d[i]) continue;
		st[i] = true;
		int newend = max(end,t[i]) + l[i];
		if(dfs(pos+1,newend)) return true;
		st[i] = false;
	}
	return false;
}


int  main()
{
	int T; cin >> T;
	while(T--)
	{
		memset(st,0,sizeof(st));
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> t[i] >> d[i] >> l[i];
		if(dfs(1,0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

