438. 找到字符串中所有字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = { 0 };
        vector<int>res;
        for (auto& e : p)
            hash1[e - 'a']++;
        int hash2[26] = { 0 };
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (++hash2[in - 'a'] <= hash1[in - 'a'])count++;
            if (right - left + 1 > p.size())
            {
                char out = s[left++];
                if (hash2[out - 'a']-- <= hash1[out - 'a'])count--;
            }
            if (count == p.size())res.push_back(left);
        }
        return res;
    }
};




30. 串联所有单词的子串
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ret;
        unordered_map<string, int>hash1;
        for (auto& e : words)
            hash1[e]++;
        int len = words[0].size(), m = words.size();
        for (int i = 0; i < len; i++)
        {
            unordered_map<string, int>hash2;
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                string in = s.substr(right, len);
                if (++hash2[in] <= hash1[in])count++;
                if (right - left + 1 > len * m)
                {
                    string out = s.substr(left, len);
                    if (hash2[out]-- <= hash1[out])count--;
                    left += len;
                }
                if (count == m)
                    ret.push_back(left);
            }
        }
        return ret;
    }
};




//76. 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = { 0 };
        int kinds = 0;
        for (auto& e : t)
        {
            if (hash1[e]++ == 0)kinds++;
        }
        int m = s.size(), n = t.size();
        int hash2[128] = { 0 };
        int minlen = INT_MAX, begin = -1;
        for (int left = 0, right = 0, count = 0; right < m; right++)
        {
            char in = s[right];
            if (++hash2[in] == hash1[in])count++;
            while (count == kinds)
            {
                if (right - left + 1 < minlen)
                {
                    minlen = right - left + 1;
                    begin = left;
                }
                char out = s[left++];
                if (hash2[out]-- == hash1[out])count--;
            }
        }
        if (begin == -1)return "";
        return s.substr(begin, minlen);
    }
};




704. 二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (nums[m] < target) i = m + 1;
            else if (nums[m] > target) j = m - 1;
            else return m;
        }
        return -1;
    }
};





34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return { -1, -1 };
        }
        int end = lower_bound(nums, target + 1) - 1;
        return { start, end };
    }
};