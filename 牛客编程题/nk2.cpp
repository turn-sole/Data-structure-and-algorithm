//JZ31 ջ��ѹ�롢��������
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        int n = pushV.size();
        stack<int> s;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && (s.empty() || s.top() != popV[i])) {
                s.push(pushV[j]);
                j++;
            }
            if (s.top() == popV[i])
                s.pop();
            else
                return false;
        }
        return true;
    }
};



//JZ36 ������������˫������
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    TreeNode* head = NULL;
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL)
            return NULL;
        Convert(pRootOfTree->left);
        if (pre == NULL)
        {
            head = pRootOfTree;
            pre = pRootOfTree;
        }
        else
        {
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }
        Convert(pRootOfTree->right);
        return head;
    }
};



