//KY264 单词识别
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> tmp;
    string s;
    while (cin >> s)
    {
        bool flag = false;
        for (char& i : s)
        {
            if (i == '.' || i == ',')
            {
                flag = true;
            }
            else if (i <= 'Z' && i >= 'A')
            {
                i = i - 'A' + 'a';
            }
        }
        if (flag)
        {
            s = s.substr(0, s.size() - 1);
        }
        ++tmp[s];
    }
    for (auto i : tmp)
    {
        cout << i.first << ':' << i.second << endl;
    }
    return 0;
}

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
    TreeNode* pre, * res;
public:
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        pre == nullptr ? res = root : pre->right = root;

        root->left = pre, pre = root;
        dfs(root->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return pRootOfTree;
        dfs(pRootOfTree);
        return res;
    }
};
