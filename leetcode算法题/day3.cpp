#include <iostream>
#include <string>
using namespace std;

//字符串最后一个单词的长度
//int main() {
//    string s;
//    getline(cin, s);
//    int n = 0;
//    int i = s.length() - 1;
//    while (i >= 0 && s[i] != ' ')
//    {
//        i--;
//        n++;
//    }
//    cout << n;
//    return 0;
//}

//125. 验证回文串
class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[i] += 32;
                }
                a += s[i];
            }
        }
        for (int i = 0, j = a.size() - 1; i < j; i++, j--)
        {
            if (a[i] != a[j])
                return false;
        }
        return true;
    }
};

//541. 反转字符串 II
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k - 1 < s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

//557. 反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s) {
        int n = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                for (int j = n; j <= (i - 1 + n) / 2; j++)
                {
                    swap(s[j], s[i - 1 - j + n]);
                }
                n = i + 1;
            }
        }
        return s;
    }
};



