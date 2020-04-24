#include<iostream>
using namespace std;
#include<string>
#include<vector>

int main()
{
	string request;
	while (cin >> request)
	{
		string do_str;
		int index = 0;
		//解析压缩的字符串
		for (int i = 0; i < request.size(); ++i)
		{
			if (request[i] - '0' >= 0 && request[i] - '0' <= 9)
			{
				int times = request[i] - '0';
				string tmp1 = request.substr(index, i - index);
				if (tmp1[1] == '-')
				{
					string tmp2;
					char begin = tmp1[0];
					char end = tmp2[2];
					while (begin < end)
					{
						tmp2 += begin;
						if (begin == 'Z')
						{
							begin = 'a';
						}
						else
						{
							++begin;
						}
					}
					while (times--)
					{
						do_str += tmp1;
					}
				}
				else
				{
					while (times--)
					{
						do_str += tmp1;
					}
				}
			}
		}
		//统计次数
		vector<int> book(128, 0);
		for (int i = 0; i < do_str.size(); ++i)
		{
			++book[do_str[i]];
			if (do_str[i] >= 'a')
			{
				++book[do_str[i] - 32];
			}
		}
		//比较大小
		char min_char = 'z';
		int max_num = 0;
		for (int i = 65; i <= 90; ++i)
		{
			if (book[i] > max_num)
			{
				max_num = book[i];
				min_char = i;
			}
		}
		char ans;
		if (book[min_char + 32] > 0)
		{
			ans = min_char + 32;
		}
		else
		{
			ans = min_char;
		}
		cout << ans << max_num << endl;
	}
	return 0;
}