//383. 赎金信
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>hash;
        for (int i = 0; i < magazine.size(); i++)
        {
            hash[magazine[i]]++;
        }
        for (auto e : ransomNote)
        {
            hash[e]--;
            if (hash[e] < 0)
                return false;
        }
        return true;
    }
};





//205. 同构字符串
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s, s2t;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            if (s2t.find(a) != s2t.end() && s2t[a] != b ||
                t2s.find(b) != t2s.end() && t2s[b] != a)
                return false;
            s2t[a] = b;
            t2s[b] = a;
        }
        return true;
    }
};




//290. 单词规律
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = str.length();
        int i = 0;
        for (auto ch : pattern) {
            if (i >= m) {
                return false;
            }
            int j = i;
            while (j < m && str[j] != ' ') j++;
            const string& tmp = str.substr(i, j - i);
            if (str2ch.count(tmp) && str2ch[tmp] != ch) {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp) {
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};



//242. 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> dic;
        for (char c : s) {
            dic[c] += 1;
        }
        for (char c : t) {
            dic[c] -= 1;
        }
        for (auto kv : dic) {
            if (kv.second != 0)
                return false;
        }
        return true;
    }
};




//49. 字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
