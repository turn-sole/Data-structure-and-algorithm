//1658. 将 x 减到 0 的最小操作数
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target < 0)return -1;
        int ret = -1;
        for (int left = 0, right = 0, tmp = 0; right < nums.size(); right++)
        {
            tmp += nums[right];
            while (tmp > target)
                tmp -= nums[left++];
            if (tmp == target)
                ret = max(ret, right - left + 1);
        }
        if (ret == -1) return -1;
        else return nums.size() - ret;
    }
};




//904. 水果成篮
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, n = fruits.size();
        unordered_map<int, int>hash;
        int ret = 0;
        for (; right < n; right++)
        {
            hash[fruits[right]]++;
            while (hash.size() > 2)
            {
                hash[fruits[left]]--;
                if (hash[fruits[left]] == 0)
                    hash.erase(fruits[left]);
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};




//860. 柠檬水找零
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto x : bills)
        {
            if (x == 5) five++;
            else if (x == 10)
            {
                if (five == 0) return false;
                five--; ten++;
            }
            else
            {
                if (ten && five)
                {
                    ten--; five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};




//1137. 第 N 个泰波那契数
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};



//面试题 08.06.汉诺塔问题
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }
    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if (n == 1)
        {
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        move(n - 1, A, C, B);
        C.push_back(A.back());
        A.pop_back();
        move(n - 1, B, A, C);
    }
};