//18. 四数之和
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                int left = j + 1, right = n - 1;
                long long sum = (long long)target - nums[i] - nums[j];
                while (left < right)
                {
                    if (nums[left] + nums[right] > sum)
                        right--;
                    else if (nums[left] + nums[right] < sum)
                        left++;
                    else
                    {
                        ans.push_back({ nums[i],nums[j],nums[left++],nums[right--] });
                        while (left < right && nums[left] == nums[left - 1])left++;
                        while (left < right && nums[right] == nums[right + 1])right--;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1])
                {
                    j++;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        return ans;
    }
};



//16. 最接近的三数之和
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans, n = nums.size();
        int min_diff = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) {
                continue;
            }
            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target) { 
                if (s - target < min_diff) {
                    ans = s; 
                }
                break;
            }
            s = x + nums[n - 2] + nums[n - 1];
            if (s < target) {
                if (target - s < min_diff) {
                    min_diff = target - s;
                    ans = s;
                }
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                s = x + nums[j] + nums[k];
                if (s == target) {
                    return target;
                }
                if (s > target) {
                    if (s - target < min_diff) { 
                        min_diff = s - target;
                        ans = s;
                    }
                    k--;
                }
                else { 
                    if (target - s < min_diff) {
                        min_diff = target - s;
                        ans = s;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};

