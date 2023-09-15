//面试题 02.05.链表求和
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* p1 = l1; ListNode* p2 = l2;
            ListNode* head = new ListNode(-1);
            ListNode* p = head;
            bool cnt = false;
            while (p1 || p2 || cnt)
            {
                int sum = 0;
                if (p1)
                {
                    sum += p1->val;
                    p1 = p1->next;
                }
                if (p2) {
                    sum += p2->val;
                    p2 = p2->next;
                }
                if (cnt)
                {
                    sum++;
                    cnt = false;
                }
                ListNode* nxt = new ListNode(sum % 10);
                if (sum / 10 == 1) {
                    cnt = true;
                }
                p->next = nxt;
                p = p->next;
            }
            return head->next;
        }
};


//1614. 括号的最大嵌套深度
class Solution {
public:
    int maxDepth(string s) {
        int res = 0, h = 0;
        for (auto& c : s)
        {
            if (c == '(') res = max(res, ++h);
            else if (c == ')') h--;
        }
        return res;
    }
};


//1544. 整理字符串
class Solution {
public:
    string makeGood(string s) {
        string ret;
        for (char& c : s)
        {
            if (ret.empty())
                ret += c;
            else
            {
                if (ret.back() + 32 == c || ret.back() - 32 == c)
                {
                    ret.pop_back();
                }
                else
                {
                    ret += c;
                }
            }
        }
        return ret;
    }
};


//LCP 44. 开幕式焰火
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int, int> mp;
    void dfs(TreeNode* root)
    {
        if (!root) return;
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
public:
    int numColor(TreeNode* root) {
        dfs(root);
        return mp.size();
    }
};