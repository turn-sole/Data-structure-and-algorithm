//260. 只出现一次的数字 III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num : nums)
            diff ^= num;
        diff = (diff == INT_MIN) ? 1 : diff & (-diff);
        vector<int> ans(2);
        for (int num : nums)
        {
            if ((num & diff) == diff)
            {
                ans[0] ^= num;
            }
            else
            {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};

//数组中出现次数超过一半的数字
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[numbers.size() / 2];
    }
};

//17. 电话号码的字母组合
class Solution {
    string strA[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
    void combine(string digits, int level, string combineStr, vector<string>& v)
    {
        if (level == digits.size())
        {
            v.push_back(combineStr);
            return;
        }
        int num = digits[level] - '0';
        string str = strA[num];
        for (size_t i = 0; i < str.size(); ++i)
        {
            combine(digits, level + 1, combineStr + str[i], v);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits.empty())
            return v;

        combine(digits, 0, "", v);
        return v;
    }
};

//137. 只出现一次的数字 II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto& i : nums) ++hash[i];
        for (auto& i : hash) if (i.second == 1) return i.first;
        return -1;
    }
};
