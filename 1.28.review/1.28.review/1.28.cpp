#define _CRT_SECURE_NO_WARNINGS
//顺序表例题 
//1.
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e6 + 10;
vector<int> a(N);

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	} 
	while(m--)
	{
		
		int y; cin >> y;
		cout << a[y] << endl;
	}
	return 0;
}

//2.
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 +10;
vector<int> a[N];
//创建N个vector数组 
//为啥使用vector空间就够了
//vector是动态内存分配的,用的时候进行再进行扩容 
int main()
{
	int n,q;
	int op,i,j;
	cin >> n >> q;
	while(q--)
	{
		cin >> op >> i >> j;
		if(op == 1)
		{
			int k; cin >> k;
			//存
			//判断空间够不够
			if(a[i].size() <= j)
			a[i].resize(j+1); 
			if(k == 0)  a[i].clear();
			else
			{
				a[i][j] = k;
			} 
		}
		else
		{
			//查
			cout << a[i][j] << endl; 
		}
	}
	return 0;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // //法一：借助辅助数组
        // vector<int> tmp(m+n);
        // int cur = 0,cur1 = 0,cur2 = 0;
        // while(cur1 < m && cur2 < n)
        // {
        //     if(nums1[cur1] <= nums2[cur2])
        //     {
        //        tmp[cur++] = nums1[cur1++];
        //     }
        //     else
        //     {
        //         tmp[cur++] = nums2[cur2++];
        //     }
        // }
        // //到这肯定有一个数组被遍历完，只需将另一个数组内容进行拷贝即可
        // while(cur1 < m)
        // {
        //     tmp[cur++] = nums1[cur1++];
        // }
        // while(cur2 < n)
        // {
        //     tmp[cur++] = nums2[cur2++];
        // }

        // for(int i = 0;i < m+n;i++)
        // {
        //     nums1[i] = tmp[i];
        // }

        // 法二：在原数组上合并
        int cur = m + n - 1, cur1 = m - 1, cur2 = n - 1;
        while (cur1 >= 0 && cur2 >= 0) {
            if (nums1[cur1] >= nums2[cur2]) {
                nums1[cur--] = nums1[cur1--];
            } else {
                nums1[cur--] = nums2[cur2--];
            }
        }
        while (cur2 >= 0) {
            nums1[cur--] = nums2[cur2--];
        }
    }
};

//链表
//1.
#include <iostream>
using namespace std;

const int N = 2e6 + 10;
int id,ne[N];

int main()
{
	int n; cin >> n;
	while(n--)
	{
		cin >> ne[++id]; 
	}
	int f; cin >> f;
	f = ne[0];
	for(int i = 1;i;i = ne[i])
	{
		cout << i << " ";
	}
	return 0;
}

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int e[N],ne[N],id,h;
int mp[N];//记录下标 

int main()
{
	//初始化链表
	ne[0] = 1;
	e[++id] = 1;
	mp[1] = id;
	 
	int q,op,x;
	cin >> q;
	while(q--)
	{
		cin >> op >> x;
		int p = mp[x];
		if(op == 1)
		{
			int y; cin >> y;
			e[++id] = y;
			mp[y] = id;
			ne[id] = ne[p];
			ne[p] = id; 
		}
		else if(op == 2) 
		{
			if(ne[p])
			  cout << e[ne[p]] << endl;
			else
			  cout << 0 << endl;
		}
		else
		{
			ne[p] = ne[ne[p]];
			mp[ne[p]] = 0;
		}
	}
	return 0;
}


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int pre[N], ne[N];
bool st[N];

int main()
{
	//初始化链表
	ne[1] = 0;
	pre[1] = 0;

	int n; cin >> n;
	int k, p;
	for (int i = 2; i <= n; i++)
	{
		cin >> k >> p;
		if (p == 0)
		{
			//将i插入到k左边
			pre[i] = pre[k];
			ne[i] = k;
			ne[pre[k]] = i;
			pre[k] = i;
		}
		else
		{
			//将i插入到k右边
			pre[i] = k;
			ne[i] = ne[k];
			pre[ne[k]] = i;
			ne[k] = i;
		}
	}
	int m, x; cin >> m;
	while (m--)
	{
		cin >> x;
		if (st[x] == true)  continue;
		{
			//将x删除
			ne[pre[x]] = ne[x];
			pre[ne[x]] = pre[x];
			st[x] = true;
		}
	}
	for (int i = ne[0]; i; i = ne[i])
	{
		cout << i << " ";
	}
	return 0;
}

