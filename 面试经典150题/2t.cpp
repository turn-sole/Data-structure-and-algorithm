//27. ÒÆ³ıÔªËØ
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int l = 0; l < nums.size(); l++)
        {
            if (nums[l] != val)
            {
                nums[res] = nums[l];
                res++;
            }
        }
        return res;
    }
};