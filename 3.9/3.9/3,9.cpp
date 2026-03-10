#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e5 + 10; 
typedef long long LL;
LL f[N]; 
int n,m;
int l,r,k;

int  main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		LL x;cin >> x;
		//根据差分数组的性质直接进行创建
		f[i] += x;
		f[i+1] -= x; 
	}
	while(m--)
	{
		cin >> l >> r >> k;
		f[l] += k;
		f[r+1] -= k;
	}
	//进行前缀和运算即可 
	for(int i = 1;i <= n;i++)
	{
		f[i] = f[i-1] + f[i];
		cout << f[i] << " "; 
	}
	return 0;
}

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n,m;
LL f[N];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		LL x;cin >> x;
		//利用差分性质直接创建差分数组
		f[i] += x;
		f[i+1] -= x; 
	}
	while(m--)
	{
		int l,r;
		LL k;
		cin >> l >> r >> k;
		f[l] += k;
		f[r+1] -= k;
	} 
	//前缀和恢复原始数组
	for(int i = 1;i <= n;i++)
	{
		f[i] = f[i-1] + f[i];
		//f[i-1]即为处理后数组的值，加上当前的差分数组，即可得到f[i]的值 
		cout << f[i] << " ";
	} 
	return 0;
}

#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n,m;
int f[N];//统计每一段区间的经过次数 

int main()
{
	cin >> n >> m;
	//预处理 
	int x;cin >> x;
	for(int i = 2;i <= m;i++)
	{
		int y;cin >> y;
		//表示x->y路段
		if(x < y) 
		{
			f[x]++;
			f[y]--;
	    }
	    else
	    {
	    	f[y]++;;
	    	f[x]--;
		}
		x = y;
	}
	//恢复数组
	for(int i = 1;i <= n;i++) f[i] += f[i-1]; 
	LL ret = 0; 
	for(int i = 1;i < n;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		//找出每一段x->y路线的最小值
		ret += min(f[i] * a ,c + b * f[i]); 
	}
	cout << ret << endl;
	return 0;
} 

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n, m;
int f[N];//统计经过次数 

int main()
{
	cin >> n >> m;

	//处理x->y之间路线的经过次数，最后一个是y-1车站
	//第i段铁路连接城市i 和 i+1
	//单独记录第一个车站，然后表示x->y,最终执行x = y 
	int x; cin >> x;
	for (int i = 2; i <= m; i++)
	{
		int y; cin >> y;
		if (x < y)
		{
			//由前面站点到后面站站点 
			f[x]++;
			f[y]--;
		}
		else
		{
			f[y]++;
			f[x]--;
		}
		x = y;
	}
	//前缀和恢复数组
	for (int i = 1; i <= n; i++) f[i] += f[i - 1];
	LL ret = 0;
	//找到各个站点的最小值
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ret += min(a * f[i], b * f[i] + c);
	}
	cout << ret << endl;
	return 0;
}

