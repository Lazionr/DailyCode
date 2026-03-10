#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 30;
int n;
char l[N],r[N];

void dfs(char ch)
{
	if(ch == '*') return;
	cout << ch;
	dfs(l[ch]);
	dfs(r[ch]);
}
int main()
{
	cin >> n;
	//处理第一次输入 
	char ch;cin >> ch;
	cin >> l[ch] >> r[ch];
	for(int i = 2;i <= n;i++)
	{
		char tmp;cin >> tmp;
		cin >> l[tmp] >> r[tmp];
	}
	dfs(ch);
	return 0;
}


#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n,l[N],r[N];

void dfs1(int u)
{
	cout << u << " ";
	if(l[u]) dfs1(l[u]);
	if(r[u]) dfs1(r[u]);
 }
void dfs2(int u)
{
	if(l[u]) dfs2(l[u]);
	cout << u << " ";
	if(r[u]) dfs2(r[u]);
}
void dfs3(int u)
{
	if(l[u]) dfs3(l[u]);
	if(r[u]) dfs3(r[u]);
	cout << u << " ";
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> l[i] >> r[i];
	dfs1(1);cout << endl;
	dfs2(1);cout << endl;
	dfs3(1);cout << endl;
	return 0;
} 


#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int n,l[N],r[N];
 
int dfs(int u)
{
	if(!u) return 0;
	return max(dfs(l[u]),dfs(r[u])) + 1;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> l[i] >> r[i];
	cout << dfs(1);
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

string a, b;
void dfs(int l1, int r1, int l2, int r2)
{
	if (l1 > r1) return;
	cout << b[r2];
	//在中序遍历中标记根节点位置
	int p = l1;
	while (a[p] != b[r2]) p++;
	//递归处理左右子树
	dfs(l1, p - 1, l2, p - l1 + l2 - 1);
	dfs(p + 1, r1, p + l2 - l1, r2 - 1);
}
int main()
{

	cin >> a >> b;
	dfs(0, a.size() - 1, 0, b.size() - 1);
	return 0;
}

