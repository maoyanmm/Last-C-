//×Ö·û´®·Ö¸î
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> book(s.size() + 1, false);
		book[0] = true;
		for (int i = 0; i < s.size(); ++i)
		{
			if (book[i] == true)
			{
				for (int j = i; j < s.size(); ++j)
				{
					string sub_str = s.substr(i, j - i + 1);
					if (dict.find(sub_str) != dict.end())
					{
						book[j + 1] = true;
					}
				}
			}
		}
		return book[s.size()];
	}
};