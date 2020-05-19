#include<iostream>
#include<vector>
using namespace std;

void remove_elements(vector<int>& vec)
{

}

int main()
{
	vector<int> vec;
	int n = 0;
	while (cin >> n)
	{
		if (n == 10)
		{
			continue;
		}
		vec.push_back(n);
	}
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << vec[vec.size() - 1] << endl;
	return 0;
}


#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int n;
	map<int, int> book;
	vector<int> out;
	while (cin >> n)
	{
		if (book.find(n) == book.end())
		{
			out.push_back(n);
			++book[n];
		}
	}
	for (int i = 0; i < out.size() - 1; ++i)
	{
		cout << out[i] << " ";
	}
	cout << out[out.size() - 1] << endl;
	return 0;
}

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
struct Point
{
	int x;
	int y;
	bool operator<(const Point& p2)
	{
		if (x == p2.x)
		{
			return y < p2.y;
		}
		return x < p2.x;
	}
};

int main()
{
	int x = 0;
	int y = 0;
	vector<Point> vec;
	while (cin >> x >> y)
	{
		Point p;
		p.x = x;
		p.y = y;
		vec.push_back(p);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i].x << " " << vec[i].y << endl;
	}
	return 0;
}

#include<iostream>
using namespace std;

class ScopedPtr
{
private:
	int* _data;
	ScopedPtr& operator=(const ScopedPtr& s) = delete;
	ScopedPtr(const ScopedPtr& s) = delete;
public:
	ScopedPtr(int value)
	{
		_data = new int(value);
	}
	~ScopedPtr()
	{
		if (_data)
		{
			free(_data);
		}
	}
	int& operator*()
	{
		return *_data;
	}
};
void test(int n)
{
	ScopedPtr ptr(n);
	*ptr *= 2;
	cout << *ptr << endl;
}
int main()
{
	int n;
	cin >> n;
	test(n);
	return 0;
}

#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<mutex>
#include<thread>
#include<string>

class RWlock
{
private:
	mutex _mtx;
	int _read_num;
	int _write_num;
public:
	RWlock()
		:_read_num(0), _write_num(0)
	{

	}
	void ReadLock()
	{
		while(_write_num == 0)
		{
			_mtx.lock();
			++_read_num;
			_mtx.unlock();
		}
	}
	void WriteLock()
	{
		while (_write_num == 0 && _read_num == 0)
		{
			_mtx.lock();
			++_write_num;
			_mtx.unlock();
		}
	}
	void ReadUnLock()
	{
		_mtx.lock();
		--_read_num;
		_mtx.unlock();
	}
	void WriteUnLock()
	{
		_mtx.lock();
		--_write_num;
		_mtx.unlock();
	}
};

RWlock my_lock;

void set(map<string, string>& book, const string& key, const string& value)
{
	my_lock.WriteLock();
	book[key] = value;
	my_lock.WriteUnLock();
	return;
}

string get(map<string, string>& book, const string& key)
{
	my_lock.ReadLock();
	string out;
	if (book.find(key) != book.end())
	{
		out = book[key];
	}
	else
	{
		out = "none";
	}
	return out;
	my_lock.ReadUnLock();
}

int main()
{
	int n;
	cin >> n;
	string request;
	string key;
	string val;
	map<string, string> book;
	while (cin >> request)
	{
		if (request == "set")
		{
			cin >> key >> val;
			set(book, key, val);
		}
		else if (request == "get")
		{
			cin >> key;
			string out = get(book, key);
			cout << out << endl;
		}
	}
	return 0;
}






#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<mutex>
#include<thread>
#include<string>

mutex mtx;

void set(map<string, string>& book, const string& key, const string& value)
{
	mtx.lock();
	book[key] = value;
	mtx.unlock();
	return;
}

string get(map<string, string>& book, const string& key)
{
	mtx.lock();
	string out;
	if (book.find(key) != book.end())
	{
		out = book[key];
	}
	else
	{
		out = "none";
	}
	return out;
	mtx.unlock();
}

int main()
{
	int n;
	cin >> n;
	string request;
	string key;
	string val;
	map<string, string> book;
	while (cin >> request)
	{
		if (request == "set")
		{
			cin >> key >> val;
			set(book, key, val);
		}
		else if (request == "get")
		{
			cin >> key;
			string out = get(book, key);
			cout << out << endl;
		}
	}
	return 0;
}