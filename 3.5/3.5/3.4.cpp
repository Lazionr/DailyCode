#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <algorithm>
//#include <cctype>
//#include <string>
//using namespace std;
//
//int p1,p2,p3;
//string s,ret;
//
//bool check(char left,char right)
//{
//	return ((isdigit(left) && isdigit(right)) || 
//	        (islower(left) && islower(right)));
//}
//void add(char left,char right)
//{
//	string v;
//	for(char ch = left + 1;ch <= right - 1;ch++)
//	{
//		char tmp = ch;
//		if(p1 == 2 && islower(tmp)) tmp -= 32;
//		else if(p1 == 3) tmp = '*';
//		
//		for(int i = 1;i <= p2;i++)
//		{
//			v += tmp;
//		}
//	}
//	if(p3 == 2) reverse(v.begin(),v.end());
//	ret += v;
//}
//int main()
//{
//	cin >> p1 >> p2 >> p3 >> s;
//	int n = s.size() - 1;
//	for(int i = 0;i <= n;i++)
//	{
//		char ch = s[i];
//		//开头或者末尾遇到'-',直接 += 
//		if(ch != '-' || i == 0 || i == n) ret += ch;
//		else
//		{
//			char left = s[i-1];
//			char right = s[i+1];
//			if(check(left,right) && left < right)
//			{
//				add(left,right);
//			}
//			else
//			{
//				ret += ch;
//			}
//			
//		}
//	}
//	cout << ret;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//const int N = 1e6 + 10;
//int a[N],b[N],c[N];
//int la,lb,lc;
//
//int main()
//{
//	string s1,s2;
//	cin >> s1 >> s2;
//	la = s1.size();
//	lb = s2.size();
//	//1.转化成数字后逆序存储到数组中 
//    for(int i = 0;i <= la;i++) a[la-1-i] = s1[i] - '0';
//    for(int i = 0;i <= lb;i++) b[lb-1-i] = s2[i] - '0';
// 	//2.计算
//	lc = max(la,lb);
//	for(int i = 0;i <= lc;i++)
//	{
//		c[i] += a[i] + b[i];
//		c[i + 1] = c[i] / 10;
//		c[i] %= 10;//处理余数 
//		
//		if(c[lc]) lc++; 
//	}
//	//3.逆序输出
//	for(int i = lc - 1;i >= 0;i--) cout << c[i]; 
//	return 0;
//}

#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;
void sub(int x[], int y[])
{
	//x-y
	for (int i = 0; i < lc; i++)
	{
		if (x[i] >= y[i]) c[i] = x[i] - y[i];
		else
		{
			x[i] += 10;
			int j = i;
			while (x[j] == 0)
			{
				x[j + 1] -= 1;
				j++;
			}
			c[i] = x[i] - y[i];
		}
	}
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	la = s1.size();
	lb = s2.size();
	//1.转化成数字并逆序存储
	for (int i = 0; i < la; i++) a[la - 1 - i] = s1[i] - '0';
	for (int i = 0; i < lb; i++) b[lb - 1 - i] = s2[i] - '0';
	//2.判断是否需要加负号
	lc = max(la, lb);
	if (a[la - 1] > b[lb - 1])
	{
		//不需要加负号
		sub(a, b);
		for (int i = lc - 1; i >= 0; i--) cout << c[i];
	}
	else
	{
		//需要加负号
		sub(b, a);
		cout << '-';
		for (int i = lc - 1; i >= 0; i--) cout << c[i];
	}

	return 0;
}

