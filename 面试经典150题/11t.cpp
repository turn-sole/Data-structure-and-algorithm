//12. 整数转罗马数字
class Solution {
public:
    string intToRoman(int num) {
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string reps[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        string res;
        int
            for (int i = 0; i < 13; i++)  //这里不使用图里的count了，一遍一遍来就行了
                while (num >= values[i])
                {
                    num -= values[i];
                    res += reps[i];
                }
        return res;
    }
};




//58. 最后一个单词的长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;

        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};




//14. 最长公共前缀
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        const auto p = minmax_element(strs.begin(), strs.end());
        for (int i = 0; i < p.first->size(); ++i)
            if (p.first->at(i) != p.second->at(i)) return p.first->substr(0, i);
        return *p.first;
    }
};




//151. 反转字符串中的单词
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));

        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};




//6. N 字形变换
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }
        string res;
        for (const string& row : rows)
            res += row;
        return res;
    }
};
