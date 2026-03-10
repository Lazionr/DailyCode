#define _crt_secure_no_warnings
#include <iostream>
#include <string>
using namespace std;

string a,b;

void dfs(int l1,int r1,int l2,int r2)
{
	//函数出口
	if(l1 > r1) return; 
	//1.确定根节点
	cout << b[r2];
	
	int p = l1;//标记中序遍历中根节点的位置
	while(a[p] != b[r2]) p++; 
	//2.划分左右子树
	dfs(l1,p-1,l2,p+l2-l1-1);
	//递归处理左子树 
	dfs(p+1,r1,p+l2-l1,r2-1);
	//递归处理右子树 
}
int main()
{
	cin >> a >> b;
	dfs(0,a.size() - 1,0,b.size() - 1);
	return 0;
}




#include <iostream>
#include <string>
using namespace std;

string a,b;

void dfs(int l1,int r1,int l2,int r2)
{
	//函数出口
	if(l1 > r1) return; 
	//在前序遍历中找到根结点 
	
	//在中序遍历中找到根节点
	int p = l1;
	while(a[p] != b[l2]) p++;
	 
	 //2.划分左右子树,分别进行dfs
	dfs(l1,p-1,l2+1,p+l2-l1);
	dfs(p+1,r1,p+l2-l1+1,r2);
	cout << b[l2]; 
}
int main()
{
	cin >> a >> b;
	dfs(0,a.size()-1,0,b.size()-1);
	return 0;
}

