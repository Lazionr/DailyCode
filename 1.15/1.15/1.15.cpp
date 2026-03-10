#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int N = 1010;
const int M = 10;
int ans[7];//中彩票的号码 
int c[7];//记录中奖次数 
int main()
{
	int n = 0;
	int num = 0;
	cin >> n;
	//输入中奖号码
	for(int i = 0;i < 7;i++)
	{
		cin >> ans[i];
	} 
	for(int i = 0;i < n;i++)
	{
		int cnt = 0;
		for(int j = 0;j < 7;j++)
		{
			cin >> num;
			for(int k = 0;k < 7;k++)
			{
				if(num == ans[k])
				cnt++;
			}
		}
	c[7-cnt]++;
	}
	for(int i = 0;i < 7;i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	//练习使用strcpy,strcat函数
	char arr1[] = "hello world!";
	char arr2[20];
	char arr3[20] = "back";
//	strcpy(arr2,arr1);
//	cout << arr2 << endl; 
    strcat(arr1,arr3);
    cout << arr1 << endl;
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
char arr[N];
int main()
{
	cin >> arr;
	int len = strlen(arr);
	for(int i = 0;i < len;i++)
	{
		if(arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] -= 32;
		}
	}
	cout << arr << endl;
	return 0;
}

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int N = 110;
char arr[N];
int main()
{
	cin >> arr;
	int len = strlen(arr);
	for(int i = 0;i < len;i++)
	{
		if(islower(arr[i]))
		{
			arr[i] = toupper(arr[i]);
		}
	}
	cout << arr << endl;
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
const int N = 255;
char arr[N];
int main()
{
	fgets(arr,N,stdin);
	int len = strlen(arr);
	int cnt = 0;
	for(int i = 0;i < len;i++)
	{
		if(arr[i] >= '0' && arr[i] <= '9')
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int N = 255;
char arr[N];
int main()
{
	fgets(arr,N,stdin);
	int len = strlen(arr);
	int cnt = 0;
	for(int i = 0;i < len;i++)
	{
		if(isdigit(arr[i]))
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int N = 110;
const int M = 30;
char arr[N][M];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < 30;j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < strlen(arr[i]);j++)
		{
			if(j == 0)
			arr[i][j] = toupper(arr[i][j]);
			else
			arr[i][j] = tolower(arr[i][j]);
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}



#include <iostream>
#include <cctype>
using namespace std;
const int N = 30;
char arr[30];
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		cin >> arr;
		if(islower(arr[0]))
		{
			arr[0] = toupper(arr[0]);
		}
		int j = 1;
		while(arr[j])
		{
			if(isupper(arr[j]))
			{
				arr[j] = tolower(arr[j]);
			}
			j++;
		}
		cout << arr << endl;
	}
	return 0;
}


#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
char arr1[N];
char arr2[N];
int main()
{
	double n = 0;
	int cnt = 0;
	cin >> n;
	cin >> arr1;
	cin >> arr2;
	int length = strlen(arr1);
	for(int i = 0;i < length;i++)
	{
		if(arr1[i] == arr2[i])
		{
			cnt++;
		}
	}
	if(cnt * 1.0 / length >= n)
	cout << "yes" << endl;
	else
	cout << "no" << endl;
	return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
char arr1[N];
char arr2[N];
int main()
{
	cin >> arr1;
	for(int i = 0;i < strlen(arr1);i++)
	{
		if(i < strlen(arr1) - 1)
		arr2[i] = arr1[i] + arr1[i+1];
		else
		arr2[i] = arr1[i] + arr1[0];
    }
	cout << arr2;
	return 0;
}


#include <iostream>
#include <cstring>
using namespace std;
const int N = 25;
char arr1[N];
char arr2[N];
int main()
{
	cin >> arr1;
	cin >> arr2;
	if(strstr(arr1,arr2))
	{
		cout << arr2 << " is substring of " << arr1;
	}
	else if(strstr(arr2,arr1))
	{
		cout << arr1 << " is substring of " << arr2;
	}
	else
	cout << "No substring" << endl;
	return 0;
}

#include <iostream> 
#include <cstring>
using namespace std;
const int N = 1110;
char arr[N];
int main()
{
	cin >> arr;
	int i = 0;
	int flag = 0;//假设没有出现 
	while(arr[i])
	{
		int cnt = 0; 
		for(int j = 0;j < strlen(arr);j++)
		{
			if(arr[i] == arr[j])
			{
				cnt++;
			}
		}
		if(cnt == 1)
		{
			cout << arr[i] << endl;
			flag = 1;
			break;
		}
		i++;
	}
	//1.break跳出来到这
	//2.没有cnt == 1的情况
	if(flag == 0)
	{
		cout << "no" << endl;
	} 
	return 0;
}

#include <iostream>
using namespace std;
const int N = 1110;
char arr[N];
char nums[128];//利用下标匹配字母，记录字母出现个数
 
int main()
{
	cin >> arr;
	int i = 0;
	while(arr[i])
	{
		//记录字母出现个数 
		nums[arr[i]]++;
		i++;
	}
	i = 0;
	int flag = 0;
	while(arr[i])
	{
		if(nums[arr[i]] == 1)
		{
			cout << arr[i] << endl;
			flag = 1;
			break;
		}
		i++; 
	}
	if(flag == 0)
	cout << "no" << endl;
	return 0;
}

#include <iostream>
using namespace std;
const int N = 1110;
char arr[N];
int main()
{
	cin >> arr;
	int i = 0;
	int flag = 0;//假设不是仅出现一次的元素
	while(arr[i])
	{
		int j = 0;
		int cnt = 0;
		while(arr[j])
		{
			if(arr[i] == arr[j])
			{
				cnt++;
			}
			j++;  
		}
		if(cnt == 1)
		{
			cout << arr[i] << endl;
			flag = 1;
			break;
		}
		i++;
	}
	if(flag == 0)
	{
		cout << "no" << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    	string s1;
    	string s2 = "abcdef";
    	cout << s2 << endl;
        string s;
        cin >> s;
        cout << s <<endl;
        string s;
        getline(cin,s,'w');
        cout << s << endl;
        string s;
        cin >> s;
        cout << s << endl;
        cout << s.size() << endl;
    //迭代器的使用
        string s = "abcdef";
        string::iterator it1 = s.begin();
        string::iterator it2 = s.end();
        cout << it1 - it2 << endl;
        //正序遍历
    	for(string::iterator it = s.begin();it < s.end();it++) 
    	{
    		cout << *it;
    	}
    	cout << endl;
        //逆序遍历
    	for(string::iterator it = s.end() - 1 ;it >= s.begin();it--)
    	{
    		cout << *it;
    	 } 
    	 cout << endl;
        s.push_back('x');
        cout << s << endl;
        string s;
        char c = 0;
        for(char c = 'a';c <= 'z';c++)
        {
        	s.push_back(c);
    	}
    	cout << s << endl;
    	s.pop_back();
    	cout << s << endl;
    //insert函数
    string s = "abcdef";
    	string str = "xxx";
    	cout << s << endl;
    	s.insert(3,str);
    	cout << s << endl;
    cout << s << endl;
    s.insert(3, "xxx");
    cout << s << endl;
    s.insert(3,'x');
    cout << s << endl;
    return 0;
}