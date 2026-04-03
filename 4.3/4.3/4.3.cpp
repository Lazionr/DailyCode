#include <iostream>
#include <cstring>

using namespace std;

const int N = 15;

int i,j;
int ret = 1e5;
int f[N][N];

int dfs(int i,int j)
{
	
	if(f[i][j] != -1) return f[i][j];
	
	if(i == j)	return f[i][j] = ret;
		
	int tmp = dfs(i+1,j) < dfs(i-1,j) ? dfs(i+1,j) : dfs(i-1,j);
	
	ret = min(tmp,dfs(2*i,j));
	return f[i][j] = ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		memset(f,-1,sizeof(f));
		
		cin >> i >> j;
		
		cout << dfs(i,j) << endl;
		
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int x, y;
int n = 1e5;
int dist[N];

void bfs()
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		int a = t + 1, b = t - 1, c = 2 * t;

		if (a <= n && dist[a] == -1)
		{
			dist[a] = dist[t] + 1;
			q.push(a);
		}

		if (b > 0 && dist[b] == -1)
		{
			dist[b] = dist[t] + 1;
			q.push(b);
		}

		if (c <= n && dist[c] == -1)
		{
			dist[c] = dist[t] + 1;
			q.push(c);
		}

		if (a == y || b == y || c == y) return;
	}

}

int main()
{
	int T; cin >> T;
	while (T--)
	{
		memset(dist, -1, sizeof(dist));

		cin >> x >> y;

		bfs();

		cout << dist[y] << endl;
	}
	return 0;
}