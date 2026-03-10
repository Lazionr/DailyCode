#define _CRT_SECURE_NO_WARNINGS
//复习栈和队列例题

//stack
//1.
//#include <iostream>
//#include <string>
//using namespace std;
//
//typedef unsigned long long ULL;
//const int N = 1e6 + 10;
//ULL q[N];
//int id;
//int main()
//{
//	int t,n;
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
//				ULL x; cin >> x;
//				q[++id] = x;
//			}
//			else if(s == "pop")
//			{
//				if(id)
//				id--;
//				else
//				cout << "Empty" << endl;
//			}
//			else if(s == "query")
//			{
//				if(id)
//				cout << q[id] << endl;
//				else
//				cout << "Anguei!" << endl;
//			}
//			else
//			{
//				cout << id << endl;
//			}
//		}
//	}
//	return 0;
//}

//#include <iostream>
//#include <stack>
//using namespace std;
//const int N = 1e5 + 10; 
//stack<int> st;
//int a[N],b[N];
//int main()
//{
//	int q,n;
//	cin >> q;
//	while(q--)
//	{
//		cin >> n;
//		for(int i = 1;i <= n;i++)
//		{
//			cin >> a[i];
//			st.push(a[i]);
//		}
//		for(int i = 1;i <= n;i++)
//		{
//			cin >> b[i]; 
//			while(!st.empty() && st.top() == b[i])
//			{
//				st.pop();
//			}
//		}
//		if(st.empty())  cout << "Yes" << endl;
//		else cout << "No" << endl;
//	}
//	return 0;
//} 

//#include <iostream>
//#include <string>
//#include <stack> 
//using namespace std;
//
//stack<int> st;
//string s;
//int main()
//{
//	string s,str;
//	cin >> s;
//	int num = 0;
//	for(int i = 0;i < s.size();i++)
//	{
//		if(s[i] == '@')  break;
//		else if(s[i] >= '0' && s[i] <= '9')
//		{
//			str += s[i];
//			num = stoi(str);
//			
//		}
//		else if(s[i] == '.')
//		{
//			st.push(num);
//			str.clear();
//		}
//		else
//		{
//			int b = st.top();  st.pop();
//			int a = st.top();  st.pop();
//			if(s[i] == '+')
//			st.push(a + b);
//			else if(s[i] == '-')
//			st.push(a - b);
//			else if(s[i] == '*')
//			st.push(a * b);
//			else
//			st.push(a / b);
//		}
//	}
//	cout << st.top() << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//const int N = 110;
//stack<int> stk;
//string s;
//bool st[N];
//int main()
//{
//	cin >> s;
//	for(int i = 0;i < s.size();i++)
//	{
//		//栈里面存下标
//		if(s[i] == '(' || s[i] == '[')
//		{
//			stk.push(i);
//		} 
//		else
//		{
//			if(stk.empty())  continue;
//			if((s[i] == ')' && s[stk.top()] == '(') || (s[i] == ']' && s[stk.top() == '[']))
//			{
//				st[stk.top()] = true;
//				st[i] = true;
//				stk.pop();
//			} 
//		}
//	}
//	string ret = "";
//	for(int i = 0;i < s.size();i++)
//	{
//		char ch = s[i];
//		if(st[i])  ret += ch;
//		else
//		{
//			if(ch == '(')
//			{
//				ret += ch;
//				ret += ')';
//			}
//			else if(ch == ')')
//			{
//				ret += '(';
//				ret += ch;
//			}
//			else if(ch == '[')
//			{
//				ret += ch;
//				ret += ']';
//			}
//			else if(ch == ']')
//			{
//				ret += '[';
//				ret += ch;
//			}
//		 } 
//	}
//	cout << ret << endl;
//	return 0;
//}

//队列
//1.
//#include <iostream> 
//
//using namespace std;
//const int N = 1e6 + 10;
//
//int q[N],h,id;
//
//int main()
//{
//	int n,op;
//	cin >> n;
//	while(n--)
//	{
//		cin >> op;
//		if(op == 1)
//		{
//			int x; cin >> x;
//			q[++id] = x;
//		}
//		else if(op == 2)
//		{
//			if(id - h) 
//			{
//				id--;
//			}
//			else
//			cout << "ERR_CANNOT_POP" << endl;
//		}
//		else if(op == 3)
//		{
//			if(id - h)
//			{
//				cout << q[h+1] << endl;
//			}
//			else
//			cout << "ERR_CANNOT_QUERY" << endl;
//		}
//		else
//		{
//			cout << id - h << endl;
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <stack>

using namespace std;
stack<int> stk;
const int N = 110;
bool st[N];

int main()
{
	int m, n;
	cin >> m >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		if (st[x])  continue;

		stk.push(x);
		st[x] = true;
		if (stk.size() > m)
		{
			st[stk.top()] = false;
			stk.pop();
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}

