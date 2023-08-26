//645. 错误的集合
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto& num : nums)
        {
            mp[num]++;
        }
        vector<int>errornums(2);
        for (int i = 1; i <= n; i++) {
            int count = mp[i];
            if (count == 2)
            {
                errornums[0] = i;
            }
            else if (count == 0)
            {
                errornums[1] = i;
            }
        }
        return errornums;
    }
};

//面试题 05.06.整数转换
int lowbit(unsigned int val)
{
    int res = 0;
    while (val)
    {
        val &= (val - 1);
        ++res;
    }
    return res;
}
class Solution {
public:
    int convertInteger(int A, int B) {
        A ^= B;
        return lowbit(A);
    }
};

//747. 至少是其他数字两倍的最大数
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = 0, ans = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= mx * 2)
                ans = i;
            else if (nums[i] * 2 > mx)
                ans = -1;
            mx = max(nums[i], mx);
        }
        return ans;
    }
};

//349. 两个数组的交集
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};