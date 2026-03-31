#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int n;
int t[N],d[N],l[N];
bool st[N];

bool dfs(int pos,int end)
{
	if(pos > n) return true;
	
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

int main()
{
	int T;cin >> T;
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


#include <iostream>
#include <vector>

using namespace std;

const int N = 15; 

int n,ret;
vector<int> path;
bool col[N],st1[N],st2[N];

void dfs(int pos)
{
	if(path.size() == n)
	{
		ret++;
		if(ret <= 3)
		{
			for(auto e : path) cout << e << " ";
		    cout << endl;
		}
		return;
	}
	
	for(int i = 1;i <= n;i++)
	{
		if(col[i] || st1[i - pos + n] || st2[i + pos]) continue;
		
		path.push_back(i);
		col[i] = st1[i - pos + n] = st2[i + pos] = true;
		
		dfs(pos+1);
		
		path.pop_back();
		col[i] = st1[i - pos + n] = st2[i + pos] = false;
	}

	
	
}

int main()
{
	cin >> n;
	
	dfs(1);
	
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 200;

int n,k;
int ret;
vector<int> path;
unordered_map<int,int> mp;

void dfs()
{
	if(path.size() == k)
	{
		ret++;
		return;
	}

	for(int i = 1;i <= n - k + 1;i++)
	{
		path.push_back(i);
		mp[i]++;
		bool flag = false;
		for(auto x : path)
		{
			if(mp[x] == 0) flag = true;
		}
		if(!flag) continue;
		
		dfs();
		
		path.pop_back();
		mp[i]--;
		
	}
}

int main()
{
	cin >> n >> k;
	dfs();
	cout << ret << endl;
	return 0;
}

#include <iostream>

using namespace std;

int n,k;
int path,ret;

void dfs(int pos,int begin)
{
	if(pos == k)
	{
		if(path == n) ret++;
		return;
	}
	
	for(int i = begin;i <= n;i++)
	{
		if(path + i * (k - pos) > n) return;
		
		path += i;
		dfs(pos+1,i);
		
		path -= i;
	}
}

int main()
{
	cin >> n >> k;
	
	dfs(0,1);
	
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n,w,a[N];
int path,ret;
int ans;

void dfs(int cnt)
{
	if(cnt >= ans) return;
	//在cnt辆缆车中寻找最优解
	
	for(int i = 1;i <= n;i++)
	{
		
	}
	
}

int main()
{
	cin >> n >> w;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	sort(a+1,a+1+n);
	
	//确定缆车数量
	int height = 0;
	for(int i = 1;i <= n;i++)
	{
		ans++
		if(height + a[i] >= w)
		{
			ans--;
			break;
		}
	}
	 
	dfs(0);
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n, w;
int c[N];
int cnt, s[N];
int ret = N;

bool cmp(int a, int b)
{
	return a > b;
}

void dfs(int pos)
{
	//cnt是缆车数量 
	if (cnt > ret) return;
	if (pos > n)
	{
		ret = cnt;
		return;
	}

	//先安排小猫加入已有缆车 
	for (int i = 1; i <= cnt; i++)
	{
		//i表示的是缆车，因此如果当前缆车超重，要继续判断下一个缆车，不能return 
		if (c[pos] + s[i] > w) continue;
		s[i] += c[pos];
		dfs(pos + 1);
		s[i] -= c[pos];
	}

	//再开新缆车
	cnt++;
	s[cnt] += c[pos];
	dfs(pos + 1);
	s[cnt] = 0;
	cnt--;
}

int main()
{
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> c[i];

	//先处理重的 
	sort(c + 1, c + 1 + n, cmp);

	dfs(1);
	cout << ret << endl;
	return 0;
}

