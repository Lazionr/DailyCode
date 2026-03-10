#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef struct Stu
{
	int id;
	int s1;
	int s2;
	
int	calc_total()
{
	return s1 + s2;
}
int calc_comprehensive()
{
	return s1 * 7 + s2 * 3;
}
}Stu; 


void is_excellent(Stu& s)
{
	if(s.calc_total() > 140 && s.calc_comprehensive() >= 800)
	    cout << "Excellent" << endl;
	else
	    cout << "Not excellent" << endl;
}

int  main()
{
	int n;
	cin >> n;
	Stu s;
	while(n--)
	{
		cin >> s.id >> s.s1 >> s.s2;
		is_excellent(s);
	}
	
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Stu
{
	string name;
	int score;
}Stu;
bool cmp(Stu s1,Stu s2)
{
	return s1.score > s2.score;
}
int main()
{
	int n;
	cin >> n;
	Stu s[n];
	for(int i = 0;i < n;i++)
	{
		cin >> s[i].score >> s[i].name;
	}
	sort(s,s+n,cmp);
	cout << s[0].name << endl;
	return 0;
}

#include <iostream>
using namespace std;
typedef struct Stu
{
	string name;
	int score;
}Stu;

int main()
{
	int N;
	cin >> N;
	Stu max = {" ",0};
	while(N--)
	{
		Stu s;
		cin >> s.score >> s.name;
		if(s.score > max.score)
		{
			max.score = s.score;
			max.name = s.name;
		}
	}
	cout << max.name << endl;
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
const int N = 210;

struct S
{
	string s;
	double ctp;
	int sore;
}arr[N];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i].s >> arr[i].ctp >> arr[i].sore;
	}
	int cnt = 0;
	for(int i = 0;i < n;i++)
	{
		if(arr[i].ctp >= 37.5 && arr[i].sore == 1)
		{
			cout << arr[i].s << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 60;
int arr[N];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for(int i = n - 1;i >= n - 5;i--)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;
const int N = 310;
typedef struct S
{
	int chinese;
	int math;
	int english;
	int total;
	int id;
}S;
S arr[N];

bool cmp(S& s1,S& s2)
{
	if(s1.total != s2.total)
	   return s1.total > s2.total;
	else if(s1.chinese != s2.chinese)
	   return s1.chinese > s2.chinese;
	else 
	   return s1.id < s2.id;
}
int main()
{
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> arr[i].chinese >> arr[i].math >> arr[i].english;
	    arr[i].id = i;
	    arr[i].total = arr[i].chinese + arr[i].math + arr[i].english; 
	}
	sort(arr+1,arr+1+n,cmp);//Ωµ–Ú≈≈¡–
	for(int i = 1;i <= 5;i++)
	{
		cout << arr[i].id << " " << arr[i].total <<endl;
	} 
	cout << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 110;
typedef struct S
{
	int id;
	string s;
	int y;
	int m;
	int d;
}S;
S arr[N];

bool cmp(S& s1,S& s2)
{
	//Ωµ–Ú 
	if(s1.y != s2.y)
	   return s1.y < s2.y;
	else if(s1.m != s2.m)
	   return s1.m < s2.m;
	else if(s1.d != s2.d)
	   return s1.d < s2.d;
	else 
	   return s1.id > s2.id;
}
int main()
{
	int n;
	cin >> n;
	
	for(int i =1;i <= n;i++)
	{
		arr[i].id = i;
		cin >> arr[i].s >> arr[i].y >> arr[i].m >> arr[i].d;
	}
	sort(arr+1,arr+1+n,cmp);
	for(int i = 1;i <= n;i++)
	{
		cout << arr[i].s << endl;
	} 
	cout << endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int arr[10] = {0};
	int* pa = &arr[0];
	for(int i = 0;i < 10;i++)
	{
		*(pa+i) = i;
	} 
	for(int e: arr)
	{
		cout << e << " ";
	}
	return 0;
}


#include <iostream>
using namespace std; l
int main()
{
	int* ptr = new int;
	delete ptr1;
	ptr1 = NULL;

	return 0;
}
