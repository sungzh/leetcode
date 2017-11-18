/*
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
 *
 * Example:
 *
 * Input:
 *
 *    1
 *      \
 *      3
 *     /
 *    2
 *
 * Output:
 * 1
 *
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 * Note: There are at least two nodes in this BST.
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
 * Source: https://leetcode.com/problems/minimum-absolute-difference-in-bst
 * Description: dp, inorder for bst
 * Author: guozheng
 * Data: 20171118 
 */

class Solution {
public:
    int min_diff = INT_MAX, val=-1;
    int getMinimumDifference(TreeNode* root) {
        if(root->left != NULL) getMinimumDifference(root->left);
        if(val >= 0) min_diff = min(root->val - val, min_diff);
        val = root->val;
        if(root->right != NULL) getMinimumDifference(root->right);
        return min_diff;
    }
};
