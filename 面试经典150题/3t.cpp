//26. 删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        for (int r = 1; r < nums.size(); r++)
        {
            if (nums[r] != nums[r - 1])
            {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};


//80. 删除有序数组中的重复项 II
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 2, r = 2;
        for (r = 2; r < nums.size(); r++)
        {
            if (nums[l - 2] != nums[r])
            {
                nums[l] = nums[r];
                ++l;
            }

        }
        return l;
    }
};