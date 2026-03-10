#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 10;

struct Node
{
	int a, b;
	string s;
};

void print(vector<int>& a)
{
	//1.利用for循环
	//for (int i = 0; i < a.size(); i++)
	//{
	//	cout << a[i] << endl;
	//}
	//cout << endl;

	//2.利用迭代器(auto可替换vector<int>::iterator)
	//for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//3.利用范围for
	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//1.创建 vector 
	vector<int> a1;
	//创建一个名字为 a1 的空的可变长数组，每个元素均为int类型数据
	vector<int> a2(N);
	//创建一个大小为10的可变长数组，每个元素的值默认均为0
	vector<int> a3(N, 2);
	//创建一个大小为10的可变长数组,且将每个元素均置为2
	vector<int> a4 = { 1,2,3,4,5 };
	//初始化列表的创建方式

	// <> 里面可以存放任意的数据类型，甚至是STL本身

	vector<string> a5;
	//存放字符串
	vector<Node> a6;
	//存放结构体类型
	vector<vector<int>> a7;
	//创建一个二维的可变长数组
	vector<int> a8[N];
	//创建一个大小为N的数组，里面放着N个可变长数组		

	//2.size / empty
	//print(a2);
	//print(a3);
	//print(a4);
	
	//3.begin / end
	//print(a2);
	//print(a3);
	//print(a4);
	
	//4.push_back / pop_back
	//for (int i = 0; i < 5; i++)
	//{
	//	a1.push_back(i);
	//	print(a1);
	//}

	//while (!a1.empty())
	//{
	//	print(a1);
	//	a1.pop_back();
	//}

	//5.front / back
	//cout << a4.front() << " " << a4.back();

	//6.resize
	vector<int> aa(5, 1);
	print(aa);
	//扩大为10
	aa.resize(10);
	print(aa);
	//缩小为3
	aa.resize(3);
	print(aa);

	//7.clear
	cout << aa.size() << endl;
	aa.clear();
	cout << aa.size() << endl;
	return 0;
}