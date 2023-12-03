//88. 合并两个有序数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i != n; ++i)
        {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n)
        {
            if (p1 == m)
            {
                cur = nums2[p2++];
            }
            else if (p2 == n)
            {
                cur = nums1[p1++];
            }
            else if (nums1[p1] < nums2[p2])
            {
                cur = nums1[p1++];
            }
            else
            {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i)
        {
            nums1[i] = sorted[i];
        }
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while (p2 >= 0)
        {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[p--] = nums1[p1--];
            }
            else
            {
                nums1[p--] = nums2[p2--];
            }

        }
    }
};