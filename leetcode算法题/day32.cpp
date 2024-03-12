//931. 下降路径最小和
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 2, INT_MAX));
        for (int i = 0; i < n + 2; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
            }
        }
        int ret = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            ret = min(ret, dp[n][i]);
        }
        return ret;
    }
};





//LCR 099. 最小路径和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 2, INT_MAX));
        dp[0][1] = 0, dp[1][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};





//174. 地下城游戏
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1] - dungeon[i][j]);
                dp[i][j] = max(1, dp[i][j]);
            }
        }
        return dp[0][0];
    }
};





//242. 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> dic;
        for (char c : s) {
            dic[c] += 1;
        }
        for (char c : t) {
            dic[c] -= 1;
        }
        for (auto kv : dic) {
            if (kv.second != 0)
                return false;
        }
        return true;
    }
};





//49. 字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int sub = 0;
        string tmp;
        unordered_map<string, int> work;
        for (auto str : strs)
        {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            if (work.count(tmp))
            {
                res[work[tmp]].push_back(str);
            }
            else
            {
                vector<string> vec(1, str);
                res.push_back(vec);
                work[tmp] = sub++;
            }
        }
        return res;
    }
};