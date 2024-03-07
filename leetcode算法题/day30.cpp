//153. 寻找旋转排序数组中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])left = mid + 1;
            else right = mid;
        }
        return nums[right];
    }
};




//面试题 08.01.三步问题
class Solution {
public:
    int waysToStep(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1 || n == 2)return n;
        if (n == 3)return 4;
        int dp[n + 1];
        dp[1] = 1, dp[2] = 2, dp[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};





//746. 使用最小花费爬楼梯
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size() + 1);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};




//724. 寻找数组的中心下标
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0, sumRight = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            sumRight -= nums[i];
            if (sumLeft == sumRight)
                return i;
            sumLeft += nums[i];
        }
        return -1;
    }
};

