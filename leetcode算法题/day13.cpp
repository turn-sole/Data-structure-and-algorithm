//������ 08.05.�ݹ�˷�
class Solution {
public:
    int multiply(int A, int B) {
        return B ? multiply(A << 1, B >> 1) + (B & 1 ? A : 0) : 0;
    }
};

//������ 16.05.�׳�β��
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0)
        {
            ans += n /= 5;
        }
        return ans;
    }
};