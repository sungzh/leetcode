/*
 * Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
 *
 * Note: The length of path between two nodes is represented by the number of edges between them.
 *
 * Example 1:
 *
 * Input:
 *
 *               5
 *              / \
 *             4   5
 *            / \   \
 *           1   1   5
 * Output:
 *
 * 2
 * Example 2:
 *
 * Input:
 *
 *               1
 *              / \
 *             4   5
 *            / \   \
 *           4   4   5
 * Output:
 *
 * 2
 * Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
 *
 */

/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/

/*
 * Souce: https://leetcode.com/problems/longest-univalue-path/
 * Description: dfs return the max path from root to one children, and _max  to store current max
 * Author: guozheng
 * Data: 20180111
 */

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int _max = 0;
        if(root) dfs(root, _max);
        return _max;
    }
private:
    int dfs(TreeNode* root, int& num) {
        int l = root->left ? dfs(root->left, num) : 0;
        int r = root->right ? dfs(root->right, num) : 0;
        int resl = root->left && root->left->val == root->val ? l+1:0;
        int resr = root->right && root->right->val == root->val ? r+1:0;
        num = max(num, resl+resr);
        return max(resl, resr);
    }
};
