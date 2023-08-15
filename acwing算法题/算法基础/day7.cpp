#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	vector<int>::iterator it = v.begin();

	while (it != v.end())
	{
		if (*it != 0)
			cout << *it;
		else
			v.erase(it);
		it++;
	}

	return 0;
}

//9. 回文数
class Solution {
public:
	bool isPalindrome(int x) {
		string s = to_string(x);
		return s == string(s.rbegin(), s.rend());
	}
};

//14. 最长公共前缀
class Solution {
public:
	static string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return {};
		sort(strs.begin(), strs.end());
		string st = strs.front(), en = strs.back();
		int i;
		int num = (int)min(st.size(), en.size());
		for (i = 0; i < num && st[i] == en[i]; i++);
		string res = string(st, 0, i);
		return res;
	}
};
