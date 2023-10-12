//283. “∆∂Ø¡„
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left, right;
        int n = nums.size();
        while (right < n)
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }

    }
};


//1089. ∏¥–¥¡„
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1;
        int n = arr.size();
        while (cur < n)
        {
            if (arr[cur])
            {
                dest++;
            }
            else
            {
                dest += 2;
            }
            if (dest >= n - 1)
                break;
            cur++;
        }
        if (dest == n)
        {
            arr[n - 1] = 0;
            cur--;
            dest -= 2;
        }
        while (cur >= 0)
        {
            if (arr[cur])
                arr[dest--] = arr[cur--];
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};