//380. O(1) ʱ����롢ɾ���ͻ�ȡ���Ԫ��
class RandomizedSet {
private:
    unordered_map<int, int> hash;    //��ϣ����Ԫ��ֵ�Ͷ�Ӧ�±꣬Ϊ��removeʱʵ��O��1��
    vector<int> dyArray;        //vector������Ϊ��̬���飬ʵ��getRandom��insert�ĳ���ʱ�����

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = hash.find(val);
        if (it != hash.end()) return false;  //����������Ѿ�����val������false����ʡʱ��
        dyArray.push_back(val);
        hash[val] = dyArray.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = hash.find(val);
        if (it == hash.end()) return false;  //ɾ��ʱ����������в�����val������false

        int lastPos = dyArray.size() - 1;   //����ɾ��ֵ���������һλ���н���
        int valPos = hash[val];
        dyArray[valPos] = dyArray[lastPos];
        dyArray.pop_back();                 //vector����ɾ��val
        hash[dyArray[valPos]] = valPos;     //��������ֵ�±귢���仯����Ҫ����
        hash.erase(val);                    //��ϣ����ɾ��val����
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int size = dyArray.size();
        int pos = rand() % size;  //���±���������
        return dyArray[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */



//238. ��������������ĳ˻�
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};
        vector<int> ans(len, 1);
        ans[0] = 1;
        int tmp = 1;
        for (int i = 1; i < len; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = len - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            ans[i] *= tmp;
        }
        return ans;
    }
};

