//42. 接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, left = 0, right = height.size() - 1, pre_max = 0, suf_max = 0;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            ans += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
        }
        return ans;
    }
};



//13. 罗马数字转整数
class Solution {
private:
    unordered_map<char, int> symbol = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(string s) {
        int len = s.length(), ans = 0;
        int temp = 0;
        for (int i = len - 1; i >= 0; i--) {
            int value = symbol[s[i]];
            value >= temp ? ans += value : ans -= value;
            temp = value;
        }
        return ans;
    }
};
