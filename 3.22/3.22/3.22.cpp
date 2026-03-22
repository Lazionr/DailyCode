#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2510;

int n,l;

struct node
{
	int l;
	int r;
}a[N];

struct num
{
	int sp;
	int cv;
}b[N];

bool cmp1(node& x,node& y)
{
	return x.l < x.r;
}

bool cmp2(num& x,num& y)
{
	return x.sp < y.sp;
}


int main()
{
	cin >> n >> l;
	for(int i = 1;i <= n;i++) cin >> a[i].l >> a[i].r;
	for(int i = 1;i <= l;i++) cin >> b[i].sp >> b[i].cv;
	
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+l,cmp2);
	
	int ret = 0;
	
	int i = 1,j = 1;
	
	while(i <= n && j <= l)
	{
		int left = a[i].l;
		int right = a[i].r;
		if(b[j].sp >= left && b[j].sp <= right && b[j].cv >= 1)
		{
			ret++;
			b[j].cv--;
		}
		if(b[j].cv == 0) j++;
		i++;
	}
	
	cout << ret << endl;	
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2510;

int n,m;
struct node
{
	int x;//左端点 阳光强度 
	int y;//右端点 数量 
}a[N],b[N];

bool cmp(node& x,node& y)
{
	 return x.x > y.x;
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
	for(int i = 1;i <= m;i++) cin >> b[i].x >> b[i].y;
	
	//左端点从大到小，阳光强度从大到小 
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	
	int ret = 0;
	for(int i = 1;i <= n;i++)
	{
		int l = a[i].x;
		int r = a[i].y;
		for(int j = 1;j <= m;j++)
		{
			int w = b[j].x, &cnt = b[j].y;
			if(cnt == 0) continue;
		    if(w < l) break;
		    if(w > r)continue;
		    //此时l <= w <= r
			ret++;
			cnt--; 
			//当这一瓶防晒霜分配给当前奶牛后，继续下一头奶牛，直接break
			break;
		}
		 
	}
	cout << ret << endl;
	return 0;
 } 


#include <iostream>

using namespace std;

typedef long long LL;

LL a,b,p;

LL qpow(LL a,LL b,LL c)
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}
int main()
{
	cin >> a >> b >> p;
	printf("%lld^%lld mod %lld=%lld",a,b,p,qpow(a,b,p));
	return 0;
} 

#include <iostream>

using namespace std;

typedef long long LL;

LL a, b, p;

LL qmul(LL a, LL b, LL p)
{
	LL ret = 0;
	while (b)
	{
		if (b & 1) ret = (ret + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ret;
}
int main()
{
	cin >> a >> b >> p;
	cout << qmul(a, b, p) << endl;
	return 0;
}

