#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void func(int n,int x)
{
	if(n >= x)
	   func(n/x,x);
	cout << s[n%x];
}
int main()
{
	int n,x;
	cin >> n >> x;
	func(n,x);
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
	int j = 0;
	int ret = 0;
	for(int i = s.size() - 1;i >= 0;i--)
	{
		if(s[i] <= '9')
			ret += (s[i] - '0') * pow(x,j);
		else
			ret += (s[i] - 'A' + 10) * pow(x,j);
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
void r_to_m(int r,int m)
{
	//用递归的思想
	 if(r >= m)
	    r_to_m(r/m,m);
	 cout << str[r%m];
}
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	//先转换为十进制
	int r = stoi(s,NULL,n);
	//再将十进制转换为m进制
	int m;
	cin >> m;
	r_to_m(r,m);
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	//00000000 00000000 00000000 00000101
	int b = -7;
	//10000000 00000000 00000000 00000111
	//11111111 11111111 11111111 11111000
	//11111111 11111111 11111111 11111001
	int c = a & b;
	//a的补码:00000000 00000000 00000000 00000101
	//b的补码:11111111 11111111 11111111 11111001
	// a & b :00000000 00000000 00000000 00000001
	//&:按位与,只有相同位置均为1结果才为1
	cout << c << endl;

	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	//00000000 00000000 00000000 00000101
	int b = -7;
	//10000000 00000000 00000000 00000111
	//11111111 11111111 11111111 11111000
	//11111111 11111111 11111111 11111001
	int c = a | b;
	//a的补码:00000000 00000000 00000000 00000101
	//b的补码:11111111 11111111 11111111 11111001
	// a | b :11111111 11111111 11111111 11111101
	//转换为原码:
	//        10000000 00000000 00000000 00000011 
	//|:按位或,只要相同位置出现1结果就为1 
	cout << c << endl;

	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a = 5;
	//00000000 00000000 00000000 00000101
	int b = -7;
	//10000000 00000000 00000000 00000111
	//11111111 11111111 11111111 11111000
	//11111111 11111111 11111111 11111001
	int c = a ^ b;
	//a的补码:00000000 00000000 00000000 00000101
	//b的补码:11111111 11111111 11111111 11111001
	// a ^ b :11111111 11111111 11111111 11111100
	//转换为原码:
	//        10000000 00000000 00000000 00000100
	//^:按位异或,对应位置相同即为0,反之为1 
	cout << c << endl;

	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int b = -7;
	//10000000 00000000 00000000 00000111
	//11111111 11111111 11111111 11111000
	//11111111 11111111 11111111 11111001
	//~b:
	//00000000 00000000 00000000 00000110
	//~:按位取反,对应位置1->0,0->1 
	cout << ~b << endl;
	return 0;
}