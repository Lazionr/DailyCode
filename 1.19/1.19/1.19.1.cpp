#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int func(int n)
{
	if(n == 0)
	return 1;
	else
	return n * func(n-1);
}
int main()
{
	//ÓÃµÝ¹éÇónµÄ½×³Ë
	int n;
	cin >> n;
	int ret = func(n);
	cout << ret << endl; 
	return 0;
}

#include <iostream>
using namespace std;
int func(int n)
{
	if(n == 1)
	return 1;
	else if(n == 2)
	return 1;
	else
	return func(n-1) + func(n-2);
}
int main()
{
	int m,n;
	cin >> m;
	while(m--)
	{
		cin >> n;
		int ret = func(n);
	    cout << ret << endl;
	}		 
	return 0;
}

#include <iostream>
using namespace std;
int func(int n)
{
	if(n == 1)
	return 1;
	else
	return n + func(n-1);

}
int main()
{
	int n;
	cin >> n;
	cout << func(n) << endl;
	return 0;
}

#include <iostream>
using namespace std;
int Ackermann(int m,int n)
{
	if(m == 0)
	    return n + 1;
	else if(m > 0 && n == 0)
	    return Ackermann(m-1,1);
	else
	    return Ackermann(m-1,Ackermann(m,n-1));
}
int main()
{
	int m,n;
	cin >> m >> n;
	cout << Ackermann(m,n) << endl;
	return 0;
}

#include <iostream>
using namespace std;
int digit(int n,int k)
{
	int ret = 0;
	while(k--)
	{
		ret = n % 10;
		n /= 10;
	}
	return ret; 
}
int main()
{
	int n,k;
	cin >> n >> k;
	cout << digit(n,k) << endl; 
}

#include <iostream>
using namespace std;
int digit(int n,int k)
{
	if(k == 1)
	return n % 10;
	else
	return digit(n/10,k-1);
}
int main()
{
	int n,k;
	cin >> n >> k;
	cout << digit(n,k) << endl; 
}

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double func(double x,double n)
{
	if(n == 1)
	    return sqrt(1+x);
	else
		return sqrt(n+func(x,n-1));
}
int main()
{
	double x,n;
	cin >> x >> n;
	cout << fixed << setprecision(2) << func(x,n) << endl;
	return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double func(double x,double n)
{
	if(n == 1)
	   return x / (1 + x);
	else
	   return x / (n + func(x,n-1));
}
int main()
{
	double x,n;
	cin >> x >> n;
	cout << fixed << setprecision(2) << func(x,n) << endl;
	return 0;
}


#include <iostream>
#include <string>
using namespace std;
string s = "0123456789ABCDEF";
void func(int x, int m)
{
	if (x >= m)
		func(x / m, m);
	cout << s[x % m];
}
int main()
{
	int x, m;
	cin >> x >> m;
	func(x, m);
	return 0;
}
