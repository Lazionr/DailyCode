#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n & 1 == 1)
	   cout << "odd" << endl;
	else
	   cout << "even" << endl;
	return 0;
}

//三个进制转换
#include <iostream>
#include <string>
using namespace std;
string str = "0123456789ABCDEF";
void to_x(int n,int x)
{
	if(n >= x)
	   to_x(n/x,x);
	cout << str[n%x];
}
int main()
{
	int n,x;
	cin >> n >> x;
	to_x(n,x);
	return 0; 
} 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int x;
	cin >> x;
	string s;
	cin >> s;
	int ret = 0;
	int j = 0;
	for(int i = s.size() - 1;i >= 0;i--)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			//数字字符 
			s[i] -= '0';
			ret += s[i] * pow(x,j);
		}
		else
		{
			//字母字符
			s[i] = s[i] - 'A' + 10;
			ret += s[i] * pow(x,j); 
		}
		j++;
	}
	cout << ret << endl;
	return 0; 
} 

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int x;
	cin >> x;
	string s;
	cin >> s;
	
	int ret = stoi(s,NULL,x);
	cout << ret << endl;
	return 0; 
} 

#include <iostream>
#include <string>
using namespace std;
string str = "0123456789ABCDEF";
void n_to_m(int n, int m)
{
	//用递归实现
	if (n >= m)
		n_to_m(n / m, m);
	cout << str[n % m];
}
int main()
{
	int n, m;
	cin >> n;
	string s;
	cin >> s >> m;
	//1.先转换为十进制
	int x = stoi(s, NULL, n);
	//2.十进制转换为m进制
	n_to_m(x, m);
	return 0;
}

