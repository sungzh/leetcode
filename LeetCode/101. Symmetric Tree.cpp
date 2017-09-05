/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *      1
 *     / \
 *    2   2
 *     \   \
 *      3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/

/*
 * Source: https://leetcode.com/problems/symmetric-tree/
 * Description: left.left right.right and left.right right.left  together in bfs(use stack) or dfs
 * Author: guozheng
 * Data: 20170905
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(left==NULL || right == NULL)
            return left == right;
        if(left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};
