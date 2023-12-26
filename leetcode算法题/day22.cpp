//283. 移动零
lass Solution{
public:
    void moveZeroes(vector<int>&nums) {
        int n = nums.size(),left = 0,right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                swap(nums[left++],nums[right]);
            }
            right++;
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>s(n);
        int a = 0;
        for (auto e : nums)
        {
            st.push(e);
            if (e)
            {
                s[a++] = st.top();
                st.pop();
            }
        }
        while (!st.empty())
        {
            s[a++] = st.top();
            st.pop();
        }
        nums = s;
    }
};




//11. 盛最多水的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r)
        {
            res = height[l] < height[r] ? max(res, (r - l) * height[l++]) : max(res, (r - l) * height[r--]);
        }
        return res;
    }
};

