//155. 最小栈
class MinStack {
public:
    stack<int> vals;
    stack<int> minvals;
    MinStack() {

    }

    void push(int val) {
        vals.emplace(val);
        if (minvals.empty())
        {
            minvals.emplace(val);
        }
        else
        {
            minvals.emplace(min(minvals.top(), val));
        }
    }

    void pop() {
        vals.pop();
        minvals.pop();
    }

    int top() {
        return vals.top();
    }

    int getMin() {
        return minvals.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


//﻿606.根据二叉树创建字符串
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void preAccess(TreeNode* t, string& str)
    {
        if (t == NULL) return;
        str += to_string(t->val);
        if (t->left || t->right)
        {
            str += "(";
            preAccess(t->left, str);
            str += ")";
        }
        if (t->right)
        {
            str += "(";
            preAccess(t->right, str);
            str += ")";
        }
    }

    string tree2str(TreeNode* t) {
        string res = "";
        preAccess(t, res);
        return res;
    }
};



//102. 二叉树的层序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            vector<int> tmp;
            for (int i = que.size(); i > 0; --i) {
                root = que.front();
                que.pop();
                tmp.push_back(root->val);
                if (root->left != nullptr) que.push(root->left);
                if (root->right != nullptr) que.push(root->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};


