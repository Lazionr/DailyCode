#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL n,m; 
LL f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		LL x;cin >> x;
		f[i] += x;
		f[i+1] -= x;
	}
	
	while(m--)
	{
		LL l,r,k;
		cin >> l >> r >> k;
		
		//处理当前元素
		f[l] += k;
		f[r+1] -= k;
	}
	
	for(int i = 1;i <= n;i++)
	{
		f[i] = f[i-1] + f[i];
		cout << f[i] << " ";
	}
	cout << endl;
	
	return 0;
}


#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1010;

LL n,m,q;
LL f[N][N];

void insert(int x1,int y1,int x2,int y2,int x)
{
	f[x1][y1] += x;
	f[x1][y2+1] -= x;
	f[x2+1][y1] -= x;
	f[x2+1][y2+1] += x;
} 

int main()
{
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			LL x;cin >> x;
			insert(i,j,i,j,x);
		}
	}
	
	while(q--)
	{
		int x1,y1,x2,y2,k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		insert(x1,y1,x2,y2,k);
	}
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-1] + f[i][j];
			cout << f[i][j] << " ";
		}
		cout << endl; 
	}
	
	return 0;
 } 

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int a[N];
bool st[N];

int main()
{
	int T;cin >> T;
	while(T--)
	{
		memset(st,0,sizeof(st));
		
		int n;cin >> n;
		for(int i =  1;i <= n;i++) cin >> a[i];
		
		int l = 1,r = 1,kind = 0;
		int ret = 0;
		while(r <= n)
		{
			if(!st[a[r]])
			{
				kind++;
				st[a[r]] = true;
				r++;
			}
			else
			{
				ret = max(ret,kind);
				st[a[l]] = false;
				kind = 0;
				l++;
			}
		}
		cout << ret << endl; 
	}
	
	return 0;
}

#include <iostream>
#include <unordered_map>

using namespace std;


int main()
{
	int T;cin >> T;
	while(T--)
	{
		int n;cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i];
		
		unordered_map<int,int> mp;
		
		int l = 1,r = 1;
		int ret = 0;
		while(r <= n)
		{
			//进窗口 
			mp[a[r]]++;
			while(mp[a[r]] > 1)
			{
				mp[a[l]]--;
				l++;
			}
			//窗口合法 
			ret = max(ret,mp.size());
			r++;
		}
		cout << ret << endl;
	}
	return 0;
}


#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 10;

int a[N];

int main()
{
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	unordered_map<int,int> mp;
	
	int l = 1,r = 1;
	int ret = 1e6,ret_l = 1,ret_r = 1;
	while(r <= n)
	{
		mp[a[r]]++;
		while(mp.size() == m)
		{
			//判断是否需要优化
			int len = r - l + 1;
			if(len < ret)
			{
			    ret = len;
				ret_l = l;
				ret_r = r;
			}
			mp[a[l]]--;
			if(mp[a[l]] == 0) mp.erase(a[l]);
			l++;
		}
		r++;
	}
	cout << ret_l << " " << ret_r << endl;
	return 0;
} 

#include <iostream>
#include <unordered_map>

using namespace std;

int ret;
string s;
unordered_map<char,int> mp;

int main()
{
	cin >> s;
	int l = 0,r = 0;
	int len = s.size();
	int ret = 1e6;
	while(r < len)
	{
		mp[s[r]]++;
		
		while(mp.size() == 26)
		{
			//判断是否能优化
			int cnt = r - l + 1;
			ret = min(cnt,ret);
			
			mp[s[l]]--;
			//如果不删除，该键就会一直留在mp中，mp.size()不会减少 
			if(mp[s[l]] == 0) mp.erase(s[l]);
			l++;
		}
		r++;
	}
	
	cout << ret << endl;
	return 0;
}


#include <iostream>

typedef long long LL;

using namespace std;

const int N = 1e5 + 10;

int n,q;
LL a[N];

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> q;
	while(q--)
	{
		LL x,y;cin >> x >> y;
		//找到大于等于x且小于等于y的元素个数
		//即找到[x,y]区间
		LL l = 1,r = n;
		while(l < r)
		{
			LL mid = (l + r) / 2;
			if(a[mid] >= x)  r = mid;
			else l = mid + 1;
		}
		LL begin = l;
		if(a[begin] < x)
		{
			cout << 0 << endl; 
			continue;
		}
		l = 1,r = n;
		while(l < r)
		{
			int mid = (l + r + 1) / 2;
			if(a[mid] <= y) l = mid;
			else r = mid - 1;
		} 
		LL end = l;
		if(a[end] > y)
		{
			cout << 0 << endl; 
			continue;
		}
		cout << end - begin + 1 << endl;
    }

	return 0;
 } 

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL n,k;
LL a[N];

LL check(int mid)
{
	LL cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		cnt += a[i] / mid;
	}
	return cnt;
}

int main()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	sort(a+1,a+1+n);
	
	LL l = 1,r = a[n];
	while(l < r)
	{
		if(check(1) < k)
		{
			cout << 0 << endl;
			return 0;
		}
		
		LL mid = (l + r + 1) / 2;
		if(check(mid) >= k) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

LL n,m;
LL a[N];

LL check(int mid)
{
	LL cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		LL ans = a[i] - mid;
		if(ans > 0) cnt += ans;
	}
	return cnt;
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	sort(a+1,a+1+n);
	
	LL l = 1,r = a[n];
	
	while(l < r)
	{
		LL mid = (l + r + 1) / 2;
		if(check(mid) >= m) l = mid;
		else r = mid - 1;
	}
	
	cout << l << endl;
	
	return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

LL len, n, m;
LL a[N];

LL check(LL mid)
{
	LL cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = i + 1;
		while (j <= n && a[j] - a[i] < mid) j++;
		cnt += j - i - 1;
		i = j - 1;
	}
	return cnt;
}

int main()
{
	cin >> len >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = len;
	n++;

	LL l = 1, r = len;

	while (l < r)
	{
		LL mid = (l + r + 1) / 2;
		if (check(mid) <= m) l = mid;
		else r = mid - 1;
	}

	cout << l << endl;
	return 0;
}

