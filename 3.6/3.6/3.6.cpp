#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int N = 1e4 + 10;
int a[N],b[N],g[N],k[N];
int n,x,y;

int check()
{
	//逆序枚举即可
	for(int i = n;i >= 1;i--)
	{
		if((x >= a[i]) && (x <= a[i] + g[i]) && (y >= b[i]) && (y <= b[i] + k[i]))
		return i;
	} 
	return -1; 
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> g[i] >> k[i];
	cin >> x >> y;
	
	cout << check();
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

int n1,n2;

bool is_valid_date(int y,int m,int d)
{
	if(d == 0 || d > 31 || m == 0 || m > 12) return false;
	if(m == 2) 
	{
		if((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
		{
			//闰年
			if(d > 29) return false; 
		}
		else
		{
			//非闰年
			if(d > 28) return false; 
		}
	}
	else if(m == 4 || m == 6 || m == 9 || m == 11)
	{
		if(d == 31) return false;
	}
	return true;
}
bool check1(int n)
{
	int y = n;
	//得到day 
	int d = y % 100;
	y /= 100;
	//得到month
	int m = y % 100;
	y /= 100;
	if(is_valid_date(y,m,d))
	{
		//判断是否回文
	    //ret和tmp比较  
	    int ret1 = 0;
	    int tmp = y;
	    while(tmp > 0)
	    {
		   ret1 = ret1 * 10 + tmp % 10;
		   tmp /= 10;
	    }
	    int ret2 = m * 100 + d;
	    return ret1 == ret2;
	}
	return false;
} 
bool check2(int year,int month,int day)
{
	if(is_valid_date(year,month,day))
	{
		//找到年份的回文数字 
	    int tmp = 0;
	    while(year > 0)
	    {
		   tmp = tmp * 10 + year % 10;
	       year /= 10;
	    }
	    //此时tmp已经是回文数字 
	    int md = month * 100 + day;
	    return tmp == md;
	}
}
void func1()
{
	int cnt = 0;
	for(int i = n1;i <= n2;i++)
	{
		if(check1(i)) cnt++;
	}
	cout << cnt;
} 

void func2()
{
	int cnt = 0;
	//一年最多只会有一个回文日期
	//枚举所有根据年份回文的数字
	int y1 = n1 / 10000; 
	int y2 = n2 / 10000;
	int month =  (n1 / 100) % 100;
	int day = n1 % 100;
	for(int i = y1;i <= y2;i++)
	{
		if(check2(i,month,day)) cnt++;
	}
	cout << cnt;
 } 
int main()
{
	cin >> n1 >> n2;
	//1.暴力枚举
	//func1();
	//2.枚举优化
	func2(); 
	return 0;
}


#include <iostream>

using namespace std;

int x,y;
int cnt;

bool is_valid_date(int year,int month,int day)
{
	//1.基础筛选
	if(month < 1 || month > 12 || day < 1 || day > 31) return false;
	//按月份筛选
	if(month == 2)
	{
		if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		{
			//闰年
			if(day > 29) return false; 
		}  
		else
		{
			if(day > 28) return false;
		}
	} 
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		if(day > 30) return false;
	}
	else
	{
		if(day > 31) return false;
	}
	return true;
}
bool check(int n)
{
	//得到year,month,day
	int year = n / 10000;
	int month = (n / 100) % 100;
	int day = n % 100;
	//判断是否合法
	if(!is_valid_date(year,month,day)) return false;
	//进行回文判断
	int tmp = 0;
	int ret = year;
	while(ret > 0)
	{
		tmp = tmp * 10 + ret % 10;
		ret /= 10;
	}
	//此时tmp就是年份的回文数字 
	int md = month * 100 + day;
	return md == tmp;
	 
}
int main()
{
	cin >> x >> y;
	//通过年份找到对应的唯一的回文数字，与month day比较
	for(int i = x;i <= y;i++)
	{
		if(check(i)) cnt++;
	}
	cout << cnt;
	return 0;
}


#include <iostream>

using namespace std;

int x, y;
int day[] = 0

int main()
{
	cin >> x > y;
	int ret = 0;
	return 0;
}


