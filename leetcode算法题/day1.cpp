//136. 只出现一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for (auto e : nums)
        {
            value ^= e;
        }

        return value;
    }
};

//118. 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a(numRows);

        for (int i = 0; i < numRows; i++)
        {
            a[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }
        }

        return a;

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
