#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

void MySet(unordered_map<int, int>& un_map, int capacity, vector<int>& priority, int key, int value)
{
	//�����������
	if (un_map.size() == capacity)
	{
		//�õ����δ���ʵ�key
		int erase_num = priority[0];
		//�ӷ������ȼ���������ɾ�����δ���ʵ�key
		priority.erase(priority.begin());
		//�ٰ�map���Ӧ��keyɾ��
		auto it = un_map.find(erase_num);
		un_map.erase(it);
	}
	//��������
	if (un_map.find(key) != un_map.end())
	{
		return;
	}
	un_map[key] = value; 
	//�������ȶ���
	priority.push_back(key);
}

int MyGet(unordered_map<int, int>& un_map, vector<int>& priority, int key)
{
	//���������key
	if (un_map.find(key) == un_map.end())
	{
		return -1;
	}
	//�����������Ҫ�������ȶ���
	auto it = priority.begin();
	for (; it != priority.end(); ++it)
	{
		if (*it == key)
		{
			priority.erase(it);
			priority.push_back(key);
			break;
		}
	}
	return un_map[key];
}

int main()
{
	int N, K;
	while (cin >> N >> K)
	{
		unordered_map<int, int> un_map;
		vector<int> priority;
		int opt;
		int x, y;
		while (N--)
		{
			cin >> opt >> x;
			if (opt == 1)
			{
				cin >> y;
				MySet(un_map, K, priority, x, y);
			}
			else
			{
				int ret = MyGet(un_map, priority, x);
				cout << ret << endl;
			}
		}
	}
	return 0;
}

#include<vector>
#include<iostream>
#include<map>
using namespace std;

void ShiftDown(vector<int>& nums, int root, int capacity)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < capacity)
	{
		if (child + 1 < capacity && nums[child + 1] > nums[child])
		{
			++child;
		}
		if (nums[child] > nums[parent])
		{
			swap(nums[child], nums[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int n, k;
	while (cin >> n)
	{
		vector<int> nums(n);
		map<int,int> mmp;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			++mmp[tmp];
		}
		n = mmp.size();
		int index = 0;
		for (const auto& e : mmp)
		{
			nums[index++] = e.first;
		}

		cin >> k;
		vector<int> heap(nums.begin(), nums.begin() + k);

		//�����
		int last_parent = (k - 2) / 2;
		for (int i = last_parent; i >= 0; --i)
		{
			ShiftDown(heap, i, k);
		}

		//��k�±꿪ʼ������ÿ��һ�Σ��������������Ҫ����
		for (int i = k; i < n; ++i)
		{
			//�Ѷ�������
			if (nums[i] < heap[0])
			{
				heap[0] = nums[i];
				ShiftDown(heap, 0, k);
			}
		}
		cout << heap[0] << endl;
	}
	return 0;
}