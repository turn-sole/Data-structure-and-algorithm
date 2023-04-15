class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        else
        {
            int t = 0, y = x;
            long long r = 0;
            while (x)
            {
                r = r * 10 + (x % 10);
                x /= 10;
            }
            if (r == y) return true;
            else return false;
        }
    }
};