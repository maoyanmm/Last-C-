// write your code here cpp
//客似云来、剪花条布
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int s_cur = 0, s_behind = 0;
		int t_cur = 0;
		int count = 0;
		while (s_cur < s.size())
		{
			if (s[s_cur] == t[t_cur])
			{
				++s_cur;
				++t_cur;
				if (t_cur == t.size())
				{
					++count;
					t_cur = 0;
					s_behind = s_cur;
				}
			}
			else
			{
				s_cur = ++s_behind;
				t_cur = 0;
			}
		}
		cout << count << endl;
	}
	return 0;
}

// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;
int a = 1;
int b = 1;
int c = 2;
int GetFepo(int n, int helper)
{
	if (helper == 0)
	{
		if (n <= 2)
		{
			return 1;
		}
		if (n == 3)
		{
			return 2;
		}
		n -= 3;
	}
	while (n--)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		int count = 0;
		count += GetFepo(from, 0);
		for (int i = from + 1; i <= to; ++i)
		{
			int rep = GetFepo(1, 1);
			count += rep;
		}
		cout << count << endl;
	}
	return 0;
}