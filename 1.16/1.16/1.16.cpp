#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s = "hello world hello everyone";
	string str = "llo";
	size_t n = s.find(str);
	cout << n << endl;
	size_t m = s.find(str,n+1);
	cout << m << endl;
    size_t n = s.find("bit");
    if(n == string::npos)
   cout << "没找到" << endl;
    else
    cout << "找到了" << endl; 
    string s1 = s.substr();
    cout << s1 << endl;
    string s2 = s.substr(7);
    cout << s2 << endl;
    string s1 = "hello world";
    string s2 = "hello";
    if(s1 == s2 + "world")
    cout << "==" << endl;
    else
    cout << "!=" << endl;
    string s = "11xx22";
	size_t pos = 0;
	int r = stoi(s,&pos);
	cout << r << endl;
	cout << pos << endl;	
	return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int cnt = 0;
	for(auto it = s.begin();it != s.end();it++)
	{
		if(isspace(*it))
		continue;
		else
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}

//isspace 专门用来判断一个字符是否为空白字符 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int cnt = 0;
	for(auto e: s)
	{
		if(isspace(e))
		continue;
		else
		cnt++;
	}
	cout << cnt << endl;
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
		cnt += s.size();
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	while(n--)
	{
		string s1;
		string s2;
	    cin >> s1;
		cin >> s2;
		if(s1 == s2)
		cout << "Tie" << endl;
		else if(s1 == "Rock" && s2 == "Scissors")
		cout << "Player1" << endl;
		else if(s1 == "Scissors" && s2 == "Paper")
		cout << "Player1" << endl;
		else if(s1 == "Paper" && s2 == "Rock")
		cout << "Player1" << endl;
		else
		cout << "Player2" << endl;
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
	for(string::iterator it = s.begin();it < s.end();it++)
	{
		if(*it >= 'a' && *it <= 'z')
		{
			if(*it == 'a')
			*it = 'z';
			else
			(*it)--;
		}
		else if(*it >= 'A' && *it <= 'Z')
		{
			if(*it == 'A')
			*it = 'Z';
			else
			(*it)--;
		}
	}
	cout << s << endl;
	return 0;
}
//用find函数来查找 
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int m = s.find('a');
	if(m != string::npos)
	s[m] = 'z';
    int n = s.find('A');
	if(n != string::npos)
 	s[n] = 'Z';
	for(string::iterator it = s.begin();it < s.end();it++)
	{
		
		if(*it >= 'b' && *it <= 'z')
		(*it)--;
		else if(*it >= 'B' && *it <= 'Z')
		(*it)--;

	}
	cout << s << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int q = 0;
	cin >> q;
	string s;
	cin >> s;
	int n = 0;
	while(q--)
	{
		cin >> n;
		switch(n)
	{
		case 1:
			{
			    string str;
			    cin >> str;
			    s += str;
			    cout << s << endl;
			    break;
			}
		case 2:
			{
				int a,b;
				cin >> a;
				cin >> b;
				s = s.substr(a,b);
				cout << s << endl;
				break;
			}
		case 3:
			{
				int a;
				cin >> a;
				string str;
				cin >> str;
				s.insert(a,str);
				cout << s << endl;
				break;
			}
		case 4:
			{
				string str;
				cin >> str;
				size_t ret = s.find(str);
				if(ret == string::npos)
				cout << -1 << endl;
				else
				cout << ret << endl;
				break;
			}
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
	cin >> s;
	cout << s.size();
	while(cin >> s)
	{
		cout << ',' << s.size();
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	bool flag = true;
	while(cin >> s)
	{
		if(flag)
		{
			//先处理第一个单词 
			cout << s.size();
			flag = false;
		}
		else
		{
			cout << ',' << s.size();
		}
	}
	return 0;
}

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s;
	int k = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (isspace(s[i]))
		{
			for (int m = i - 1; m >= k; m--)
			{
				cout << s[m];
			}
			k = i + 1;
			cout << endl;
		}
	}
	for (int m = s.size() - 1; m >= k; m--)
	{
		cout << s[m];
	}
	cout << endl;
	return 0;
}


#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s;
	int j = 0;
	int k = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (isspace(s[i]))
		{
			j = i;
			for (int m = j - 1; m >= k; m--)
			{
				cout << s[m];
			}
			k = j + 1;
			cout << endl;
		}
	}
	return 0;
}