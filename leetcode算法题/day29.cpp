//35. 搜索插入位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)left = mid + 1;
            else right = mid;
        }
        if (target > nums[right])return nums.size();
        else return left;
    }
};




//9. x 的平方根
class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x, mid = 0;
        while (left < right)
        {
            mid = left + (right - left + 1) / 2;
            if (mid * mid <= x)left = mid;
            else right = mid - 1;
        }
        return left;
    }
};





//852. 山脉数组的峰顶索引
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, mid = 0;
        while (left < right)
        {
            mid = left + (right - left + 1) / 2;
            if (arr[mid] > arr[mid - 1])left = mid;
            else right = mid - 1;
        }
        return left;
    }
};




//162. 寻找峰值
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = -1, right = nums.size() - 1; 
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid;
        }
        return right;
    }
};

