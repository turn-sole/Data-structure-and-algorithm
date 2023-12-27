//12. ����ת��������
class Solution {
public:
    string intToRoman(int num) {
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string reps[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        string res;
        int
            for (int i = 0; i < 13; i++)  //���ﲻʹ��ͼ���count�ˣ�һ��һ����������
                while (num >= values[i])
                {
                    num -= values[i];
                    res += reps[i];
                }
        return res;
    }
};




//58. ���һ�����ʵĳ���
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




//14. �����ǰ׺
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




//151. ��ת�ַ����еĵ���
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




//6. N ���α任
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
