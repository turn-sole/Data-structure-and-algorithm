//121. ������Ʊ�����ʱ��
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for (int e : prices)
        {
            cost = min(cost, e);
            profit = max(profit, e - cost);
        }
        return profit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int minprice = prices[0];
        vector<int> dp(n, 0);

        for (int i = 1; i < n; i++) {
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];

    }
};