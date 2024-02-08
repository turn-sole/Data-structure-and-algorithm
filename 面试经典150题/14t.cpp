//1. 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0;; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return { i, j };
    }
};





//219. 存在重复元素 II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dictionary;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            if (dictionary.count(num) && i - dictionary[num] <= k) {
                return true;
            }
            dictionary[num] = i;
        }
        return false;
    }
};





//128. 最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int>nums_set;
        for (auto e : nums)
        {
            nums_set.insert(e);
        }
        int res = 0;
        for (auto x : nums_set)
        {
            if (!nums_set.count(x - 1))
            {
                int y = x;
                while (nums_set.count(y + 1))y++;
                res = max(res, y - x + 1);
            }
        }
        return res;
    }
};
