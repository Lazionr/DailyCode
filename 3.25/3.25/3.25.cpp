#include <iostream>

using namespace std;

int n;
char a,b,c;

void dfs(int x,char begin,char tmp,char end)
{
	if(x == 0) return;
	dfs(x-1,begin,end,tmp);
	printf("%c->%d->%c\n",begin,x,end);
	dfs(x-1,tmp,begin,end);
}
int main()
{
	cin >> n >> a >> b >> c;
	
	dfs(n,a,c,b);
	
	return 0;
}

#include <iostream>

using namespace std;

const int N = 15;

int n = 13,m = 4;

int a[14][5];
int cnt[N];

void dfs(int x)
{
	if(x == 13) return;
	int t = a[x][cnt[x]];
	cnt[x]--;
	dfs(t);
}
int main()
{
	for(int i = 1;i <= n;i++)
	{
		cnt[i] = 4;
		for(int j = 1;j <= m;j++)
		{
			char ch; cin >> ch;
			if(ch >= '2' && ch <= '9') ch -= '0';
			else if(ch == 'A') ch = 1;
			else if(ch == 'J') ch = 11;
			else if(ch == 'Q') ch = 12;
			else if(ch == 'K') ch = 13;
			else ch = 10;
			a[i][j] = ch;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		dfs(a[13][i]);
	}
	int ret = 0;
	for(int i = 1;i <= n;i++)
	{
		if(!cnt[i]) ret++;
	}
	cout << ret << endl;
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

const int N = (1 << 11);

int n;
int f[N];
string s;

void dfs(int l,int r)
{
	if(l > r) return;
   	int mid = (l + r) / 2;
   	dfs(l,mid);
   	dfs(mid+1,r);
   	
   	int key = 0;
   	if(l == 0) key = f[r];
   	else key = f[r] - f[l-1];
   	if() cout << 'I';
   	else if(key == 0) cout << 'B';
   	else cout << 'F';
}
int main()
{
	cin >> n >> s;
	int len = s.size();
	
	for(int i = 0;i < len;i++)
	{
		int t = s[i] - '0';
		if(i == 0) f[i] = t;
		else f[i] = f[i-1] + t;
	}
	dfs(0,len - 1);
	return 0;
}


#include <iostream>

using namespace std;

const int N = 11;

int n;
int f[1 << N];

void dfs(int l,int r)
{
	if(l > r) return;
	
	//1.判断类型
	char ret;
	int sum = f[r] - f[l - 1];
	if(sum == r - l + 1) ret = 'I';
	else if(sum == 0) ret = 'B';
	else ret = 'F';
	
	if(l == r)
	{
		//当l == r时，mid == l == r，此时依旧会dfs(l,mid)，死循环 
		cout << ret;
		return;
	} 
	//2.划分左右序列 
	int mid = (l + r) / 2;
	
	dfs(l,mid);
	dfs(mid+1,r);
	
	cout << ret;
}
int main()
{
	cin >> n;
	n = (1 << n);
	//前缀和预处理 
	for(int i = 1;i <= n;i++)
	{
		char ch;cin >> ch;
		int t = 0;
		if(ch == '1') t = 1;
		
		f[i] = f[i-1] + t;
	}
	dfs(1,n);
	return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

int n;


int main()
{
    // 在这里编写你的代码
    cin >> n;
    int ret = 1e5 + 10;
    for(int i = 1;i <= n;i++)
    {
        int x;cin >> x;
        ret = min(ret,x);
    }
    cout << ret << endl;
    return 0;
}

