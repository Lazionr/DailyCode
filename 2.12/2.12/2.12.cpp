#define _CRT_SECURE_NO_WARNINGS

//set/multiset的使用

#include <iostream>
#include <set>

using namespace std;

int a[] = { 10,60,20,70,80,30,90,40,100,50 };

int main()
{
	//set<int> mp1;
	//set<string> mp2;

	set<int> mp;

	//插入
	for (auto e : a)
	{
		mp.insert(e); 
	}

	//遍历set
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	////查找
	//if (mp.count(1)) cout << "1" << endl;
	//if (mp.count(10)) cout << "10" << endl;
	//if (mp.count(30)) cout << "30" << endl;
	//if (mp.count(99)) cout << "99" << endl;

	//mp.erase(10);
	//mp.erase(30);

	//if (mp.count(10)) cout << "10" << endl;
	//else cout << "no : 10" << endl;
	//if (mp.count(30)) cout << "30" << endl;
	//else cout << "no : 30" << endl;

	//lower_bound/upper_bound
	auto x = mp.lower_bound(20);
	auto y = mp.upper_bound(20);
	cout << *x << " " << *y << endl;

	return 0;
}