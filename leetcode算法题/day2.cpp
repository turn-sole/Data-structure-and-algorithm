//把字符串转换成整数
class Solution {
public:
    int StrToInt(string str) {
        int a = 0; int b = 1;
        for (char ch : str)
        {
            if (isalpha(ch))
            {
                return 0;
            }
            if (ch == '+' || ch == '-')
            {
                b = (ch == '+') ? 1 : -1;
            }
            if (isdigit(ch))
            {
                a = a * 10 + ch - '0';
            }
        }
        return a * b;
    }
};

//415. 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string v;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int a = 0;
        for (int i = 0; i < num1.size() || i < num2.size(); i++)
        {
            if (i < num1.size())
                a += num1[i] - '0';
            if (i < num2.size())
                a += num2[i] - '0';
            v += (a % 10) + '0';
            a /= 10;
        }
        if (a)
            v += a + '0';
        reverse(v.begin(), v.end());
        return v;
    }
};

//344. 反转字符串
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int left = 0, right = n - 1; left <= right; left++, right--)
        {
            swap(s[left], s[right]);
        }
    }
};

//387. 字符串中的第一个唯一字符
class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s.find(s[i]) == s.rfind(s[i])) {
                return i;
            }
        }
        return -1;
    }
};


