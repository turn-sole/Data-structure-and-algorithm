//28. 找出字符串中第一个匹配项的下标
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = needle.size(), len2 = haystack.size();
        int* nextval = new int[len1];
        int j = 0, k = -1;
        nextval[0] = -1;=
        while (j < len1 - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                k++; j++;
                if (needle[k] != needle[j])=
                    nextval[j] = k;
                else nextval[j] = nextval[k];
            }
            else k = nextval[k];=
        }
        j = 0; k = 0;
        while (k < len2 && j < len1) {
            if (j == -1 || needle[j] == haystack[k]) {
                j++; k++;
            }
            else j = nextval[j];
        }
        delete[] nextval;
        if (j == len1)
            return k - len1;
        return -1;
    }
};




//68. 文本左右对齐
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // 待分配空格数 = maxWidth - 单词总长
        // 待分配空格数必须 >= 单词数 - 1
        int n = words.size(), ave, blank, more;
        vector<string> res;
        vector<int> length(n);
        for (int i = 0; i < n; i++) length[i] = words[i].length();
        int left = 0, right = 0, sum;
        while (left < n) {
            sum = length[left];
            while (right < n - 1 && maxWidth - sum >= right - left) sum += length[++right];
            if (maxWidth - sum < right - left) sum -= length[right--];
            blank = maxWidth - sum;
            if (right == left) ave = blank, more = 0;
            else {
                ave = blank / (right - left);
                more = blank % (right - left);
            }
            res.push_back("");
            if (right == n - 1) {
                cout << blank << '\n';
                for (int i = left; i <= right; i++) {
                    res[res.size() - 1] += words[i];
                    if (blank) res[res.size() - 1] += ' ', blank--;
                }
                while (blank--) res[res.size() - 1] += ' ';
            }
            else {
                for (int i = left; i <= right; i++) {
                    res[res.size() - 1] += words[i];
                    if (blank) {
                        blank -= ave;
                        for (int j = 0; j < ave; j++)
                            res[res.size() - 1] += ' ';
                    }
                    if (more) more--, res[res.size() - 1] += ' ', blank--;
                }
            }
            left = right + 1, right = left;
        }
        return res;
    }
};




//392. 判断子序列
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        for (int i = 0, j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                if (++i == s.size())
                    return true;
            }
        }
        return false;
    }
};




//167. 两数之和 II - 输入有序数组
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int s = numbers[i] + numbers[j];
            if (s < target) i++;
            else if (s > target) j--;
            else return { i + 1, j + 1 };
        }
        return {};
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
