//3. 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>dic;
        int i = -1, res = 0, len = s.size();
        for (int j = 0; j < len; j++)
        {
            if (dic.find(s[j]) != dic.end())
            {
                i = max(i, dic.find(s[j])->second);
            }
            dic[s[j]] = j;
            res = max(res, j - i);
        }
        return res;

    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 };
        int left = 0, right = 0, ret = 0;
        int n = s.size();
        while (right < n)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};





//1004. 最大连续1的个数 III
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, res = 0, n = nums.size();
        for (right = 0; right < n; right++)
        {
            if (nums[right] == 0)
            {
                count++;
            }
            while (count > k)
            {
                if (nums[left++] == 0)
                    count--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};




//30. 串联所有单词的子串
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), m = words.size(), d = words[0].size();
        int len = 0;
        unordered_map<string, int> um;
        for (string w : words) {
            len += w.size();
            um[w]++;
        }
        vector<unordered_map<string, int> > vu(d);
        for (int i = 0; i < d && i + len <= n; i++) {
            for (int j = i; j < i + len; j += d) {
                string w = s.substr(j, d);
                vu[i][w]++;
            }
            if (vu[i] == um) {
                res.emplace_back(i);
            }
        }
        for (int i = d; i + len <= n; i++) {
            int r = i % d;
            string wa = s.substr(i - d, d), wb = s.substr(i + len - d, d);
            if (--vu[r][wa] == 0) vu[r].erase(wa);
            vu[r][wb]++;
            if (vu[r] == um) {
                res.emplace_back(i);
            }
        }

        return res;
    }
};

