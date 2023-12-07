//169. 多数元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>hash;
        int a = 0, b = 0;
        for (int e : nums)
        {
            hash[e]++;
            if (hash[e] > b)
            {
                a = e;
                b = hash[e];
            }
        }
        return a;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


//189. 轮转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[(i + k) % n] = nums[i];
        }
        nums.assign(a.begin(), a.end());
    }
};


class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

