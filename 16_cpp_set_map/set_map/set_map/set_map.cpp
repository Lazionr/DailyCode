#include <iostream>
#include <set>
#include <map>

using namespace std;

void test1()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	s1.insert(7);

	set<int>::iterator it = s1.begin();

	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<string> s2;

	s2.insert("hello");
	s2.insert("world");
	s2.insert("sort");
	s2.insert("endl");

	for (auto& e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test2()
{
	set<int> s;
	for (int i = 1; i <= 10; i++)
	{
		s.insert(i);
		cout << i << " ";
	}
	cout << endl;


	//删除最小值
	s.erase(s.begin());
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(2);
	s.erase(pos);
	s.erase(7);

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;


	//删除指定值
	int x; 
	while (cin >> x)
	{
		if (s.count(x))
		{
			s.erase(x);
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "要删除的值不存在" << endl;
		}
	}
	
}


void test3()
{
	map<string, int> mp({ { "hello",1 }, { "name" , 2 } });
	for (auto& e : mp)
	{
		cout << e.first << ":" << e.second << endl;
	}
	cout << endl; 
}


int main()
{
	//test1();
	//test2();

	test3();

	return 0;
}