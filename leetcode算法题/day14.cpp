//1480. 一维数组的动态和
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i - 1] + nums[i];
        }
        return dp;
    }
};


//35. 搜索插入位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};


