//238. 除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>front(n + 1);
        vector<int>after(n + 1);
        front[0] = nums[0];
        after[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            front[i] = nums[i] * front[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            after[i] = nums[i] * after[i + 1];
        }
        nums[0] = after[1];
        nums[n - 1] = front[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            nums[i] = front[i - 1] * after[i + 1];
        }
        return nums;
    }
};




//560. 和为 K 的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>hash;
        hash[0] = 1;
        int sum = 0, ret = 0;
        for (auto e : nums)
        {
            sum += e;
            if (hash.count(sum - k)) ret += hash[sum - k];
            hash[sum]++;
        }
        return ret;
    }
};




//91. 解码方法
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            int t = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (t >= 10 && t <= 26)dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};




//LCR 098. 不同路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};





//63. 不同路径 II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1]) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};