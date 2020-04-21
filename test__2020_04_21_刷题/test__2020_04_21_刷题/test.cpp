// write your code here cpp
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
struct Node
{
	int _x;
	int _y;
	Node(int x, int y)
	{
		_x = x;
		_y = y;
	}
};

int direction[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
void dfs(int i, int j, vector<vector<string> >& book, int& count)
{
	book[i][j] = "x";
	++count;
	for (int index = 0; index < 4; ++index)
	{
		int tmp_i = i + direction[index][0];
		int tmp_j = j + direction[index][1];
		if (tmp_i >= 0 && tmp_j >= 0 && tmp_i < book.size() && tmp_j < book[0].size()
			&& book[tmp_i][tmp_j] == ".")
		{
			dfs(tmp_i, tmp_j, book, count);
		}
	}
}

void dfs_nor(int start_i, int start_j, vector<vector<string> >& book, int& count)
{
	stack<Node> st;
	st.push(Node(start_i, start_j));
	while (!st.empty())
	{
		Node node = st.top();
		st.pop();
		++count;
		int x = node._x;
		int y = node._y;
		book[x][y] = "x";
		for (int index = 0; index < 4; ++index)
		{
			int tmp_x = x + direction[index][0];
			int tmp_y = y + direction[index][1];
			if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < book.size() && tmp_y < book[0].size()
				&& book[tmp_x][tmp_y] == ".")
			{
				st.push(Node(tmp_x, tmp_y));
			}
		}
	}
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int row, col;
		vector<vector<string>> book(m, vector<string>(n));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> book[i][j];
				if (book[i][j] == "@")
				{
					row = i;
					col = j;
				}
			}
		}
		int count = 0;
		dfs_nor(row, col, book, count);
		cout << count - 1 << endl;
	}
	return 0;
}

#include<iostream>
#include<stdio.h>
using namespace std;
#include<vector>
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0));
		vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
		dp[1][1] = 1.0;
		while (k--)
		{
			int x, y;
			cin >> x >> y;
			maze[x][y] = 1;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (i == 1 && j == 1)
				{
					continue;
				}
				if (maze[i][j] == 1)
				{
					dp[i][j] = 0;
				}
				else if (i == 1)
				{
					dp[i][j] = dp[i][j - 1];
				}
				else if (j == 1)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else if (i == n)
				{
					dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1];
				}
				else if (j == m)
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1] * 0.5;
				}
			}
		}
		printf("%.2lf\n", dp[n][m]);
	}
	return 0;
}