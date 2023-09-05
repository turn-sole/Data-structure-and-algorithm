//JZ31 栈的压入、弹出序列
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
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



//JZ36 二叉搜索树与双向链表
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



