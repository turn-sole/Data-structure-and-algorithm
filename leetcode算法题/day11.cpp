//������ 01.01.�ж��ַ��Ƿ�Ψһ
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

//������ 01.02.�ж��Ƿ�Ϊ�ַ�����
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

//������ 01.04.��������
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