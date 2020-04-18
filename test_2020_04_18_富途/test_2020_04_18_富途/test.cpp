#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<map>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int solve(int n, vector<int> &S, vector<int> &T) {
	if (n == 0)
	{
		return 0;
	}
	multimap<int, int> mmp1;
	int count = 1;
	for (int i = 0; i < n; ++i)
	{
		mmp1.insert(S[i], T[i]);
	}
	auto it1 = mmp1.begin();
	for (; it1 != mmp1.end(); ++it1)
	{
		auto it2 = mmp1.begin();
		for (; it2 != it1; ++it2)
		{
			if (it2->second > it1->first)
			{
				++count;
			}
		}
	}
	return count;
}
/******************************结束写代码******************************/


int main() {
	int n;
	cin >> n;
	vector<int> S, T;
	for (int i = 0; i < n; ++i) {
		int s, t;
		cin >> s >> t;
		S.push_back(s);
		T.push_back(t);
	}
	cout << solve(n, S, T) << endl;
	return 0;

}




int main()
{
	
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> gupiao(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> gupiao[i];
		}
		int q_size;
		cin >> q_size;
		vector<int> q(q_size);
		for (int i = 0; i < q_size; ++i)
		{
			cin >> q[i];
		}
		sort(gupiao.begin(), gupiao.end());
		for (int i = 0; i < q_size; ++i)
		{
			int sub_money = 0;
			int days = 0;
			int j = q[i] - 1;
			while (j >= 0)
			{
				++days;
				int tmp_m = m;
				int tmp_money = 0;
				while (j >= 0 && tmp_m--)
				{
					tmp_money += gupiao[j--];
				}
				sub_money += tmp_money*days;
			}
			cout << sub_money << endl;
		}
	}
	return 0;
}