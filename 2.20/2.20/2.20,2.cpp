#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	unordered_map<string,int> mp;
	int q;cin >> q;
	while(q--)
	{
		int op,sco;
		string na;
		cin >> op;
		if(op == 1)
		{
			//插入与修改
			cin >> na >> sco;
			//直接进行查找
//			if(mp.count(na))
//			{
//				//存在，直接更新成绩即可
//				mp[na] = sco;
//				cout << "OK" << endl; 
//			} 
//			else
//			{
//				//不存在，添加
//				mp.insert({na,sco});
//				cout << "OK" << endl; 
//			}
            mp[na] = sco;
            cout << "OK" << endl;
 		}
		else if(op == 2)
		{
			//查询 
			cin >> na;
			if(mp.count(na)) cout << mp[na] << endl;
			else cout << "Not found" << endl;
		}
		else if(op == 3)
		{
			//删除 
			cin >> na;
			if(mp.count(na)) 
			{
				mp.erase(na);
				cout << "Deleted successfully" << endl;
			}
			else cout << "Not found" << endl;
		}
		else
		{
			//输出数量 
			cout << mp.size() << endl;
		}
	}
	return 0;
} 

#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> mp;
	int T,n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		int x;
		while(n--)
		{
			cin >> x;
			mp.insert(x);
		}
		//遍历
	    for(auto it = mp.end();it != mp.end();it++)
	    {
	  	    cout << *it << " ";
	    } 
	    cout << endl;
	    mp.clear();
	}

	return 0;
}


#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin >> T;
	while(T--)
	{
		int n;cin >> n;
		unordered_set<int> mp;
		for(int i = 1;i <= n;i++)
		{
			int x;cin >> x;
			if(!mp.count(x))
			{
				//不在哈希表中，即第一次出现
				cout << x << " ";
				mp.insert(x); 
			}
		}
		cout << endl;
	}
	return 0;
}


#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

unordered_map<string,set<int>> mp;
//记录每个单词在哪个文章出现过 

int main()
{
	int N;cin >> N;
	for(int i = 1;i <= N;i++)
	{
		int L;cin >> L;
		while(L--)
		{
			string s;cin >> s;
			mp[s].insert(i);
		}
	}
	int M;cin >> M;
	while(M--)
	{
		string s;cin >> s;
		for(auto e : mp[s])
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
LL a[N];
unordered_map<int,int> mp;
//<数据，出现次数> 
int main()
{
	int n,c;cin >> n >> c;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
		//统计每个数字出现次数 
	}
	LL ret = 0;
	for(int i = 1;i <= n;i++)
	{
		//枚举B,统计B(a[i]) + C出现次数
		ret += mp[a[i] + c];
	}
	cout << ret << endl;
	return 0;
}
