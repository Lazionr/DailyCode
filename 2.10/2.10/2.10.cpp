#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//const int N = 1e4 + 10;
//priority_queue<int> heap;
//int n,m;
//
//int main()
//{
//	cin >> n >> m;
//	while(n--)
//	{
//		int a,b,c;
//		cin >> a >> b >> c;
//		for(int x = 1;x <= m;x++)
//		{
//			int ret = a * x * x + b * x + c;
//			if(heap.size() < m)
//			{
//				heap.push(ret);
//				continue;
//			}
//			if(ret >= heap.top()) continue;
//			heap.push(ret);
//			heap.pop();
//		}
//	}
//	vector<int> arr(m);
//	for(int i = 0;i < m;i++)
//	{
//		arr[i] = heap.top();
//		heap.pop();
//	}
//	for(auto e = arr.end() - 1;e > arr.begin();e--)
//	{
//		cout << *e << " ";
//	}
//	return 0;
//}

#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4 + 10;

int a[N], b[N], c[N];
int x, n, m;
struct node
{
	int f;
	int num;
	int x;

	bool operator <(const node& s) const
	{
		//小根堆 
		return f > s.f;
	}
};


priority_queue<node> heap;

int calc(int i, int x)
{
	return a[i] * x * x + b[i] * x + c[i];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	//1、把x=1的值放入堆中 
	for (int i = 1; i <= n; i++)
	{
		heap.push({ calc(i,1),i,1 });
	}
	//2、依次拿出m个值
	while (m--)
	{
		auto t = heap.top(); heap.pop();
		int f = t.f;
		int num = t.num;
		int x = t.x;

		cout << f << " ";
		heap.push({ calc(num,x + 1),num,x + 1 });
	}
	return 0;
}



