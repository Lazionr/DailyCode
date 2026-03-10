#define _CRT_SECURE_NO_WARNINGS

//map的使用
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void print(map<string, int>& mp)
{
	for (auto & x : mp)
	{
		cout << x.first << " " << x.second << endl;
	}
}

//统计一堆字符串中，每一个字符串出现的次数
void fun()
{
	string s;
	map<string, int> mp;
	for (int i = 1; i <= 10; i++)
	{
		cin >> s;
		mp[s]++;
	}
	print(mp);
}
int main()
{
	fun();

	//////创建map
	//////用来比较的关键字放前面
	////map<int, int> mp1;
	////map<string, int> mp2;
	////map<string, string> mp3;
	////map<int, vector<int>> mp4;

	////测试
	//map<string, int> mp;

	////插入
	//mp.insert({ "zhangsan",1 });
	//mp.insert({ "lisi",2 });
	//mp.insert({ "wangwu",3 });

	////print(mp);

	////operator[ ] 可以让map想数组一样使用
	//cout << mp["zhangsan"] << endl;
	//mp["zhangsan"] = 110;
	//cout << mp["zhangsan"] << endl;

	////注意事项:operator[] 有可能会向mp中插入本不想插入的元素
	////如果查找的内容不存在，便会将查找的内容插入到map中,先插入再拿值
	////插入时，第一个关键字就是[]中的内容，第二个关键字是默认的值
	////if (mp["zhaoliu"] == 4) cout << "yes" << endl;
	////else cout << "no" << endl;
	////
	////print(mp);
	//
	////因此，先进行判断是否在mp中，再进行查找
	//if (mp.count("zhaoliu") && mp["zhaoliu"] == 4) cout << "yes" << endl;
	//else cout << "no" << endl;
	//
	////删除
	//mp.erase("zhangsan");

	//print(mp);
	
	return 0;
}