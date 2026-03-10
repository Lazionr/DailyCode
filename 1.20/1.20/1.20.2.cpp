#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

typedef struct Stu
{
	string name;
	int chinese;
	int math;
	int score;
void Init_stu()
{
	name = "zhangsan";
	math = 100;
	chinese = 90;
	score = math + chinese;
}

void Print_stu()
{
	cout << name << endl;
	cout << chinese << endl;
	cout << math << endl;
	cout << score << endl;
}
}Stu;
int main()
{
	Stu s1;
	s1.Init_stu();
    s1.Print_stu();
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

typedef struct Stu
{
	string name;
	int chinese;
	int math;
	int score;
}Stu;

//重载运算符 
ostream& operator<<(ostream& os,const Stu& s)
{
	os << s.name << endl;
	os << s.chinese << endl;
	os << s.math << endl;
	os << s.score << endl;
} 
int main()
{
	Stu s = {"zhangsan",90,100,190};
	cout << s << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[] = {1,5,3,7,9,3,8,2,6,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	for(int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	sort(arr,arr+sz);//默认升序 
	for(int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;
//bool compare(int x,int y)
//{
//	return x > y;
//}

struct Cmp
{
	bool operator()(int x,int y)
   {
	  return x > y;
   }
}cmp;
int main()
{
	int arr[] = {1,5,3,7,9,3,8,2,6,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	for(int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	//使用降序方式 
	//sort(arr,arr+sz,compare);//函数 
	sort(arr,arr+sz,cmp);//仿函数 
    for(int e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef struct S
{
	string name;
	int age;
}S;
bool cmp_by_name(S s1,S s2)
{
	return s1.name < s2.name;
}
int main()
{
	S arr[] = {{"zhangsan",20},{"lisi",25},{"wangwu",18}};
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr,arr+sz,cmp_by_name);
	for(int i = 0;i < sz;i++)
	{
		cout << arr[i].name << ":" << arr[i].age << endl;
	}
	return 0;
}


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef struct S
{
	string name;
	int age;
}S;
struct Cmp
{
	bool operator()(S s1, S s2)
	{
		return s1.age < s2.age;//升序 
	}
}cmp;
int main()
{
	S arr[] = { {"zhangsan",20},{"lisi",25},{"wangwu",18} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + sz, cmp);
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i].name << ":" << arr[i].age << endl;
	}
	return 0;
}
