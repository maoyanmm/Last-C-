#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<set>

void Disconnect(vector<int>& book)
{
	for (int i = 0; i < book.size(); ++i)
	{
		if (book[i] == 1)
		{
			book[i] = 0;
			return;
		}
	}
}
void Connect(vector<int>& book)
{
	for (int i = 0; i < book.size(); ++i)
	{
		if (book[i] == 0)
		{
			book[i] = 1;
			return;
		}
	}
	book.push_back(1);
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> book;
		while (n--)
		{
			string id;
			string query;
			cin >> id;
			cin >> query;
			if (query == "disconnect")
			{
				Disconnect(book);
			}
			else
			{
				Connect(book);
			}
		}
		int ans = book.size();
		cout << ans << endl;
	}
	return 0;
} 

// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Insert(vector<string>& book, string& new_dir)
{
	for (size_t i = 0; i < book.size(); ++i)
	{
		if (new_dir.find(book[i]) != new_dir.npos)
		{
			book[i] = new_dir;
			return;
		}
		if (book[i].find(new_dir) != book[i].npos)
		{
			return;
		}
	}
	book.push_back(new_dir);
}

void Sort(vector<string>& book)
{
	for (size_t i = 0; i < book.size() - 1; ++i)
	{
		int flag = 0;
		for (size_t j = 0; j < book.size() - i - 1; ++j)
		{
			if (book[j].size() > book[j + 1].size())
			{
				swap(book[j], book[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> book;
		while (n--)
		{
			string dir;
			cin >> dir;
			Insert(book, dir);
		}
		Sort(book);
		for (const auto& e : book)
		{
			cout << "mkdir -p " << e << endl;
		}
		cout << endl;
	}
	return 0;
}