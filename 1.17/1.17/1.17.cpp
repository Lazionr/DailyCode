#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s;
	int k = 0;
	getline(cin,s);
	for(int i = 0;i < s.size();i++)
	{
		if(isspace(s[i]))
		{
			for(int m = i - 1;m >= k;m--)
			{
				cout << s[m];
			}
			k = i + 1;
			cout << endl;
		}
	}
	for(int m = s.size() - 1;m >= k;m--)
	{
		cout << s[m];
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
//	 string s;
//	 while(cin >> s)
//	 {
//	 	reverse(s.begin(),s.end());
//	 	cout << s << endl;
//	 }
    //整形反转
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	reverse(arr,arr + sz);
	for(auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string s1 = s;
	reverse(s1.begin(),s1.end());
	if(s1 == s)
	cout << "yes" << endl;
	else
	cout << "no" << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int left = 0;
	int right = s.size() - 1;
	while(left <= right)
	{
		if(s[left] == s[right])
	{
		left++;
		right--;
	}
	else
	cout << "no" << endl;
	}
	cout << "yes" << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int arr[] = {1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4};
int main()
{
	int n = 0;
	string s;
	getline(cin,s);
	for(auto e : s)
	{
		if(e == ' ')
		n += 1;
		else
		n += arr[e - 'a'];
	}
	cout << n << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i = 0;
	cin >> i;
	string last;
	while(i--)
	{
		string op;
		string ans;
		cin >> op;
		int n1,n2,r;
		if(op == "a" || op == "b" || op == "c")
		{
			//三个数据 
			cin >> n1 >> n2;
			ans += to_string(n1);
			if(op == "a")
			{
			    r = n1 + n2;
			    ans += "+";
			    ans += to_string(n2);
			    ans += "=";
			    ans += to_string(r);
			}
			else if(op == "b")
			{
				r = n1 - n2;
			    ans += "-";
			    ans += to_string(n2);
			    ans += "=";
			    ans += to_string(r);
			}
			else
			{
				r = n1 * n2;
			    ans += "*";
			    ans += to_string(n2);
			    ans += "=";
			    ans += to_string(r);
			}
			last = op;
		}
		else
		{
			//两个数据 与上次运算类型相同
			ans += op;
			n1 = stoi(op); 
			cin >> n2;
			if(last == "a")
			{
			    r = n1 + n2;
			    ans += "+";
			    ans += to_string(n2);
			    ans += "=";
			    ans += to_string(r);
			}
			else if(last == "b")
			{
				r = n1 - n2;
			    ans += "-";
			    ans += to_string(n2);
			    ans += "=";
			    ans += to_string(r);
			}
			else
			{
				r = n1 * n2;
			    ans += "*";
			    ans += to_string(n2);
			    ans += "=";
			    ans += to_string(r);
			}
		}
		cout << ans << endl;
		cout << ans.size() << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << (a + b) / c << endl;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ret = 0;
	while(n)
	{
		if(n % 10 != 7 && n / 10 != 7 && n % 7 != 0)
		{
			ret += pow(n,2);
		}
		n--;
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a,b;
	while(n--)
	{
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}


#include <iostream>
using namespace std;
const int N = 35;
int arr[N] = {0,1,1};
int main()
{
	//计算前30个斐波那契数
	for(int i = 3;i <= 30;i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	} 
	int n,a;
	cin >> n;
	while(n--)
	{
		cin >> a;
		cout << arr[a] << endl;
	}
	return 0;
}


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	string t;
	cin >> s;
	cin >> t;
	int q;
	cin >> q;
	int l1,r1,l2,r2;
	while(q--)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		string s1 = s.substr(l1-1,r1-l1+1);
		string t1 = t.substr(l2-1,r2-l2+1);
		if(s1 < t1)
		cout << "yifusuyi" << endl;
		else if(s1 > t1)
		cout << "erfusuer" << endl;
		else
		cout << "ovo" << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		cout << a + b << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int k = 0;
	while(cin >> k)
	{
	    for(int i = 1;i <= k;i++)
	    {
		    for(int j = 1;j <= i;j++)
		    {
			    cout << j << " ";
		    } 
		    cout << endl;
	    }
	}
	return 0;
}

#include <iostream>
using namespace std;
const int N = 25;
int arr[N];
int main()
{
	int n,k,m;
	while(cin >> n)
	{
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	for(int j = 0;j < n;j++)
	{
		if(arr[j] == m)
		{
			cout << j << endl;
			break;
		}
	}
	if(i == n)
	cout << "no" << endl;
	}
	return 0;
} 


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	//遍历字符串
	for(int i = 0;i < s.size() - 1;i++)
	{
		if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
		c1++;
		else if(s[i] >= 48 && s[i] <= 57)
		c2++;
		else
		c3++;
	} 
	cout << "Letters=" << c1 << endl;
	cout << "Digits=" << c2 << endl;
	cout << "Othjers=" << c3 << endl;
	return 0;
}

//isalpha 判断是否为字母 
//isupper 判断是否为大写字母 
//islower 判断是否为小写字母 

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	//遍历字符串
	for(int i = 0;i < s.size() - 1;i++)
	{
//		if(islower(s[i]) || isupper(s[i]))
        if(isalpha(s[i]))
		c1++;
		else if(isdigit(s[i]))
		c2++;
		else
		c3++;
	} 
	cout << "Letters=" << c1 << endl;
	cout << "Digits=" << c2 << endl;
	cout << "Othjers=" << c3 << endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a,b;
    while(cin >> a >> b)
	{
		if(a == b && b == 0)
		break;
		else
		{
			cout << a + b << endl;
		}
	}	
	return 0;
} 

#include <iostream>
using namespace std;
int main()
{
	int a,b;
    while(cin >> a >> b,a || b)
	{
		{
			cout << a + b << endl;
		}
	}	
	return 0;
} 

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int cnt = 0;
	while(cin >> s)
	{
		for(auto e : s)
		{
			if(isdigit(e))
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n)
	{
	    if(n / 11 == 0 && n % 2 == 0)
	    {
		  cout << 0 << endl;;
		  break;
	    }
	    else if(n / 11 == 0 && n % 2 != 0)
	    {
		  cout << 1 << endl;
		  break;
	    }
    	if((n % 10) % 2)
	    {
		  cout << 1;
    	}
	    else
    	cout << 0;
	    n /= 10;
	}
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ret = 0;
	int i = 0;
	while(n)
	{
		if(n % 10 % 2)
		{
			//奇数
			 ret += 1 * pow(10,i);
		}
//		else
//		{
//			//偶数
//			ret += 0 * pow(10,i++); 
//		}
		n /= 10;
		i++;
	}
	cout << ret << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] % 2)
		s[i] = '1';
		else
		s[i] = '0';
	}
	cout << stoi(s) << endl;
	return 0;
}

ios::sync_with_stdio(false);
cin.tie(0);