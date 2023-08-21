//692. 前K个高频单词
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        for (string& e : words)
            mp[e]++;

        priority_queue<pair<int, string>>n;
        for (auto& [str, cnt] : mp)
        {
            n.push({ -cnt,str });
            if (n.size() > k)
                n.pop();
        }

        vector<string>ans;
        while (!n.empty())
        {
            ans.push_back(n.top().second);
            n.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//107. 二叉树的层序遍历 II
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != NULL)
            q.push(root);
        vector<vector<int>> result;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            result.push_back(v);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};