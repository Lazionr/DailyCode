#include <iostream>
#include <algorithm> 

using namespace std;

const int N = 3e4 + 10;

int w,n;
int p[N];

int main()
{
	cin >> w >> n;
	for(int i = 1;i <= n;i++) cin >> p[i];
	sort(p+1,p+1+n);
	int x = 1,y = n,cnt = 0;
	while(x <= y)
	{
		if(p[x] + p[y] <= w) x++,y--;
		else y--;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}


#include <iostream>

using namespace std;

const int N = 1010;

int m,n,k,l,d;
int x,y,p,q;
bool fx[N],fy[N];

int main()
{
	cin >> m >> n >> k >> l >> d;
	while(d--)
	{
		cin >> x >> y >> p >> q;
		if(x == p)
		{
			//横坐标相同
			int ret_y = min(y,q);
			fy[ret_y] = true;
		}
		if(y == q)
		{
			//纵坐标相同
			int ret_x = min(x,p);
			fx[ret_x] = true;
		}
	}
	int i = 1;
	while(fx[i] && i <= n)
	{
		cout << i << " ";
		i++;
	}
	cout << endl;
	int j = 1;
	while(fy[j] && j <= m)
	{
		cout << j << " ";
		j++;
	}
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;

int m,n,k,l,d;
int x,y,p,q;

struct node
{
	int index;
	int cnt;
}row[N],col[N];//行 列

//根据cnt从大到小来进行排序 
bool cmp1(node & x,node & y)
{
	return x.cnt > y.cnt;
}

//根据index从小到大来进行排序 
bool cmp2(node & x,node & y)
{
	return x.index < y.index;
}
int main()
{
	cin >> m >> n >> k >> l >> d;
	//初始化
	for(int i = 1;i <= m;i++) row[i].index = i; 
	for(int i = 1;i <= n;i++) col[i].index = i;
	
	while(d--)
	{
		cin >> x >> y >> p >> q;
		//先行后列
		if(x == p)
		{
			//行数相同
			col[min(y,q)].cnt++;
		 } 
		 if(y == q)
		 {
		 	//列数相同
		 	row[min(x,p)].cnt++;
		 }
	}
	
	//找到前k个元素
	sort(row+1,row+1+m,cmp1);
	//找到前l个元素 
	sort(col+1,col+1+n,cmp1);
	
	//对前k个元素以下标为标准排序
	sort(row+1,row+1+k,cmp2); 
	//对前l个元素以下标为标准排序
	sort(col+1,col+1+l,cmp2);
	
	for(int i = 1;i <= k;i++)
	{
		cout << row[i].index << " ";
	}
	cout << endl;
	for(int i = 1;i <= l;i++)
	{
		cout << col[i].index << " ";
	} 
	cout << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;

int n,m,k;
int a[N][N];
int col[N];

int calc(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x -= x & -x;
	}
	return cnt;
}

bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> a[i][j];
		}
	}	
	int ret = 0;
	for(int st = 0;st < (1 << n);st++)
	{
		int cnt = calc(st);
		if(cnt > k) //非法值，因为选择的行数+列数 = k 
		continue;
		memset(col,0,sizeof(col));
		int sum = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				if((st >> i) & 1) sum += a[i][j];
				else col[j] += a[i][j];
			}
		}
		//从大到小排列 
	    sort(col,col+m,cmp);
	    for(int i = 0;i < k - cnt;i++) sum += col[i];
		ret = max(ret,sum); 
	}
	cout << ret << endl;
	return 0;
} 

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;

int n,m,k;
int a[N][N];
int col[N];

int calc(int x)
{
	//统计xd的二进制中 1 出现的次数
	int ret = 0;
	while(x)
	{
		x -= x & -x;
		ret++;
	}
	return ret; 
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> a[i][j];
		}
	}
	int ret = 0;
	//1.二进制枚举选哪一行
	for(int st = 0;st < (1 << n);st++)
	{
		//统计选的行数，通过k - 行数得到列数
		int cnt = calc(st);
		if(cnt > k) continue;//此时cnt非法值 
		//每次需要清空col数组
		memset(col,0,sizeof(col)); 
		int sum = 0;
		//找到对应的行
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				//固定行数 
				if((st >> i) & 1) sum += a[i][j];
				else col[j] += a[i][j];
			}
		}
		//对col进行排序，选出前 k - cnt个
		sort(col,col+m,cmp);
		for(int i = 0;i < k - cnt;i++) sum += col[i];
		ret = max(ret,sum);
	}
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 25;

int n, m, k;
int a[N][N];
int row[N];


int calc(int x)
{
	int ret = 0;
	while (x)
	{
		x -= x & -x;
		ret++;
	}
	return ret;
}

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int ret = 0;
	//枚举列
	for (int st = 0; st < (1 << m); st++)
	{
		int sum = 0;
		int cnt = calc(st);
		if (cnt > k) continue;
		memset(row, 0, sizeof(row));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((st >> j) & 1) sum += a[i][j];
				else row[i] += a[i][j];
			}
		}

		sort(row, row + n, cmp);
		for (int i = 0; i < n; i++) sum += row[i];

		ret = max(ret, sum);
	}
	cout << ret << endl;
	return 0;
}

