//134. ����վ
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            cursum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (cursum < 0) {
                start = i + 1;
                cursum = 0;
            }
        }
        if (sum < 0) return -1;
        return start;
    }
};




//135. �ַ��ǹ�
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        // ��ǰ���
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        // �Ӻ���ǰ
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        // ͳ�ƽ��
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};

