#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e6 + 10;

vector<int> a(N);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int id, num;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	while (m--)
	{
		cin >> num;
		cout << a[num] << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;

//创建N个vector 
vector<int> a[N];

int main()
{
	int n, q;
	cin >> n >> q;

	while (q--)
	{
		int op, i, j, k;
		cin >> op >> i >> j;
		if (op == 1)
		{
			//进行存操作
			cin >> k;
			//判断是否需要扩容
			if (a[i].size() <= j)
			{
				a[i].resize(j + 1);
			}
			a[i][j] = k;
		}
		else
		{
			//进行查操作
			cout << a[i][j] << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int N = 2e6 + 10;

vector<int> a(N);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int id, num;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	while (m--)
	{
		cin >> num;
		cout << a[num] << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;

//创建N个vector 
vector<int> a[N];

int main()
{
	int n, q;
	cin >> n >> q;

	while (q--)
	{
		int op, i, j, k;
		cin >> op >> i >> j;
		if (op == 1)
		{
			//进行存操作
			cin >> k;
			//判断是否需要扩容
			if (a[i].size() <= j)
			{
				a[i].resize(j + 1);
			}
			a[i][j] = k;
		}
		else
		{
			//进行查操作
			cout << a[i][j] << endl;
		}
	}
	return 0;
}


#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 30;
int n;

vector<int> p[N];

PII find(int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p[i].size(); j++)
		{
			if (p[i][j] == x)
			{
				return { i,j };
			}
		}
	}
}

void clean(int x, int y)
{
	//把x y以上的木块归位 
	for (int j = y + 1; j < p[x].size(); j++)
	{
		int t = p[x][y];
		p[t].push_back(t);
		p[x].resize(y + 1);
	}
}

void move(int x1, int y1, int x2)
{
	for (int j = y1; j < p[x1].size(); j++)
	{
		p[x2].push_back(p[x1][j]);
	}
	p[x1].resize(y1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p[i].push_back(i);
	}

	string op1, op2;
	int a, b;
	while (cin >> op1 >> a >> op2 >> b)
	{
		//查找a和b的位置
		PII pa = find(a);
		int x1 = pa.first, y1 = pa.second;
		PII pb = find(b);
		int x2 = pb.first, y2 = pb.second;

		if (op1 == "move")//归位 
		{
			clean(x1, y1);
		}
		if (op2 == "onto")//归位 
		{
			clean(x2, y2);
		}

		move(x1, y1, x2);

		for (int i = 0; i < n; i++)
		{
			cout << i << ":";
			for (int j = 0; j < p[i].size(); j++)
			{
				cout << " " << p[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int N = 2e6 + 10;
vector<int> a(N);
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int num;
	while (m--)
	{
		cin >> num;
		cout << a[num] << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

vector<int> p[N];
int main()
{
	int n, q;
	cin >> n >> q;

	while (q--)
	{
		int op, i, j, k;
		cin >> op >> i >> j;

		if (op == 1)
		{
			//存
			cin >> k;
			//判断是否需要进行扩容
			if (p[i].size() <= j)
				p[i].resize(j + 1);
			p[i][j] = k;
		}
		else
		{
			//查
			cout << p[i][j] << endl;
		}
	}
	return 0;
}
