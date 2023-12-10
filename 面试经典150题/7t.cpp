//45. ÌøÔ¾ÓÎÏ· II
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int end = 0;
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(nums[i] + i, maxPos);
            if (i == end)
            {
                end = maxPos;
                ans++;
            }
        }
        return ans;
    }
};





//274. H Ö¸Êı
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int c : citations) {
            cnt[min(c, n)]++;
        }
        int s = 0;
        for (int i = n; ; i--) {
            s += cnt[i];
            if (s >= i) {
                return i;
            }
        }
    }
};


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};

