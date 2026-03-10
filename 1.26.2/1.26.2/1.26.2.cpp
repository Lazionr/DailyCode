#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stack>
//
//using namespace std;
//typedef unsigned long long ULL;
//
//stack<ULL> st;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int t,n;
//	ULL x;
//	string s;
//	cin >> t;
//	while(t--)
//	{
//		cin >> n;
//		while(n--)
//		{
//			cin >> s;
//			if(s == "push")
//			{
//				cin >> x;
//				st.push(x);
//			}
//			else if(s == "pop")
//			{   if(st.size())
//				  st.pop();
//				cout << "Empty" << endl;
//			}
//			else if(s == "query")
//			{
//				if(st.size())
//				  cout << st.top() << endl;
//				cout << "Anguei!" << endl;
//			}
//			else
//			{
//				  cout << st.size() << endl;
//			}
//		} 
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//typedef unsigned long long ULL;
//const int N = 1e6 + 10;
//ULL stk[N];
//int num;
//int main()
//{
//	ios::sync_with_stdio(false);
//    cin.tie(NULL);
//	int t;
//	cin >> t;
//	string op;
//	while(t--)
//	{
//		//先清空栈
//		num = 0; 
//		int n;
//		cin >> n;
//		while(n--)
//		{
//		cin >> op;
//		if(op == "push")
//		{
//			ULL x;
//			cin >> x;
//			stk[++num] = x;
//		}
//		else if(op == "pop")
//		{
//			if(num)
//			num--;
//			else
//			cout << "Empty" << endl;
//		}
//		else if(op == "query")
//		{
//			if(num)
//			cout << stk[num] << endl;
//			else
//			cout << "Anguei!" << endl;
//		}
//		else
//		{
//			cout << num << endl;
//		}
//		}
//	}
//	return 0;
//} 

//#include <iostream>
//#include <stack>
//#include <vector> 
//using namespace std;
//
//const int N = 1e5 + 10;
//stack<int> st;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	int q,n;
//	cin >> q;
//	while(q--)
//	{
//		cin >> n;
//		vector<int> poped(n);
//		int x,y;
//		for(int i = 1;i <= n;i++)
//		{
//			cin >> x;
//			st.push(x);
//		}
//		for(int i = 1;i <= n;i++)
//		{
//			cin >> poped[i];
//		}
//		for(int i = 1;i <= n;i++)
//		{
//			if(st.empty())
//			  continue;
//			else
//			{
//				if(st.top() == poped[i])
//				{
//					st.pop();
//				}
//				else continue;
//			}
//		}
//		if(st.empty())
//		  cout << "Yes" << endl;
//		else
//		  cout << "No" << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <stack>
//using namespace std;
//const int N = 1e5 + 10;
//int a[N],b[N];
//
//int main()
//{
//	int q,n;
//	cin >> q;
//	while(q--)
//	{
//		cin >> n;
//		for(int i = 1;i <= n;i++)  cin >> a[i];
//		for(int i = 1;i <= n;i++)  cin >> b[i];
//		
//		stack<int> st;
//		int j = 1;//出栈序列指针 
//		for(int i = 1;i <= n;i++)
//		{
//			//进栈
//			st.push(a[i]);
//			while(!st.empty() && st.top() == b[j] && j <= n)
//			{
//				st.pop();
//				j++;
//			}
//		}
//		if(st.empty())
//		  cout << "Yes" << endl;
//		else
//		  cout << "No" << endl;
//	}
//	return 0;
//} 

//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//stack<int> st; 
//int main()
//{
//	char ch;
//	int num = 0;
//	while(cin >> ch)
//	{
//		if(ch == '@')  break;
//		else if(ch >= '0' && ch <= '9')
//		{
//			num = num * 10 + ch - '0';
//			
//		}
//		else if(ch == '.')
//		{
//			st.push(num);
//			num = 0;//必须将Num置为0 
//		}
//		else //遇到操作符
//		{
//			int b = st.top(); st.pop();
//			int a = st.top(); st.pop();
//			if(ch == '+')  st.push(a+b);
//			else if(ch == '-')  st.push(a-b);
//			else if(ch == '*')  st.push(a*b);
//			else st.push(a/b);
//		} 
//	}
//	cout << st.top() << endl;
//	return 0;
//}

//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//stack<int> st; 
//int main()
//{
//	string s,str;
//	cin >> s;
//	int num;
//	char ch;
//	for(string::iterator i = s.begin();i < s.end();i++)
//	{
//		if(*i == '@')  break;
//		else if(*i >= '0' && *i <= '9')
//		{
//		    str += *i;
//		    num = stoi(str);
//		}
//		else if(*i == '.')
//		{
//			st.push(num);
//			str.clear();//清空str 
//		}
//		else //遇到操作符
//		{
//			ch = *i;
//			int b = st.top(); st.pop();
//			int a = st.top(); st.pop();
//			if(ch == '+')  st.push(a+b);
//			else if(ch == '-')  st.push(a-b);
//			else if(ch == '*')  st.push(a*b);
//			else st.push(a/b);
//		} 
//	}
//	cout << st.top() << endl;
//	return 0;
//}


#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int N = 110;
bool st[N];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<int> stk; //栈里面存的是下标 
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '(')  stk.push(i);
        else
        {
            if (stk.empty())  continue;

            int t = stk.top();
            if (s[t] == '(' && s[i] == ']')
            {
                st[t] = st[i] = true;
                stk.pop();
            }
        }
    }
    string ret = "";
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (st[i]) ret += ch;
        else
        {
            // 不能匹配就要加括号
            if (ch == '(')
            {
                ret += ch;
                ret += ')';
            }
            else if (ch == ')')
            {
                ret += '(';
                ret += ch;
            }
            else if (ch == '[')
            {
                ret += ch;
                ret += ']';
            }
            else if (ch == ']')
            {
                ret += '[';
                ret += ch;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
