#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1010;
LL f[N][N];
int n,m,q;

int main()
{
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			LL x;cin >> x;
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + x;
		}
	}
	while(q--)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >>  y2;
		cout << f[x2][y2] - f[x1-1][y2] - f[x2][y1-1] + f[x1-1][y1-1] << endl;
 	}
	return 0;
}

#include <iostream>

using namespace std;

const int N = 5010;
int a[N][N];
int f[N][N];
int n,m;

int main()
{
	cin >> n >> m;
	while(n--)
	{
		int x,y,v;
		cin >> x >> y >> v;
		x++,y++;//坐标统一向右下角移动一位，二维前缀和是从1开始的 
		a[x][y] += v;//同一个位置可能有多个目标，因此需要累加现金价值 
	}
	n = 5001;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-1] + a[i][j];
		}
	}
	int ret = 0;
	m = min(m,n);
	//如果m很大，那么就会覆盖所有矩阵，此时min之后仍能进for循环中，计算现金价值 
	//1.找到所有边长为m的正方形，枚举右下角坐标即可
	for(int x2 = m;x2 <= n;x2++)
	{
		for(int y2 = m;y2 <= n;y2++)
		{
			int x1 = x2 + 1 - m;
			int y1 = y2 + 1 - m;
			//2.计算(x1.y1)到(x2,y2)这个子矩阵和现金价值，并更新最大值
			int val = f[x2][y2] - f[x2][y1-1] - f[x1-1][y2] + f[x1-1][y1-1]; 
			ret = max(ret,val);
		}
	}
	cout << ret << endl;
	return 0;
}


#include <iostream>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
int n;
LL f[N];

int main()
{
	cin >> n;
	//预处理 
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		f[i] = f[i - 1] + x;
	}
	//当前位置之前的最小字段和 
	LL ret = -1e15;
	//当前位置之前的最小前缀和 
	LL prevmin = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, f[i] - prevmin);
		prevmin = min(prevmin, f[i]);
	}
	cout << ret << endl;
	return 0;
}

