#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int GetLong(int x1,int y1,int x2,int y2)
{
	int length_x = abs(x1-x2);
	length_x *= length_x;
	int length_y = abs(y1-y2);
	length_y *= length_y;
	int length = sqrt(length_x + length_y);
	return length;
}

int GetMin(vector<int>& x_a, vector<int>& y_a, vector<int>& x_b, vector<int>& y_b)
{
	int min = INT_MAX;
	int tmp_min = 0;
	int size = x_a.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			tmp_min = GetLong(x_a[i],y_a[i],x_b[j],y_b[j]);
			if (tmp_min < min)
			{
				min = tmp_min;
			}
		}
	}
	return min;
}

int main()
{
	int t;
	while (cin >> t)
	{
		while (t--)
		{
			int n;
			cin >> n;
			vector<int> x_a(n);
			vector<int> y_a(n);
			vector<int> x_b(n);
			vector<int> y_b(n);
			for (int i = 0; i < n; ++i)
			{
				cin >> x_a[i] >> y_a[i];
			}
			for (int i = 0; i < n; ++i)
			{
				cin >> x_b[i] >> y_b[i];
			}
			int ans = GetMin(x_a,y_a,x_b,y_b);
			cout << ans << endl;
		}
	}
	return 0;
}



#include<iostream>
#include<math.h>
using namespace std;

int GetLevel(int x)
{
	int level = sqrt((double)x) + 1;
	return level;
}

int GetGrandParent(int x, int k, int now_level)
{
	int sub = now_level - k;
	while (sub--)
	{
		x /= 2;
	}
	return x;
}

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int x, k;
		cin >> x >> k;
		int now_level = GetLevel(x);
		if (k >= now_level)
		{
			cout << -1 << endl;
		}
		else
		{
			int grand_parent = GetGrandParent(x, k, now_level);
			cout << grand_parent << endl;
		}
	}
	return 0;
}





#include<stack>
#include<iostream>
#include<string>
using namespace std;
class MyQueue
{
private:
	stack<int> st1;
	stack<int> st2;
public:
	void add(int num)
	{
		st1.push(num);
	}
	void poll()
	{
		int size = st1.size() - 1;
		if (size < 0)
		{
			return;
		}
		while (size--)
		{
			int tmp = st1.top();
			st1.pop();
			st2.push(tmp);
		}
		st1.pop();
		size = st2.size();
		while (size--)
		{
			int tmp = st2.top();
			st2.pop();
			st1.push(tmp);
		}
	}
	void peek()
	{
		int size = st1.size() - 1;
		while (size--)
		{
			int tmp = st1.top();
			st1.pop();
			st2.push(tmp);
		}
		cout << st1.top() << endl;
		size = st2.size();
		while (size--)
		{
			int tmp = st2.top();
			st2.pop();
			st1.push(tmp);
		}
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		MyQueue my_queue;
		string tmp;
		getline(cin, tmp);
		while (n--)
		{
			string action;
			getline(cin, action);
			if (action.substr(0, 3) == "add")
			{
				string str_num = action.substr(4, action.size() - 4);
				int num = stoi(str_num);
				my_queue.add(num);
			}
			else
			{
				if (action == "peek")
				{
					my_queue.peek();
				}
				else if (action == "poll")
				{
					my_queue.poll();
				}
			}
		}
	}
	return 0;
}




#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		queue<int> my_queue;
		int q;
		cin >> q;
		string tmp;
		getline(cin, tmp);
		while (q--)
		{
			string action;
			getline(cin, action);
			if (action.substr(0, 4) == "PUSH")
			{
				string str_num = action.substr(5, action.size() - 5);
				int num = stoi(str_num);
				my_queue.push(num);
			}
			else
			{
				if (action == "TOP")
				{
					if (my_queue.empty())
					{
						cout << -1 << endl;
					}
					else
					{
						cout << my_queue.front() << endl;
					}
				}
				else if (action == "POP")
				{
					if (my_queue.empty())
					{
						cout << -1 << endl;
					}
					else
					{
						my_queue.pop();
					}
				}
				else if (action == "SIZE")
				{
					cout << my_queue.size() << endl;
				}
				else if (action == "CLEAR")
				{
					int size = my_queue.size();
					while (size--)
					{
						my_queue.pop();
					}
				}
			}
		}
	}
	return 0;
}