//面试题 01.01.判定字符是否唯一
class Solution {
public:
    bool isUnique(string astr) {
        char arr[26] = { 0 };
        for (int i = 0; i < astr.size(); i++) {
            int a = astr[i] - 'a';
            if (arr[a] > 0) {
                return false;
            }
            arr[a] ++;
        }
        return true;
    }
};

//面试题 01.02.判定是否互为字符重排
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

//面试题 01.04.回文排列
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> d;
        for (char c : s)
        {
            d[c] += 1;
        }
        int odd = 0;
        for (auto k : d)
        {
            if (k.second % 2 == 1)
            {
                if (++odd > 1)
                    return false;
            }
        }
        return true;
    }
};