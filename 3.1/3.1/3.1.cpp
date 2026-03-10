#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string a,b;

void dfs(int l1,int r1,int l2,int r2)
{
	if(l1 > r1) return;
	//1.找到根节点
	int p = l1;
	while(a[p] != b[l2]) p++;
	//2.递归处理左右子树
	dfs(l1,p-1,l2+1,p+l2-l1);
	dfs(p+1,r1,p+l2-l1+1,r2);
	cout << b[l2];
}

int main()
{
	cin >> a >> b;
	dfs(0,a.size()-1,0,b.size()-1);
	return 0;
} 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;
vector<int> edges[N];
int n;

int dfs(int u)
{
	int ret = 0;
	for (auto e : edges[u])
	{
		ret = max(ret, dfs(e));
	}
	return ret + 1;
}
int main()
{
	cin >> n;
	int u, v;
	for (int i = 2; i <= n; i++)
	{
		cin >> u >> v;
		edges[u].push_back(v);
	}
	int x, y; cin >> x >> y;
	cout << dfs(1) << endl;
	return 0;
}

