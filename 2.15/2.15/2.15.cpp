#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

int n,p;
map<string,int> mp;

bool check(char ch)
{
	if(isdigit(ch) || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	return true;
	else return false;
}
int main()
{
	string a;
	int b;
	cin >> n >> p;
	while(n--)
	{
		cin >> a >> b;
		mp[a] = b;
	}
	//输入完成后，通过mp[ ]++ 来计算出现次数
	char ch;
	long long ret = 0;
	string tmp = "";
	while(scanf("%c",&ch) != EOF)
	{
		if(check(ch))
		{
			//正常字符
			tmp += ch; 
		}
		else
		{
			//分隔符
			ret += mp[tmp];
			tmp = "";
		} 
	}
	cout << ret % p << endl;
	return 0;
} 


#include <iostream>
#include <set>
#include <cstdlib>
#include <algorithm> 
using namespace std;

const int INF = 1e7 + 10;
set<int> mp;
int n;

int main()
{
	//处理第一天
	cin >> n;
	int ret; cin >> ret;
	mp.insert(ret);
	//左右护法
	mp.insert(-INF);
	mp.insert(INF);
	
	//处理剩下天数
	for(int i = 2;i <= n;i++)
	{
		int x; cin >> x;
		//1.利用lower_bound找到大于等于x的最小值
		auto it = mp.lower_bound(x);
		//2.有序，找到小于等于x的最大值，就在*it之前 
		auto tmp = it;
		tmp--;
		
		if(*it == x) continue;
		ret += min(abs(*it - x),abs(*tmp - x));
		mp.insert(x);
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long LL;
const LL INF = 1e10 + 10;
set<LL> mp;

int main()
{
	int m; cin >> m;
	mp.insert(-INF);
	mp.insert(INF);
	while (m--)
	{
		LL op, len;
		cin >> op >> len;
		if (op == 1)
		{
			//进货
			if (mp.count(len))
			{
				cout << "Already Exist" << endl;
			}
			else mp.insert(len);
		}
		else
		{
			//出货
			//判空
			if (mp.size() == 2) cout << "Empty" << endl;
			else
			{
				if (mp.count(len))
				{
					//存在刚好长度的 
					cout << len << endl;
					mp.erase(len);
				}
				else
				{
					//找到长度最接近的
					//1.找到大于len的最小值
					auto it = mp.upper_bound(len);
					//2.利用迭代器找到小于len的最大值
					auto tmp = it; tmp--;
					// *it 不会等于 *tmp

					LL n1 = llabs(*it - len);
					LL n2 = llabs(*tmp - len);

					if (n1 < n2)
					{
						cout << *it << endl;
						mp.erase(it);
					}
					else
					{
						cout << *tmp << endl;
						mp.erase(tmp);
					}
				}
			}
		}
	}
	return 0;
}

