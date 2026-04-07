#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 5;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

string s;
string aim = "123804765";
int n = 3;
unordered_map<string,int> dist;

void bfs()
{
	queue<string> q;
	q.push(s);
	dist[s] = 0;
	
	while(q.size())
	{	
	    auto t = q.front();q.pop();
		    
		int pos = 0;
	    while(t[pos] != '0') pos++;
	    //一维->二维 
	    int x = pos / 3,y = pos % 3;
	    
		for(int i = 0;i < 4;i++)
	    {   
		    int a = x + dx[i],b = y + dy[i];
		    if(a < 0 || a > 2 || b < 0 || b > 2) continue;

		    string tmp = t;
		    
		    //二维->一维 
		    int ans = a * 3 + b;
		    
		    swap(tmp[ans],tmp[pos]);
		    
		    if(dist.count(tmp)) continue;
			 
		    dist[tmp] = dist[t] + 1;
		
		    q.push(tmp);
		
        	if(tmp == aim) return;	
	    }
	}
}

int main()
{
	cin >> s;
	
	bfs();
	
	cout << dist[aim] << endl;
	
	return 0;
}

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 1010;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;
char a[N][N];
int dist[N][N];



void bfs()
{
	memset(dist,-1,sizeof(dist));
	queue<PII> q;
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(a[i][j] == '1') 
			{
				q.push({i,j});
				dist[i][j] = 0;
			}
		}
	}
	
	while(q.size())
	{
		auto t = q.front();q.pop();
		int i = t.first,j = t.second;
		
		for(int k = 0;k < 4;k++)
		{
			int x = i + dx[k];
			int y = j + dy[k];
			
			if(x < 1 || x > n || y < 1 || y > m) continue;
			if(dist[x][y] != -1) continue;
			
			q.push({x,y});
			dist[x][y] = dist[i][j] + 1;
		}
	}
	
}

int main()
{
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	
	bfs();
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 1010;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m,path;
int p[N][N];
int ret = 1e5;
int dist[N][N];

void bfs()
{
	memset(dist,-1,sizeof(dist));
	
	queue<PII> q;
	
	int i = 1,j = 1;
	while(j <= m) 
	{

		q.push({i,j});
		dist[i][j] = 0;
		j++;
	}
	
	while(q.size())
	{	
		auto t = q.front();q.pop();
		int a = t.first,b = t.second;
		
	
		for(int k = 0;k < 4;k++)
		{
			
			int x = a + dx[k];
			int y = b + dy[k];
			
			if(x < 1 || x > n || y < 1 || y > m) continue;
			if(dist[x][y] != -1) continue;
			
			q.push({x,y});
			path += p[x][y];
			
			if(x == n && y == m)
			{
				ret = min(ret,path);
				path = 0;
			} 
			
		}
	}
	
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> p[i][j];
		}
	}
	
	bfs();
	
	cout << ret << endl;
	return 0;
 } 


#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int n, m;
int p[N][N];
bool st[N][N];

bool bfs(int mid)
{
	if (n == 1) return true;

	memset(st, 0, sizeof(st));

	queue<PII> q;

	for (int j = 1; j <= m; j++)
	{
		q.push({ 1,j });
		st[1][j] = true;
	}

	while (q.size())
	{
		auto t = q.front(); q.pop();
		int a = t.first, b = t.second;

		for (int k = 0; k < 4; k++)
		{
			int x = a + dx[k], y = b + dy[k];
			if (x < 1 || x > n || y < 1 || y > m) continue;
			if (st[x][y]) continue;
			if (p[x][y] > mid) continue;

			st[x][y] = true;
			q.push({ x,y });
			if (x == n) return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;

	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> p[i][j];
			r = max(r, p[i][j]);
		}
	}

	while (l < r)
	{
		int mid = (l + r) / 2;
		if (bfs(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;
	return 0;
}

