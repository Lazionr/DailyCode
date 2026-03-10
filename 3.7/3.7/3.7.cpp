#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int x,y;
int day[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	cin >> x >> y;
	//枚举月日对应的组合，拼凑回文日期
	int cnt = 0;
	for(int i = 1;i <= 12;i++)
	{
		for(int j = 1;j <= day[i];j++)
		{
			int k = j % 10 * 1000 + j / 10 % 10 * 100 + i % 10 * 10 + i / 10;
			int num = k * 10000 + i * 100 + j;
			if(x <= num && num <= y) cnt++;
		}
	} 
	cout << cnt; 
	return 0;
}


#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int n,a[N],b[N];

bool check()
{
	//根据当前a[1]的值进行判断是否合法
	for(int i = 1;i <= n;i++)
	{
		a[i+1] = b[i]- a[i-1] - a[i];
		if((a[i+1] < 0) || a[i+1] > 1) return false;
	} 
	return a[n+1] == 0;
}
int main()
{
	cin >> n;
	int cnt = 0; 
	for(int i = 1;i <= n;i++) cin >> b[i];
	//枚举a数组第一个格子是否有雷，判断是否合法即可
	//假设没雷 
	if(check()) cnt++;
	//假设有雷 
	a[1] = 1;
	if(check()) cnt++;
	cout << cnt;
	return 0;
}

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
long long sum[N];//存放当前位置之前所有元素的和 
int n,m; 

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
    	sum[i] = sum[i-1] + a[i];
	}
    while(m--)
    {
    	int l,r;cin >> l >> r;
    	cout << sum[r] - sum[l - 1] << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

typedef long long LL;

const int N = 2e3 + 10;
LL f[N];//前缀和 
int n,x;

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		f[i] = f[i-1] + x;
	}
	LL prevmin = 0;
	LL ret = -1e10;
	for(int i = 1;i <= n;i++)
	{
		ret = max(ret,f[i] - prevmin);
		prevmin = min(f[i],premvin);
	}
	return 0;
}


#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;
LL f[N];
int n,x;

int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x;
		f[i] = f[i-1] + x;
	}
	LL ret = -1e10;
	//当前位置之前的最小子段和 
	LL prevmin = 0;
	for(int i = 1;i <= n;i++)
	{
		ret = max(ret,f[i] - prevmin);
		prevmin = min(prevmin,f[i]);
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL f[N][N];

int main()
{
	ios_sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> x;
			f[i][j] = f[i][j - 1] + x;
		}
	}
	LL ret = 0;
	for (int i = 1; i <= q; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		LL += f[]
	}
	return 0;
}
