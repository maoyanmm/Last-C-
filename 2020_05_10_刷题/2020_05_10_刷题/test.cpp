#include<vector>
using namespace std;
#include<iostream>
//À≥ ±’Î¥Ú”°æÿ’Û
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		int i = 0;
		int j = 0;
		int mm = 0;
		int nn = 0;
		vector<int> ans;
		if (n == 0)
		{
			return ans;
		}
		while (mm < m && nn < n)
		{
			while (j < m && mm < m && nn < n)
			{
				ans.push_back(mat[i][j]);
				if (j + 1 < m)
					++j;
				else
					break;
			}
			++i;
			++nn;
			while (i < n && mm < m && nn < n)
			{
				ans.push_back(mat[i][j]);
				if (i + 1 < n)
					++i;
				else
					break;
			}
			--j;
			--m;
			while (j >= mm && mm < m && nn < n)
			{
				ans.push_back(mat[i][j]);
				if (j - 1 >= mm)
					--j;
				else
					break;
			}
			--i;
			--n;
			while (i >= nn && mm < m && nn < n)
			{
				ans.push_back(mat[i][j]);
				if (i - 1 >= nn)
					--i;
				else
					break;
			}
			j++;
			++mm;
		}
		return ans;
	}
};

class MaxGap {
public:
	int FindMax(const vector<int>& A, int begin, int end)
	{
		int max = A[begin];
		for (int i = begin; i < end; ++i)
		{
			if (A[i] > max)
			{
				max = A[i];
			}
		}
		return max;
	}
	int findMaxGap(vector<int> A, int n) {
		if (n == 0 || n == 1)
		{
			return 0;
		}
		int left_max = A[0];
		int right_max = FindMax(A, 0, n);
		int sub_max = abs(right_max - left_max);
		for (int i = 1; i < n-1; ++i)
		{
			if (A[i] > left_max)
			{
				left_max = A[i];
			}
			if (A[i] == right_max)
			{
				right_max = FindMax(A, i+1, n);
			}
			int sub_tmp = abs(right_max - left_max);
			if (sub_tmp > sub_max)
			{
				sub_max = sub_tmp;
			}
		}
		return sub_max;
	}
};
class Solution {
public:
	int directions[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	void DFS(vector<vector<char>>& board, int x, int y)
	{
		board[x][y] = '#';
		for (int i = 0; i < 4; ++i)
		{
			int tmp_x = x + directions[i][0];
			int tmp_y = y + directions[i][1];
			if (tmp_x < 0 || tmp_y < 0 || tmp_x >= board.size() || tmp_y >= board[0].size())
			{
				continue;
			}
			if (board[tmp_x][tmp_y] == 'O')
			{
				DFS(board, tmp_x, tmp_y);
			}
		}
	}
	void solve(vector<vector<char>>& board) {
		if (board.empty())
		{
			return;
		}
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; ++i)
		{
			if (board[i][0] == 'O')
			{
				DFS(board, i, 0);
			}
			if (board[i][col - 1] == 'O')
			{
				DFS(board, i, col - 1);
			}
		}
		for (int j = 0; j < col; ++j)
		{
			if (board[0][j] == 'O')
			{
				DFS(board, 0, j);
			}
			if (board[row - 1][j] == 'O')
			{
				DFS(board, row - 1, j);
			}
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				if (board[i][j] == '#')
				{
					board[i][j] = 'O';
				}
			}
		}
	}
};