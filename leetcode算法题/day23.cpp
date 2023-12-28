//611. 有效三角形的个数
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ret = 0, n = nums.size();
        for (int i = n - 1; i >= 2; i--)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    ret += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ret;
    }
};




//15. 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue; 
            if (x + nums[i + 1] + nums[i + 2] > 0) break; 
            if (x + nums[n - 2] + nums[n - 1] < 0) continue; 
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s > 0) --k;
                else if (s < 0) ++j;
                else {
                    ans.push_back({ x, nums[j], nums[k] });
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j); 
                    for (--k; k > j && nums[k] == nums[k + 1]; --k); 
                }
            }
        }
        return ans;
    }
};

