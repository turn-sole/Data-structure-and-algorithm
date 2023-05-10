#include<iostream>
using namespace std;
//JZ64 Çó1 + 2 + 3 + ... + n
class Solution {
public:
    int Sum_Solution(int n) {
        n && (n += Sum_Solution(n - 1));
        return n;
    }
};

