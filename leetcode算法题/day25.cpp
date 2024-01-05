//209. 长度最小的子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n + 1, s = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            s += nums[right];
            while (s >= target) {
                ans = min(ans, right - left + 1);
                s -= nums[left++];
            }
        }
        return ans <= n ? ans : 0;
    }
};




//3. 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = s.size();
        for (int j = 0; j < len; j++) {
            if (dic.find(s[j]) != dic.end())
                i = max(i, dic.find(s[j])->second); 
            dic[s[j]] = j; 
            res = max(res, j - i);
        }
        return res;
    }
};

