#include <iostream>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n,a[N];

int tmp[N];

LL merge(int l,int r)
{
	if(l >= r) return 0;
	
	LL ret = 0;
	
	LL mid = (l + r) / 2;
	ret += merge(l,mid);
	ret += merge(mid+1,r);
	
	//合并左右区间
	int cur1 = l,cur2 = mid + 1,cur = l;
	while(cur1 <= mid && cur2 <= r)
	{
		if(a[cur1] <= a[cur2])
		{
			tmp[cur++] = a[cur1++];
		}
		else
		{
			ret += mid - cur1 + 1;
			tmp[cur++] = a[cur2++]; 
		}
	} 
	
	while(cur1 <= mid) tmp[cur++] = a[cur1++];
	while(cur2 <= r) tmp[cur++] = a[cur2++];
	
	for(int i = l;i <= r;i++)  a[i] = tmp[i];
	 
	return ret;
}


int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cout << merge(1,n) << endl;
	return 0;
}

#include <iostream>
#include <ctime>
using namespace std;

const int N = 5e6 + 10;

int n,k;
int a[N];

int get_random(int left,int right)
{
	return a[rand() % (right - left + 1) + left];
}

int quick_sort(int left,int right ,int k)
{
	if(left >= right) return a[left];
	
	int p = get_random(left,right);
	
	int l = left - 1,r = right + 1,cur = left;
	while(cur < r)
	{
		if(a[cur] < p) swap(a[cur++],a[++l]);
		else if(a[cur] == p) cur++;
		else swap(a[cur],a[--r]);
	}
	
	//分完后的三个区间
	//[left,l][l+1,r-1][r,right] 
	int a = l - left + 1,b = r - 1 - l,c = right - r + 1;
	if(k <= a) return quick_sort(left,l,k);
	else if(k <= a + b) return p;
	else return quick_sort(r,right,k-a-b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
  srand(time(0));
	cin >> n >> k;
	k++;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	cout << quick_sort(1,n,k) << endl;
	return 0;
 } 


#include <iostream>
#include <queue>
using namespace std;

const int N = 5e6 + 10;

int n, k;
priority_queue<int> heap;

int main()
{
	cin >> n >> k;
	k++;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		heap.push(x);
		if (heap.size() > k) heap.pop();
	}
	cout << heap.top() << endl;
	return 0;
}
