//122. 买卖股票的最佳时机 II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int tmp = prices[i] - prices[i - 1];
            if (tmp > 0) profit += tmp;
        }
        return profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n][2];
        f[0][0] = -prices[0];
        f[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] + prices[i]);
        }
        return f[n - 1][1];
    }
};




//55. 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int flag = n - 1;
        for (int i = n - 2; i >= 0; i--)
            if (nums[i] >= flag - i)
                flag = i;
        return flag == 0 ? true : false;
    }
};
