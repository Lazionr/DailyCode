#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map> 
#include <cctype>
using namespace std;

int n,p;
map<string,int> mp;

bool check(char ch)
{
	if(isdigit(ch) || isalpha(ch)) return true;
	return false;
}
int main()
{
	cin >> n >> p;
	string a;
	int b;
	while(n--)
	{
		cin >> a >> b;
		mp[a] = b;
	}
	char ch;
	string s = "";
	long long ret = 0;
	while(scanf("%c",&ch) != EOF)
	{
		if(check(ch)) 
		{
			s += ch;
		}
		else
		{
			ret += mp[s];
			s = "";
		}
	}
	cout << ret % p << endl;
	return 0;
}


#include <iostream>

using namespace std;

const int N = 15;
int n, arr[N][N];
//定义 右 下 左 上四个方向 
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main()
{
	cin >> n;
	//定义初始值 
	int x = 1, y = 1, cnt = 1;
	int pos = 0;
	while (cnt <= n * n)
	{
		//1.将当前值填入
		arr[x][y] = cnt;
		//2.更新下一个元素
		int a = x + dx[pos];
		int b = y + dy[pos];
		//判断是否越界 
		if (a < 1 || a > n || b < 1 || b > n || arr[a][b])
		{
			//更新pos
			pos = (pos + 1) % 4;
			a = x + dx[pos];
			b = y + dy[pos];
		}
		cnt++;
	}
	//输出
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%3d", arr[i][j]);
		}
		cout << endl;
	}
	return 0;
}


