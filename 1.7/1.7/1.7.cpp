#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr1[110][110];
int arr2[110][110];

int main()
{
    int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> arr1[i][j];
		}
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> arr2[i][j];
			arr2[i][j] += arr1[i][j];
		}
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
		
	return 0;
}


#include <iostream>
using namespace std;

int arr[110][110];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

int arr[110][110];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
		}
	}
	//½øÐÐ×ªÖÃ 
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}


#include <iostream>
using namespace std;
const int N = 110;
int arr[N][N];
int main()
{
	int m,n;
	int sum = 0;
	cin >> m >> n;
	
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			cin >> arr[i][j];
			if(i == 0 || i == m-1 || j == 0 || j == n-1)
			{
				sum += arr[i][j];
			}
		}
	}
    cout << sum << endl;
	return 0;
}

#include <iostream>
using namespace std;
const int N = 110;
int arr[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i > 0 && i < n - 1 && j > 0 && j < m - 1)
			{
				arr[i][j] = (arr[i - 1][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i][j - 1]) / 4;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
