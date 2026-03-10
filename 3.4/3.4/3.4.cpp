#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//
//using namespace std;
//
//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//const int N = 15;
//int n,arr[N][N],pos;
//
//int main()
//{
//	cin >> n;
//	//1.初始化
//	int a = 1,b = 1,cnt = 1;
//	while(cnt <= n * n)
//	{
//		arr[a][b] = cnt;
//		int x = a + dx[pos];
//		int y = b + dy[pos];
//		//越界
//		if(x < 1 || x > n || y < 1 || y > n || arr[x][y])
//		{
//			pos = (pos + 1) % 4;
//			x = a + dx[pos];
//			y = b + dy[pos];
//		}
//		a = x;
//		b = y;
//		cnt++; 
//	}
//	//2.输出
//	for(int i = 1;i <= n;i++)
//	{
//		for(int j = 1;j <= n;j++)
//		{
//			printf("%3d",arr[i][j]);
//		}
//		cout << endl;
//	 } 
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

int p1, p2, p3;
string s, str, tmp, ans, res;

bool check(char p, char q)
{
	if ((isdigit(p) && isdigit(q)) || (islower(p) && islower(q)))
	{
		return (p < q);
	}
	return false;
}
string func_p3(string key)
{
	if (p3 == 1)
	{
		//顺序 
		return key;
	}
	//逆序
	//reverse无返回值 
	reverse(key.begin(), key.end());
	return key;
}
string ret(char p, char q)
{
	string key = "";
	//填充的起始字符 
	char start = p + 1;
	//填充的结束字符
	char end = q - 1;

	if (start > end) return "";
	if (p1 == 1)
	{
		//填充小写
		for (char c = start; c <= end; c++)
		{
			//重复p2次,不能直接修改p2,全局变量 
			for (int i = 1; i <= p2; i++)
			{
				key += c;
			}
		}
	}
	else if (p1 == 2)
	{
		//填充大写
		for (char c = start; c <= end; c++)
		{
			//重复p2次,不能直接修改p2,全局变量 
			for (int i = 1; i <= p2; i++)
			{
				key += toupper(c);
			}
		}
	}
	else
	{
		//填充符号
		for (char c = start; c <= end; c++)
		{
			//重复p2次,不能直接修改p2,全局变量 
			for (int i = 1; i <= p2; i++)
			{
				key += '*';
			}
		}
	}
	return func_p3(key);
}
int main()
{
	cin >> p1 >> p2 >> p3;
	cin >> s;
	//定义两个指针
	int p = 0, q = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			p = i - 1;
			q = i + 1;
			if (p < 0 || q >= s.size())
			{
				tmp += '-';
				continue;
			}
			if (s[p] == s[q])
			{
				res += tmp;
				res += '-';
				tmp = "";
				continue;
			}
			if (check(s[p], s[q]))
			{
				if (s[p] + 1 == s[q])
				{
					tmp.erase(remove(tmp.begin(), tmp.end(), '-'), tmp.end());
					res += tmp;
					tmp = "";
					continue;
				}
				//ans为重复子串 
				ans = ret(s[p], s[q]);
				tmp.erase(remove(tmp.begin(), tmp.end(), '-'), tmp.end());
				res = res + tmp + ans;
				tmp = "";
			}
			else
			{
				tmp += '-';
			}
		}
		else
		{
			tmp += s[i];
		}

	}
	res += tmp;
	cout << res;
	return 0;
}
