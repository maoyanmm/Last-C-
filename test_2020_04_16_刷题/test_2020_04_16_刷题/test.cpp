// write your code here cpp
//生兔子、收件人列表
#include<iostream>
#include<string>
using namespace std;

bool HaveSymbol(const string& str)
{
	for (const auto& ch : str)
	{
		if (ch == ',' || ch == ' ')
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		string helper;
		getline(cin, helper);
		for (size_t i = 0; i < n - 1; ++i)
		{
			string tmp;
			getline(cin, tmp);
			if (HaveSymbol(tmp) == true)
			{
				cout << '"' << tmp << '"' << ',' << ' ';
			}
			else
			{
				cout << tmp << ',' << ' ';
			}
		}
		string tmp;
		getline(cin, tmp);
		if (HaveSymbol(tmp) == true)
		{
			cout << '"' << tmp << '"' << endl;
		}
		else
		{
			cout << tmp << endl;
		}
	}
	return 0;
}

// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<long long> book(95);
	book[0] = 1;
	book[1] = 2;
	for (int i = 2; i < book.size(); ++i)
	{
		book[i] = book[i - 1] + book[i - 2];
	}
	while (cin >> n)
	{
		cout << book[n - 1] << endl;
	}
	return 0;
}