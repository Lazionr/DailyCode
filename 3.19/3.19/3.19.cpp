#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;

struct node
{
	int t;
	int d;
}a[N];

bool cmp(node& x,node& y)
{
	return y.d * x.t < x.d * y.t;
}
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i].t >> a[i].d;
	
	sort(a,a+n,cmp);
	
	LL ret = 0;
	LL time = 0;
	for(int i = 0;i < n;i++)
	{
		ret += a[i].d * time;
		time += 2 * a[i].t;
	}
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 5e4 + 10;

int n;

struct node
{
	int w;
	int s;
}a[N];

bool cmp(node& x, node& y)
{
	return  x.s + x.w < y.s + y.w;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].s;

	sort(a, a + n, cmp);

	LL sum = 0;
	LL ret = -1e18;
	for (int i = 0; i < n; i++)
	{
		ret = max(ret, sum - a[i].s);
		sum += a[i].w;
	}
	cout << ret << endl;
	return 0;
}
