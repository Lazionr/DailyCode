#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Max(int a,int b)
{
	return a > b ? a : b;
 } 
int main()
{
	//比较两个数的最大值
	int x,y;
	cin >> x >> y;
	int r = Max(x,y);
	cout << "最大值为：" << r << endl;
	 
	return 0;
}


#include <iostream>
#include <utility>
using namespace std;
//Swap(int& x,int& y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
int main()
{
	int a = 10;
	int b = 20;
//	int& r1 = a;
//	int& r2 = a;
//	cout << a << endl;
//	cout << r1 << endl;
//	cout << r2 << endl;
//	r1 = b;
//	cout << r1 << endl;
//    cout << &a << endl;
    cout << a << " " << b << endl;
    swap(a,b);
    cout << a << " " << b << endl;
	return 0;
}


#include <iostream>
#include <utility>
using namespace std;
int main()
{
	int arr1[4] = {0};
	int arr2[4] = {10,20,30,40};
	swap(arr1,arr2);
	for(int e : arr1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#include<iostream>
#include<ctime>
using namespace std;
//定义全局字符串s 
string s("hello world");
void TestFunc1(string s) {}
void TestFunc2(string& s) {}
void Test()
{
// 以值作为函数参数
size_t begin1 = clock();
for (size_t i = 0; i < 10000000; ++i)
{
TestFunc1(s);
}
size_t end1 = clock();
// 以引?作为函数参数
 
size_t begin2 = clock();
for (size_t i = 0; i < 10000000; ++i)
{
TestFunc2(s);
}
size_t end2 = clock();
// 分别计算两个函数运?结束后的时间
cout << "TestFunc1(string)-time:" << end1 - begin1 << endl;
cout << "TestFunc2(string&)-time:" << end2 - begin2 << endl;
}
int main() 
{
Test();
return 0;
}

#include <iostream>
using namespace std;
int cacl(int x,char c,int y)
{
	switch(c)
    {   
	    case '+':
		    return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
		    return x / y;
		case '%' :
		    return x % y;	
		
    }
}
int main()
{
	int a,b;
	char c;
	cin >> a >> c >> b;
	//cin在输入时，遇到空格会结束，继续往后读取时，会跳过空格 
	int ret = cacl(a,c,b);
	cout << ret << endl;
	return 0;
} 

#include <iostream>
using namespace std;
int max(int a,int b,int c)
{
	int r = a > b ? a : b;
	if(r > c)
	return r;
	else
	return c;
}
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
  	int m = max(a,b,c);
  	cout << m << endl;
	return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;
int Max(int a,int b,int c)
{
	int r = a > b ? a : b;
	return r > c ? r : c;
}
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
  	float m = Max(a,b,c) * 1.0 / (Max(a+b,b,c) * Max(a,b,b+c));
  	cout << fixed << setprecision(3) << m << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp_str(string str1,string str2)
{
	return str1.size() < str2.size();
}
int main()
{
	string s1 = "abcdef";
	string s2 = "bbq";
	//按照字符串长度来比较大小 
	cout << max(s1,s2,cmp_str) << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int _max;
	int _min;
	cin >> n;
	int k,t;
	cin >> k;
	_max = k;//假设k为最大值，给出基准 
	_min = k;//假设k为最小值，给出基准
	for(int i = 1;i < n;i++)
	{
		cin >> t;
		_max = max(_max,t);
		_min = min(_min,t);
	} 
	cout << _max - _min << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int _max = 0;
	int _min = 100;
	cin >> n;
	int t;
	for(int i = 0;i < n;i++)
	{
		cin >> t;
		_max = max(_max,t);
		_min = min(_min,t);
	} 
	cout << _max - _min << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int N = 110;
const int M = 30;
int arr[N][M];
int main()
{
	int n,m;
	cin >> n >> m;
	double _ret = 0.0;
	for(int i = 0;i < n;i++)
	{
		int _max = 0;
	    int _min = 10;
		int sum = 0;
		double ret = 0;
		for(int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			_max = max(_max,arr[i][j]);
			_min = min(_min,arr[i][j]);
			sum += arr[i][j];
		}
		sum -= (_max + _min);
		ret = sum * 1.0 / (m-2);
		_ret = max(_ret,ret);
	} 
	cout << fixed << setprecision(2) << _ret << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	int n,m,s;
	cin >> n >> m;
	double top = 0;
	double r = 0;
	for(int i = 0;i < n;i++)
	{
		//计算一名学生的成绩
		int _max = 0;
		int _min = 10; 
		int sum = 0;
		for(int j = 0;j < m;j++)
		{
			cin >> s;
			sum += s; 
			_max = max(_max,s);
			_min = min(_min,s);
		}
		r = (sum - _max - _min) * 1.0/ (m - 2);
		top = max(top,r);
	}
	cout << fixed << setprecision(2) << top << endl;
	return 0;
}

#include <iostream>
using namespace std;

void func(int n)
{
	for(int i = 2;i <= n;i++)
	{
		//产生2-n之间的数 
	     int sum = 0;
	     for(int j = 1;j < i;j++)
	   {
		  //寻找因数
		   if(i % j == 0)
		   {
		 	sum += j;
		   }
	    }     
	if(sum == i)
	cout << sum << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	func(n);
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int cnt = 0;
	while(n--)
	{
		string s;
	    cin >> s;
	    float f;
	    cin >> f;
	    int m;
	    cin >> m;
	    if(f >= 37.5 && m == 1)
	    {
	    	cout << s << endl;
	    	cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
bool is_primer(int x)
{
	if(x < 2)
	return false;
	else
	{
		for(int j = 2;j <= sqrt(x);j++)
		{
			if(x % j == 0)
			{
				//非素数
				return false; 
			}
		}
		return true;
	}
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 2;i <= n;i++)
	{
		if(is_primer(i))
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
const int N = 5050;
int arr[N];
bool is_primer(int x)
{
	if(x < 2)
	return false;
	else
	{
	   	for(int j = 2;j <= sqrt(x);j++)
 	   {
	 	  if(x % j == 0)
		  {
			  return false;
		  }
	   }
	   return true;	
	}
}
int main()
{
	int n;
	cin >> n;
	int m = 0;
	for(int i = 2;i <= n;i++)
	{
		//找到1-n之间的所有素数
		if(is_primer(i))
		{
			arr[m++] = i; 
		} 
	}
	int flag = 0;//假设非空 
	for(int j = 1;j < m;j++)
	{
		if(arr[j] - arr[j-1] == 2)
		{
			flag = 1;
			cout << arr[j-1] << " " << arr[j] << endl;
		}
	}
	if(flag == 0)
	cout << "empty" << endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
bool is_primer(int x)
{
	if(x < 2)
	   return false;
	else
	{
	   	for(int j = 2;j <= sqrt(x);j++)
 	   {
	 	  if(x % j == 0)
		  {
			  return false;
		  }
	   }
	   return true;	
	}
}
int main()
{
	int n;
	cin >> n;
	int flag = 0;
	for(int i = 2;i + 2 <= n;i++)
	{
		if(is_primer(i) && is_primer(i+2))
		{
			cout << i << " " << i+2 << endl;
			flag++;
		} 
	}
	if(flag == 0)
	cout << "empty" << endl;
	return 0;
}


#include <iostream>
#include <cmath>
using namespace std;
bool is_primer(int x)
{
	if(x < 2)
	    return false;
	else if(x == 2)
	    return true;
	else if(x % 2 == 0)//排除偶数 
	    return false; 
	else
	{
	   	for(int j = 3;j <= sqrt(x);j += 2)//只检查奇数因数 
 	   {
	 	  if(x % j == 0)
		  {
			  return false;
		  }
	   }
	   return true;	
	}
}
int main()
{
	int n;
	cin >> n;
	int flag = 0;
	for(int i = 2;i + 2 <= n;i++)
	{
		if(is_primer(i) && is_primer(i+2))
		{
			cout << i << " " << i+2 << endl;
			flag++;
		} 
	}
	if(flag == 0)
	cout << "empty" << endl;
	return 0;
}

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
bool is_primer(int n)
{
	if(n < 2)
	return false;
	else if(n == 2)
	return true;
	else if(n % 2 == 0)
	return false;
	else
	{
		for(int j = 3;j <= sqrt(n);j += 2)
		{
			if(n % j == 0)
			return false;
		}
		return true;
	}
}
// bool func(string s)
// {
// 	int left = 0;
// 	int right = s.size() - 1;
// 	while(left < right)
// 	{
// 		if(s[left++] != s[right--])
// 		return false;
// 	}
// 	return true;
// }
bool func(string s)
{
	string t = s;
	reverse(s.begin(),s.end());
	if(s == t)
	return true;
	else
	return false;
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 11;i <= n;i++)
	{
		if(is_primer(i) && func(to_string(i)))
			cnt++;
	}
	cout << cnt << endl;
} 

#include <iostream>
#include <cmath>
using namespace std;
bool is_primer(int n)
{
	if(n < 2)
	return false;
	else if(n == 2)
	return true;
	else if(n % 2 == 0)
	return false;
	else
	{
		for(int j = 3;j <= sqrt(n);j += 2)
		{
			if(n % j == 0)
			return false;
		}
		return true;
	}
}
bool func(int n)
{
	int ret = 0;
	int tmp = n;
	while(tmp)
	{
		ret = ret * 10 + tmp % 10;
		tmp /= 10;
	}
	if(ret == n)
	return true;
	else
	return false;
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 11;i <= n;i++)
	{
		if(is_primer(i) && func(i))
			cnt++;
	}
	cout << cnt << endl;
} 

#include <iostream>
#include <cmath>
using namespace std;
bool is_primer(int n)
{
	if(n < 2)
	return false;
	else if(n == 2)
	return true;
	else if(n % 2 == 0)
	return false;
	else
	{
		for(int i = 3;i <= sqrt(n);i += 2)
		{
			if(n % i == 0)
			return false;
		}
		return true;
	}
}
int instead(int x)
{
	int ret = 0;
	while(x)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}
int main()
{
	int m,n;
	cin >> m >> n;
	int flag = 0;
	int cnt = 0;
	for(int i = m;i <= n;i++)
	{
		if(is_primer(i) && is_primer(instead(i)))
		{
			flag++;
			if(cnt == 0)
			{
				cout << i;
				cnt++;
			}
			else
			{
				cout << ',' << i;
			}
		}
	}
	if(flag == 0)
	cout << "No" << endl;
	return 0;
}

//对输出逻辑进行优化
//同时利用reverse函数进行反转 
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
bool is_primer(int n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		for (int i = 3; i <= sqrt(n); i += 2)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
}
int instead(int x)
{
	string s = to_string(x);
	reverse(s.begin(), s.end());

	return stoi(s);
}
int main()
{
	int m, n;
	cin >> m >> n;
	int flag = 0;
	for (int i = m; i <= n; i++)
	{
		if (is_primer(i) && is_primer(instead(i)))
		{
			if (flag)
				cout << ',';
			cout << i;
			flag++;
		}
	}
	if (flag == 0)
		cout << "No" << endl;
	return 0;
}
