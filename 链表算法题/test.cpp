#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTDataType* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
226. 翻转二叉树
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
		TreeNode* invertTree(TreeNode* root) {
			if (root == nullptr)
			{
				return root;
			}
			TreeNode* left = invertTree(root->left);
			TreeNode* right = invertTree(root->right);
			root->left = right;
			root->right = left;
			return root;
		}
};
100. 相同的树
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
		{
			return true;
		}
		if (p && q && p->val == q->val)
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else
			return false;
	}
};